#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>

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
    void on_btn_sure_clicked();

    void doProcessFinished(QNetworkReply*);

private:
    Ui::Widget *ui;
    ///////使用程序的方式进行爬取网站
    QNetworkAccessManager *manager;
    void Init();
};

#endif // WIDGET_H
