#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlDatabase>
#include"userregister.h"

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
    void doProcessLoginIn();
    void doProcessRegister();


private:
    Ui::Widget *ui;
    void Init();
    QSqlDatabase db;
    userRegister *UserRegisterPage;
};

#endif // WIDGET_H
