#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>

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
    void doProcessConnected();

    void doProcessReadyRead();

    void doProcessDisconnected();

    void on_btn_bind_clicked();

    void on_btn_send_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;

    void Init();
};

#endif // WIDGET_H
