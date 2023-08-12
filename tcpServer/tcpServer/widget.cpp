#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
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
    myServer=new QTcpServer(this);
}

void Widget::on_btn_bind_clicked()
{
    QString myAddr;
    //通过程序遍历网卡IP

//    QList<QHostAddress> addrs = QNetworkInterface::allAddresses();
//    for(int i=0;i<addrs.length();i++)
//    {
//        QHostAddress addr = addrs.at(i);
//        qDebug()<<addr.toString();
//        if(addr.toString().contains("192."))
//        {
//            myAddr=addr.toString();
//            break;
//        }
//    }


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
    connect(myServer,SIGNAL(acceptError(QAbstractSocket::SocketError)),
            this,SLOT(doProcessAcceptError(QAbstractSocket::SocketError)));
}
void Widget::doProcessNewConnection()
{
    client = myServer->nextPendingConnection();//获取到客户端的描述符
    arryClients.append(client);
    QString msg=QString("客户端[%1:%2]连入！")
            .arg(client->peerAddress().toString())
            .arg(client->peerPort());//对方的IP地址和d端口号
    //获得客户端的ip及port自动添加上去
    ui->lineEdit_Client->setText(client->peerAddress().toString());
    ui->lineEdit_Client_Port->setText(QString::number(client->peerPort()));
    ui->textEdit_Server->append(msg);

    //使用槽检测客户端断开
    connect(client,SIGNAL(disconnected()),
            this,SLOT(doProcessDisconnected()));
    //使用槽读取内容
    connect(client,SIGNAL(readyRead()),this,
            SLOT(doProcessReadyRead()));
//    //客户端的连入
//    connect(client,SIGNAL(connected()),
//            this,SLOT(doProcessConnected()));

}

void Widget::doProcessAcceptError(QAbstractSocket::SocketError err)
{
    qDebug()<<err;
}

void Widget::doProcessDisconnected()
{
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString msg=QString("客户端[%1:%2]退出！")
            .arg(client->peerAddress().toString())
            .arg(client->peerPort());//对方的IP地址和d端口号
    ui->textEdit_Client->append(msg);

    //删除对应客户端
    for(int i=0;i<arryClients.length();i++)
    {
        if(arryClients.at(i)->peerAddress() == client->peerAddress())
        {
            if(arryClients.at(i)->peerPort() == client->peerPort())
            {
                arryClients.removeAt(i);
                break;
            }
        }
    }
}
//读取客户端发过来的信息
void Widget::doProcessReadyRead()
{
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString str1=QString("客户端[%1:%2]说：")
            .arg(client->peerAddress().toString())
            .arg(client->peerPort());//对方的IP地址和d端口号
    QString msg,str2;
    while(!client->atEnd())//当前读写位置不在末尾
    {

        QString ms=QString(client->readAll());
        msg.append(ms);
        qDebug()<<ms<<endl;
    }
    //客户端说对方的IP地址和d端口号 客户端发过来的信息
    str2=QString("%1%2").arg(str1).arg(msg);
    ui->textEdit_Server->append(str2);

}

void Widget::on_btn_send_clicked()
{
    qDebug()<<"服务器发送按钮点击"<<endl;
    QString ip = ui->lineEdit_Client->text();
    QString port = ui->lineEdit_Client_Port->text();
    //查找对应的客户
    for(int i=0;i<arryClients.length();i++)
    {
        if(arryClients.at(i)->peerAddress().toString()==ip)
        {
            if(arryClients.at(i)->peerPort()==port.toUInt())
            {
                qDebug()<<"已发送消息2"<<arryClients.at(i)->peerAddress().toString()<<endl;
                QString msg=ui->textEdit_Client->toPlainText();
                arryClients.at(i)->write(msg.toUtf8());
                qDebug()<<"已发送消息"<<msg.toUtf8()<<endl;
                ui->textEdit_Client->clear();
                break;
            }
        }
    }
}
//void Widget::doProcessConnected()
//{
//    QTcpSocket *client = (QTcpSocket *)this->sender();

//}
