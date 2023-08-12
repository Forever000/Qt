#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

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
    manager=new QNetworkAccessManager();
}

void Widget::on_btn_sure_clicked()
{
    QNetworkRequest request;
    ///设置头使用的是什么浏览器，优点在于：使自己的请求更像是浏览器在请求下载，而不是普通程序请求下载，
    /// 避免了服务器判断不是浏览器在请求（防止网络爬虫），从而截断该程序的请求
    request.setRawHeader(QByteArray("User-Agent"),QByteArray("MyOwnBrowser 1.0"));
    QString url = ui->lineEdit->text();
    request.setUrl(QUrl(url));

    reply = manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(doProcessReadyRead()));
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),
            this,SLOT(doProcessError(QNetworkReply::NetworkError)));
    connect(reply,SIGNAL(finished()),this,SLOT(doProcessFinish()));//处理文件下载完成后关闭文件
}

////slots//////////
void Widget::doProcessReadyRead()
{
    QString str = reply->readAll();
    ui->textEdit->setText(str);
}l
void Widget::doProcessError(QNetworkReply::NetworkError error)
{
    switch (error) {
    case QNetworkReply::ConnectionRefusedError:
    {
        qDebug()<<"ConnectionRefusedError";
        break;
    }
    case QNetworkReply::RemoteHostClosedError:
    {
        qDebug()<<"RemoteHostClosedError";
        break;
    }
    default:
        break;
    }
}

void Widget::doProcessFinish()
{
    qDebug()<<"下载完成！";
    //reply->close();
}


////////end slots//////////
