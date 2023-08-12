#include "widget.h"
#include "ui_widget.h"
#define MAXNUM 100


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Init()
{

    recvTotal=0;//当前传输的文件数据
    allTotal=0;//文件总的大小
    myServer = new QTcpServer(this);
    myFile = new QFile(this);
}

//slots
void Widget::on_btn_bind_clicked()
{
    QString myAddr;
    //手动设置IP
    myAddr=ui->lineEdit_Server->text();
    QString myPort=ui->lineEdit_Server_Port->text();
    bool ret = myServer->listen(QHostAddress(myAddr),myPort.toUInt());
    QString msg;
    if(!ret)
    {
        msg="绑定失败！";
    }
    else
    {
        msg="绑定成功！";
        ui->btn_bind->setEnabled(false);
    }
    ui->textEdit_Server->append(msg);

    myServer->setMaxPendingConnections(MAXNUM);

    connect(myServer,SIGNAL(newConnection()),
            this,SLOT(doProcessNewConnection()));
}

void Widget::doProcessNewConnection()
{
    client = myServer->nextPendingConnection();//获取到客户端的描述符
//    arryClients.append(client);
    QString msg=QString("客户端[%1:%2]连入！")
            .arg(client->peerAddress().toString())
            .arg(client->peerPort());//对方的IP地址和d端口号
    ui->textEdit_Server->append(msg);


    //使用槽读取内容
    connect(client,SIGNAL(readyRead()),this,
            SLOT(doProcessReadyRead()));
}

void Widget::doProcessReadyRead()
{
    QByteArray ba = client->readAll();
    //第一次接收数据
    if(this->recvTotal==0)
    {
        this->allTotal =0;
        //获取客户端发送过来的文件名及需要上传文件的大小
        //filename#totalsize
        QStringList list = QString(ba).split("#");
        QString filename = list.at(0);
        this->allTotal = QString(list.at(1)).toLongLong();

        this->allTotal += ba.length();
        this->recvTotal += ba.length();

        //打开文件
        myFile->setFileName(filename);
        int ret = myFile->open(QIODevice::WriteOnly|QIODevice::Truncate);
        if(!ret)
        {
            this->recvTotal = 0;
            QMessageBox::warning(this,"warning","file can't open!");
            return;
        }
        QString msg=QString("正在接收文件%1：").arg(filename);
        ui->textEdit_Server->append(msg);
        ui->progressBar->setRange(0,allTotal);
    }
    else
    {
        qint64 len = myFile->write(ba);
        this->recvTotal+=len;
    }
    //更新进度条
    ui->progressBar->setValue(this->recvTotal);
    //判断是否接收完成
    if(this->recvTotal == this->allTotal)
    {
        myFile->close();
        this->recvTotal=0;
        this->allTotal=0;
        QString msg="接收文件成功！";
        ui->textEdit_Server->append(msg);
    }
}

// end slots
