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

////////////slots//////////////////////
void Widget::on_btn_sure_clicked()
{
    QNetworkRequest request;
    QString url = ui->lineEdit->text();
    request.setUrl(QUrl(url));

    reply = manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(doProcessReadyRead()));
    connect(reply,SIGNAL(finished()),this,SLOT(doProcessFinished()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),
            this,SLOT(doProcessDownloadProgress(qint64,qint64)));
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),
            this,SLOT(doProcessError(QNetworkReply::NetworkError)));

    //QStringList urlList = url.split("/");
    //QString filename = urlList.at(urlList.length()-1);

    //URL获取自https://www.flvcd.com/parse.php?format=&kw=https%3A%2F%2Fwww.ixigua.com%2F7058446746094928417%3FlogTag%3Dec57c65aecc328007334&sbt=%BF%AA%CA%BCGO%21
    myFile->setFileName("myVIDEO.mp4");
    bool ret = myFile->open(QIODevice::WriteOnly|QIODevice::Truncate);
    if(!ret)
    {
        QMessageBox::warning(this,"warning","open file error!");
        return;
    }
    ui->progressBar->setValue(0);
    ui->progressBar->setMinimum(0);


}

void Widget::doProcessReadyRead()
{
    while(!reply->atEnd())
    {
        QByteArray ba = reply->readAll();
        myFile->write(ba);
        qDebug()<<"当前进度为："<<ui->progressBar->value();
    }
}
void Widget::doProcessFinished()
{
    myFile->close();
    QMessageBox::information(this,"info","write finish!");
}
void Widget::doProcessDownloadProgress(qint64 receive_total, qint64 all_total)
{   
    ui->progressBar->setMaximum(all_total);//检测文件总共大小，并设置为最大
    ui->progressBar->setValue(receive_total);//接收当前的进度

}
void Widget::doProcessError(QNetworkReply::NetworkError err)
{
    qDebug()<<err;
}

///////////end slots//////////////////


////////////function///////////////
void Widget::Init()
{
    manager=new QNetworkAccessManager(this);
    myFile=new QFile(this);

}


///////////end function////////////
