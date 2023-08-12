#include "userregister.h"

userRegister::userRegister(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("用户注册"));
    setWindowIcon(QIcon(":/new/prefix1/QQ.jpg"));
    Init();
}
void userRegister::Init()
{
    db=QSqlDatabase::addDatabase("QSQLITE");//设置数据库驱动 这里使用的是SQL Server
    db.setDatabaseName("userNameAndPwd1");
    if(!db.open())
    {
        qDebug()<<"打开失败";
    }
    else
    {
        qDebug()<<"打开成功";
    }

    //创建标签、行文本编辑器、按钮
    lbl_username=new QLabel(tr("用户名："));
    lbl_userPwd1=new QLabel(tr("请输入密码："));
    lbl_userPwd2=new QLabel(tr("请再次输入密码："));
    liedt_username=new QLineEdit();
    liedt_userPwd1=new QLineEdit();
    liedt_userPwd2=new QLineEdit();
    register_d=new QPushButton(tr("确认注册"));

    //创建布局，添加当前按钮至布局中
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(lbl_username,0,0);
    mainLayout->addWidget(lbl_userPwd1,1,0);
    mainLayout->addWidget(lbl_userPwd2,2,0);
    mainLayout->addWidget(liedt_username,0,1);
    mainLayout->addWidget(liedt_userPwd1,1,1);
    mainLayout->addWidget(liedt_userPwd2,2,1);
    mainLayout->addWidget(register_d,3,0,1,2);//行跨度为1，列跨度为2

    //按钮绑定
    connect(register_d,SIGNAL(clicked(bool)),this,SLOT(doProcessRegister()));//绑定按钮
}

void userRegister::doProcessRegister()
{
    //后续添加逻辑检测，例如：两次输入的密码是否相同，用户名规则等

    //后期目标：检测用户输入密码或者用户名是否重复，若重复，则提醒，否则进行注册
    //        检测用户输入的用户名格式、密码格式是否符合要求
    QString regName=liedt_username->text();//测试代码，在调试成功之后，将新建窗口，使用新的窗口注册
    QString regPwd=liedt_userPwd1->text();
    QString sql="INSERT INTO UsrNamePwd(userName,userPwd)VALUES(";
            sql+="\'"+regName+"\'"+","+"\'"+regPwd+"\'"+")";
    QSqlQuery q;
    if(!q.exec(sql))
    {
        qDebug() << "Error: Fail to create table." << q.lastError();
        db.close();
    }
    QMessageBox::about(this,"Success","注册成功！请重新登录");
    qDebug()<<"注册成功！"<<endl;
    LoginPage = new Widget();
    this->destroy(true);
}
