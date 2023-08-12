#include "widget.h"
#include "ui_widget.h"

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
    udpSocket=new QUdpSocket(this);
    connect(udpSocket,SIGNAL(connected()),
            this,SLOT(doProcessConnected()));
    connect(udpSocket,SIGNAL(readyRead()),
            this,SLOT(doProcessReadyRead()));
    connect(udpSocket,SIGNAL(disconnected()),
            this,SLOT(doProcessDisconnected()));
//    udpSocket->bind()
}

void Widget::doProcessConnected()
{
    QString msg="连接成功！";
    ui->textEdit->append(msg);
    ui->btn_bind->setEnabled(false);
}

void Widget::doProcessReadyRead()
{
    QByteArray datagram;
    QHostAddress addr;
    quint16 port;
    while (udpSocket->hasPendingDatagrams())
    {
        addr.clear();
        port = 0;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size(),&addr,&port);
    }
    QString msg=QString("[%1:%2]说:%3")
            .arg(addr.toString())
            .arg(port)
            .arg(QString(datagram));
    ui->textEdit->append(msg);
}

void Widget::doProcessDisconnected()
{
    QString msg="断开连接！";
    ui->textEdit->append(msg);
    ui->btn_bind->setEnabled(true);
}

void Widget::on_btn_bind_clicked()
{
    QString msg;
    QString port=ui->lineEdit_port->text();
    bool ret = udpSocket->bind(port.toUInt());
    if(!ret)
    {
        msg="failed";
    }
    else
    {
        msg="success";
    }
    ui->textEdit->append(msg);
}

void Widget::on_btn_send_clicked()
{
    QString peer_ip=ui->lineEdit_ip_peer->text();
    QString peer_port=ui->lineEdit_port_peer->text();
    QString msg = ui->textEdit_2->toPlainText();
    //发送数据给指定的端口
    udpSocket->writeDatagram(msg.toUtf8(),
                QHostAddress(peer_ip),peer_port.toUInt());
    ui->textEdit_2->clear();
}
