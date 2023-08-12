#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#define MaxNum 100

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
    myClient=new QTcpSocket(this);
}

//slots
void Widget::on_btn_bind_clicked()
{
    QString servIP = ui->lineEdit_Server->text();
    QString servPort = ui->lineEdit_Server_Port->text();
    myClient->connectToHost(QHostAddress(servIP),servPort.toUInt());
    //通过绑定判断是否连接成功
    connect(myClient,SIGNAL(connected()),
            this,SLOT(doProcessConnected()));
    connect(myClient,SIGNAL(readyRead()),
            this,SLOT(doProcessReadyRead()));
    connect(myClient,SIGNAL(disconnected()),
            this,SLOT(doProcessDisconnected()));
    connect(myClient,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(doProcessError(QAbstractSocket::SocketError)));

}

void Widget::doProcessConnected()
{
    QString msg = "服务器连接成功！";
    ui->textEdit_Server->append(msg);
    ui->btn_bind->setEnabled(false);
}
void Widget::doProcessReadyRead()
{
    QString msg,str1,str2;
    str1=QString("服务器[%1:%2]说：")
            .arg(myClient->peerAddress().toString())
            .arg(myClient->peerPort());
    while(!myClient->atEnd())
    {
        str2.append(QString(myClient->readAll()));
    }
    msg=QString("%1%2").arg(str1).arg(str2);
    ui->textEdit_Server->append(msg);
}
void Widget::doProcessDisconnected()
{
    QString msg=QString("服务器退出！");
    ui->textEdit_Server->append(msg);
    ui->btn_bind->setEnabled(true);
}
void Widget::doProcessError(QAbstractSocket::SocketError err)
{
    qDebug()<<err;
}


void Widget::on_btn_send_clicked()
{
    QString msg=ui->textEdit_Client->toPlainText();
    int ret = myClient->write(msg.toUtf8());
    if(ret<=0)
    {
        return;
    }
    ui->textEdit_Client->clear();
}
//end slots

