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
#include<QPainter>

class userRegister : public QWidget
{
    Q_OBJECT
public:
    explicit userRegister(QWidget *parent = 0);

    void Clear_liedt_userInfo()
    {
        liedt_username->clear();
        liedt_userPwd1->clear();
        liedt_userPwd2->clear();
    }

signals:
    void backToLoginWidget();

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
    //绘图事件，自动调用
    void paintEvent(QPaintEvent *);
};

#endif // USERREGISTER_H
