#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QNetworkInterface>
#include<QTcpSocket>

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

    void doProcessAcceptError(QAbstractSocket::SocketError);

    void doProcessReadyRead();

    void doProcessDisconnected();

    void on_btn_send_clicked();

//    void doProcessConnected();

private:
    Ui::Widget *ui;
    QTcpServer *myServer;
    QList<QTcpSocket *> arryClients;
    QTcpSocket *client;

    void Init();
};

#endif // WIDGET_H
