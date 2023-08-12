#include "loginwidget.h"
#include "ui_loginwidget.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlRecord>
#include<QSqlError>
#include<QMessageBox>

loginWidget::loginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWidget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix1/QQ.jpg"));//设置界面图标
    Init();
}

loginWidget::~loginWidget()
{
    delete ui;
}

void loginWidget::Init()
{
    //    q.prepare("INSERT INTO userNameAndPwd1 (userName, userPwd) "
    //                "VALUES (:userName, :userPwd)");
    //    q.bindValue(":userPwd", "xiaogao");
    //    q.bindValue(":userPwd", "123456789");

    //    qDebug() << "插入完毕！ " << endl;


    //遍历数据库
//    QSqlRecord rec = q.record();

//    qDebug() << "Number of columns: " << rec.count();

//    int nameCol = rec.indexOf("userPwd"); // index of the field "name"
//    while (q.next())
//      qDebug() << q.value(nameCol).toString(); // output all names


    db=QSqlDatabase::addDatabase("QSQLITE");//设置数据库驱动 这里使用的是SQL Server
    db.setDatabaseName("userNameAndPwd1");
//        db.setHostName("127.0.0.1");//设置主机名称，本地主机为127.0.0.1
//        db.setDatabaseName("userNameAndPwd1");//添加数据源，在ODBC中添加的
//        db.setUserName("aaa");//登录名称,在SQL Server中添加的登录名
//        db.setPassword("123456");//密码，在SQL Server中添加的登录名的密码
    if(!db.open())
    {
        qDebug()<<"数据库打开失败";
    }
    else
    {
        qDebug()<<"数据库打开成功";
    }
    connect(ui->btn_Login_in,SIGNAL(clicked(bool)),this,SLOT(doProcessLoginIn()));
    connect(ui->btn_Register,SIGNAL(clicked(bool)),this,SLOT(doProcessRegister()));
}

void loginWidget::doProcessLoginIn()
{
    //遍历当前目录下数据库userNameAndPwd1中的表usrNamePwd
    QString sql="select * from usrNamePwd";
    QSqlQuery q;
    if(!q.exec(sql))
    {
        qDebug() << "Error: Fail to create table." << q.lastError();
        db.close();
    }
    while (q.next())
    {
        QString userName = ui->lineEdit_userName->text();
        QString userPwd = ui->lineEdit_userPwd->text();
        if(!(userName.isEmpty()) && !(userPwd.isEmpty()))
        {
            if(userName==q.value(0).toString())
            {
                if(userPwd==q.value(1).toString())
                {
                    QMessageBox::about(this,"Success","登录成功！");
                    //产生新的窗体，用于网络通信功能
                    qmusic1=new QMusic();
                    qmusic1->show();
                    this->hide();
                }
                else
                {
                    QMessageBox::warning(this,"Warning","密码错误！");
                }
            }
//            qDebug() << q.value(0).toString()<<q.value(1).toString()<<endl; // output all names
        }
        else
        {
            qDebug()<<"用户名或密码为空！"<<endl;
            return;
        }
    }
}
void loginWidget::doProcessRegister()
{
    userRegisterPage= new userRegister();
    userRegisterPage->show();//加载子窗体
//    this->destroy(true);//销毁当前窗体
    this->hide();
}

void loginWidget::paintEvent(QPaintEvent *)
{
    QPixmap pixmap=QPixmap(":/new/prefix1/background/default.jpg");
    QPainter painter(this);
    painter.drawPixmap(this->rect(),pixmap);
}
