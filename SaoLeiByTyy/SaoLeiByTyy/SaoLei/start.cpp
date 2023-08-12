#include "start.h"
#include "ui_start.h"

#include <QPainter>
#include <QPixmap>

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);


//    ui->label->setScaledContents(true);
//    QMovie *iconShow = new QMovie(":/boom.gif");
//    ui->label->setMovie(iconShow);
//    ui->label->resize(this->size());
//    iconShow->start();
}

start::~start()
{
    delete ui;
}

void start::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/bg2.jpg"),QRect());
//    QPixmap pixmap = QPixmap(":/boombg.jpg");
//    QPainter painter(this);
//    painter.drawPixmap(this->rect(),pixmap);
}

void start::on_pushButton_start_clicked()
{
    mw = new MainWindow();
    mw->show();
    this->hide();

}

void start::on_pushButton_exit_clicked()
{
    mw->close();
}
