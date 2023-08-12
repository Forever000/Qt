#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include<QFileDialog>
#include<QFile>

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
    void on_btn_connect_clicked();

    void doProcessConnected();

    void on_btn_fileUpload_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *myClient;
    QFile *myFile;
    quint64 totalSize;
    quint64 sendSize;

    void Init();
};

#endif // WIDGET_H
