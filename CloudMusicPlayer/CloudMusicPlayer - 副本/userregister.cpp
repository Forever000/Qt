#include "userregister.h"

userRegister::userRegister(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 300);
    setWindowTitle(tr("用户注册"));
    setWindowIcon(QIcon(":/new/prefix1/img/image/systemTrayIcon.png"));
    Init();
}
void userRegister::Init()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userNameAndPwd1.db");
    if(!db.open())
    {
        qDebug()<<"数据库打开失败";
    }
    else
    {
        qDebug()<<"数据库打开成功";
    }

    //创建标签、行文本编辑器、按钮
    lbl_username=new QLabel(tr("用户名："));
    lbl_userPwd1=new QLabel(tr("请输入密码："));
    lbl_userPwd2=new QLabel(tr("请再次输入密码："));
    liedt_username=new QLineEdit();
    liedt_userPwd1=new QLineEdit();
    liedt_userPwd2=new QLineEdit();
    liedt_userPwd1->setEchoMode(QLineEdit::Password);
    liedt_userPwd2->setEchoMode(QLineEdit::Password);
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
    QString regName=liedt_username->text();//测试代码，在调试成功之后，将新建窗口，使用新的窗口注册
    QString regPwd1=liedt_userPwd1->text();
    QString regPwd2=liedt_userPwd2->text();

    QSqlQuery q;

    //检测用户输入密码或者用户名是否重复，若重复，则提醒，否则进行注册
    //遍历当前目录下数据库userNameAndPwd1中的表usrNamePwd,检查是否用户名已被注册
    QString sql1="select * from UsrNamePwd WHERE userName==";
    sql1+="\'"+regName+"\'";
    if(!q.exec(sql1))
    {
        qDebug() << "regName---Error: Fail to create table." << q.lastError();
        db.close();
    }
    while(q.next())
    {
        if(regName==q.value(0).toString())
        {
            QMessageBox::warning(this,"Warning","当前用户名已被注册！请重新输入用户名");
            liedt_username->selectAll();
            return;
        }
//        qDebug() << q.value(0).toString()<<q.value(1).toString()<<endl; // output all names
    }


//////////////////////////////////////////////////////////////////////////////////////


    //检测用户输入的用户名格式、密码格式是否符合要求
    if(!(regName.isEmpty()) && !(regPwd1.isEmpty()) && !(regPwd2.isEmpty()))
    {
        //添加逻辑检测，例如：两次输入的密码是否相同，用户名规则等
        if(regPwd1!=regPwd2)
        {
            QMessageBox::warning(this,"Warning","请确保两次输入的密码相同！");
            return;
        }

        QString sql="INSERT INTO UsrNamePwd(userName,userPwd)VALUES(";
                sql+="\'"+regName+"\'"+","+"\'"+regPwd1+"\'"+")";

        if(!q.exec(sql))
        {
            qDebug() << "Error: Fail to create table." << q.lastError();
            db.close();
        }
        QMessageBox::about(this,"Success","注册成功！请重新登录");
        qDebug()<<"注册成功！"<<endl;
        //将注册成功的信号发送出去
        emit backToLoginWidget();

//        LoginPage = new loginWidget();
//        LoginPage->show();
        this->hide();
//        this->destroyed(this);
//        this->destroy(true);
//        regName.clear();
//        regPwd1.clear();
//        regPwd2.clear();
    }
    else
    {
        QMessageBox::warning(this,"Warning","用户名或密码为空！");
        qDebug()<<"用户名或密码为空！"<<endl;
    }
}
void userRegister::paintEvent(QPaintEvent *)
{
    QPixmap pixmap=QPixmap(":/new/prefix1/img/background/理想家园.JPG");
    QPainter painter(this);
    painter.drawPixmap(this->rect(),pixmap);
}
