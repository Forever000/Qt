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
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
          this, SLOT(doProcessFinished(QNetworkReply*)));
}


void Widget::on_btn_sure_clicked()
{
    QString myUrl = ui->lineEdit->text();
    manager->get(QNetworkRequest(QUrl(myUrl)));
}



////////////////////slots/////////////////////
void Widget::doProcessFinished(QNetworkReply *reply)
{
    QString str = reply->readAll();
    ui->textEdit->setText(str);
//    qDebug()<<str;
    qDebug()<<"OK!!!!!!";
}


///////////////////end slots//////////////////
