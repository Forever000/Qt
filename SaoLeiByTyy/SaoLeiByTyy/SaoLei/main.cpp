#include "mainwindow.h"
#include "start.h"

#include <QApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //配置数据库

    //数据库连接测试

    //数据库查询操作

    //关闭数据库

    start s;
    s.show();
    return a.exec();
}
