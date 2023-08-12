#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include "userregister.h"
#include"qmusic.h"
#include<QPixmap>
#include<QPainter>

class userRegister;//使用前向声明（forward declaration）来代替 #include 引用，或将类的实现移到源文件中，避免头文件相互引用的情况。
class QMusic;

namespace Ui {
class loginWidget;

}

class loginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginWidget(QWidget *parent = 0);
    ~loginWidget();


private slots:
    void doProcessLoginIn();
    void doProcessRegister();

private:
    Ui::loginWidget *ui;
    void Init();
    QSqlDatabase db;
    userRegister *userRegisterPage;
    QMusic *qmusic1;
    void paintEvent(QPaintEvent *);//绘图事件，自动调用

};

#endif // LOGINWIDGET_H
