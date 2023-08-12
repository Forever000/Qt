#include "qqmainwindow.h"
#include "ui_qqmainwindow.h"

QQMainWindow::QQMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QQMainWindow)
{
    ui->setupUi(this);
}

QQMainWindow::~QQMainWindow()
{
    delete ui;
}
