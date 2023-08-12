#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include<QPixmap>
#include<QPainter>
#include<QDialog>


namespace Ui {
class loginWidget;
}

class loginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginWidget(QWidget *parent = 0);
    ~loginWidget();

private:
    Ui::loginWidget *ui;
    void Init();
    QSqlDatabase db;
    void paintEvent(QPaintEvent *);//绘图事件，自动调用

private slots:
    //登录逻辑设计
    void doProcessLoginIn();
    //注册点击设计
    void doProcessRegister();

signals:
    //登录成功，发出信号
    void signal_loginSuccess();
    //点击注册，发出信号，更新窗口
    void signal_register_click();
    //登录成功，发出当前登录的用户名
    void signal_loginName(QString);

};

#endif // LOGINWIDGET_H
