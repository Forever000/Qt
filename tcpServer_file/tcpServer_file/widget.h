#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btn_bind_clicked();

    void doProcessNewConnection();

    void doProcessReadyRead();

private:
    Ui::Widget *ui;
    QTcpServer *myServer;
    QTcpSocket *client;
    qint64 recvTotal;
    qint64 allTotal;
    QFile *myFile;

    void Init();

};

#endif // WIDGET_H
