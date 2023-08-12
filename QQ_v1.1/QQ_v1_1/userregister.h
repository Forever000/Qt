#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QGridLayout>
#include<QPushButton>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlRecord>
#include<QSqlError>
#include<QMessageBox>
#include"loginwidget.h"
//#include<QPixmap>
//#include<QPainter>

class loginWidget;//使用前向声明（forward declaration）来代替 #include 引用，或将类的实现移到源文件中，避免头文件相互引用的情况。

class userRegister : public QWidget
{
    Q_OBJECT
public:
    explicit userRegister(QWidget *parent = 0);

signals:

public slots:
    void doProcessRegister();

private:
    void Init();
    QSqlDatabase db;
    QLabel *lbl_username;
    QLabel *lbl_userPwd1;
    QLabel *lbl_userPwd2;
    QLineEdit *liedt_username;
    QLineEdit *liedt_userPwd1;
    QLineEdit *liedt_userPwd2;
    QGridLayout *mainLayout;
    QPushButton *register_d;
    loginWidget *LoginPage;

    //绘图事件，自动调用
    void paintEvent(QPaintEvent *);


};

#endif // USERREGISTER_H
