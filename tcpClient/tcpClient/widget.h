#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include<QHostAddress>

#include<QTcpServer>
#include<QNetworkInterface>


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

    void on_btn_send_clicked();

    void doProcessConnected();

    void doProcessReadyRead();

    void doProcessDisconnected();

    void doProcessError(QAbstractSocket::SocketError);





private:
    Ui::Widget *ui;
    QTcpSocket *myClient;
    void Init();
};

#endif // WIDGET_H
