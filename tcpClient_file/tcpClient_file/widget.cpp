#include "widget.h"
#include "ui_widget.h"
#define MSG_LEN 1024*2

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
    totalSize=0;
    sendSize=0;
    myClient=new QTcpSocket(this);
    myFile=new QFile(this);
}


//slots
void Widget::on_btn_connect_clicked()
{
    QString servAddres=ui->lineEdit_Server->text();
    QString servPort = ui->lineEdit_Server_Port->text();
    //连接服务器
    myClient->connectToHost(servAddres,servPort.toUInt());
    connect(myClient,SIGNAL(connected()),
            this,SLOT(doProcessConnected()));
}

void Widget::doProcessConnected()
{
    QString msg = "服务器连接成功！";
    ui->textEdit_Server->append(msg);
    ui->btn_connect->setEnabled(false);
}

void Widget::on_btn_fileUpload_clicked()
{
    //打开文件
    QString filename = QFileDialog::getOpenFileName(this,"上传文件：",
                    "C:/Users/gys/Pictures","video(*.mp4)");
//    qDebug()<<filename;
    if(filename.isEmpty())
    {
        return;
    }

    QString msg = QString("准备发送[%1]文件").arg(filename);
    ui->textEdit_Server->append(msg);

    myFile->setFileName(filename);
    bool ret = myFile->open(QIODevice::ReadOnly|QIODevice::Unbuffered);
    if(!ret)
    {
        return;
    }
    //设置进度条清空全局值
    ui->progressBar->setValue(0);
    this->totalSize=0;
    this->sendSize=0;

    //获取文件大小（设置进度条的滚动）
    this->totalSize = myFile->size();
    ui->progressBar->setRange(0,totalSize);
    msg=QString("文件总大小为：%1").arg(totalSize);
    ui->textEdit_Server->append(msg);
    //发送头给服务器 filename#totalsize
    QFileInfo info(filename);
    msg = QString("%1#%2#").arg(info.fileName()).arg(this->totalSize);
    myClient->write(msg.toUtf8());
    myClient->waitForBytesWritten();//等待对方收完当前发送的数据再进行下一次的写，确保每一次都能够完全写成功（服务器完全收到了）

    //准备边读文件边发数据
    quint64 len;
    while(!myFile->atEnd())
    {
        QByteArray ba = myFile->read(MSG_LEN);//读取文件2K
        len = myClient->write(ba);//将读取的文件塞给服务器
        this->sendSize += len;//设置进度条的同步
        ui->progressBar->setValue(this->sendSize);
        myClient->waitForBytesWritten();//等待对方收完当前发送的数据再进行下一次的写，确保每一次都能够完全写成功（服务器完全收到了）
    }
    myFile->close();
    if(this->totalSize==this->sendSize)
    {
        msg=QString("文件上传成功！");
    }
    else
    {
        msg=QString("文件上传失败[totalSize:%1 sendSize:%2]")
                .arg(this->totalSize)
                .arg(this->sendSize);
    }
    ui->textEdit_Server->append(msg);


}


//end slots
