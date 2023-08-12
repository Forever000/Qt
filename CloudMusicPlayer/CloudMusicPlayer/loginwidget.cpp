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
    setFixedSize(400, 300);
    setWindowIcon(QIcon(":/new/prefix1/img/image/systemTrayIcon.png"));//设置界面图标
    Init();
}

loginWidget::~loginWidget()
{
    delete ui;
}

void loginWidget::Init()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db=QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db=QSqlDatabase::addDatabase("QSQLITE");//设置数据库驱动 这里使用的是SQL Server
        db.setDatabaseName("userNameAndPwd1.db");
        if(!db.open())
        {
            qDebug()<<"数据库打开失败";
            QMessageBox::critical(this,"无法打开数据库文件：userNameAndPwd1.db",db.lastError().databaseText());
            exit(-1);
        }
        else
        {
            qDebug()<<"数据库打开成功";
        }
    }

    //检查MusicInfo表是否存在，不存在则创建该表
    QSqlQuery query;
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("MusicInfo"));
    if(query.next()){
        if(query.value(0).toInt()==0){
            QSqlQuery sql_query;
            //QString create_sql = "create table MusicInfo (id int primary key, name varchar(30), url varchar(200), author varchar(50), title varchar(50), duration bigint, albumTitle varchar(50), audioBitRate int)";
            QString create_sql = "create table MusicInfo (userName varchar(30), url varchar(200), author varchar(50), title varchar(50), duration bigint, albumTitle varchar(50), audioBitRate int)";
            sql_query.prepare(create_sql);
            sql_query.exec();
        }
    }
    //检查UsrNamePwd表是否存在，不存在则创建该表
    QSqlQuery query2;
    query2.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("UsrNamePwd"));
    if(query2.next()){
        if(query2.value(0).toInt()==0){
            QSqlQuery sql_query;
            QString create_sql = "create table UsrNamePwd (userName varchar(30),userPwd varchar(30))";
            sql_query.prepare(create_sql);
            sql_query.exec();
        }
    }

    connect(ui->btn_Login_in_2,SIGNAL(clicked(bool)),this,SLOT(doProcessLoginIn()));
    connect(ui->btn_Register_2,SIGNAL(clicked(bool)),this,SLOT(doProcessRegister()));


}

void loginWidget::doProcessLoginIn()
{
    db=QSqlDatabase::addDatabase("QSQLITE");//设置数据库驱动 这里使用的是SQL Server
    db.setDatabaseName("userNameAndPwd1.db");
    if(!db.open())
    {
        qDebug()<<"数据库打开失败";
        QMessageBox::critical(this,"无法打开数据库文件：userNameAndPwd1.db",db.lastError().databaseText());
        exit(-1);
    }
    else
    {
        qDebug()<<"数据库打开成功";
    }

    //遍历当前目录下数据库userNameAndPwd1中的表UsrNamePwd
    QString sql="select * from UsrNamePwd";
    QSqlQuery q;
    if(!q.exec(sql))
    {
        qDebug() << "loginwidget------Error: Fail to create table." << q.lastError();
        db.close();
    }
    while (q.next())
    {
        QString userName = ui->lineEdit_userName_2->text();
        QString userPwd = ui->lineEdit_userPwd_2->text();
        if(!(userName.isEmpty()) && !(userPwd.isEmpty()))
        {
            if(userName==q.value(0).toString())
            {
                if(userPwd==q.value(1).toString())
                {
                    QMessageBox::about(this,"Success","登录成功！");
                    //登录成功加载该用户数据库中存储的内容
                    //登录成功之后向主窗体发出信号，删除dialog对话框
                    emit signal_loginSuccess();
                    emit signal_loginName(userName);
                    qDebug()<<"信号发送成功signal_loginSuccess"<<endl;
                    ui->lineEdit_userName_2->clear();
                    ui->lineEdit_userPwd_2->clear();
                    return;
                }
                else
                {
                    QMessageBox::warning(this,"Warning","密码错误！");
                }
            }
        }
        else
        {
            QMessageBox::warning(this,"Warning","用户名或密码为空！");
            qDebug()<<"用户名或密码为空！"<<endl;
            return;
        }
    }
}
void loginWidget::doProcessRegister()
{
    emit signal_register_click();
    qDebug()<<"信号发送成功signal_register_click"<<endl;

}

void loginWidget::paintEvent(QPaintEvent *)
{
    QPixmap pixmap=QPixmap(":/new/prefix1/img/background/理想家园.JPG");
    QPainter painter(this);
    painter.drawPixmap(this->rect(),pixmap);
}

//void loginWidget::reBackToLoginWidget()
//{

//    this->show();
//    emit signal_reloadloginwidgetTodialog();

//}
