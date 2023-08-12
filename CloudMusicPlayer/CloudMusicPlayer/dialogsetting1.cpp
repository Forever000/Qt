#include "dialogsetting1.h"
#include "ui_dialogsetting1.h"
#include<QPainter>
#include<QPixmap>

dialogSetting1::dialogSetting1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogSetting1)
{
    ui->setupUi(this);
//    setFixedSize(400, 300);
    setWindowIcon(QIcon(":/new/prefix1/img/image/setting.png"));//设置界面图标
    Init();
}

dialogSetting1::~dialogSetting1()
{
    delete ui;
}

void dialogSetting1::Init()
{
    connect(ui->buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(doProcessbuttonBoxClick(QAbstractButton*)));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(doProcessTakePhoto()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(doProcessOpenPic()));
//    connect(ui->comboBox_4,SIGNAL(currentIndexChanged(int)),this,SLOT(doProcesscurrentIndexChanged(int)));

//    camdialog=new QDialog(this);
}
void dialogSetting1::doProcessbuttonBoxClick(QAbstractButton* btn)
{
    //获取触发信号的对象（即按钮）
    if(btn==ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        qDebug()<<"1000"<<endl;
        int curIndex=ui->comboBox_4->currentIndex();
        emit engineChose(curIndex);//发出当前选择的信号
        this->close();
    }
    if(btn==ui->buttonBox->button(QDialogButtonBox::Cancel))
    {
        qDebug()<<"1000"<<endl;
        this->close();
    }
}

void dialogSetting1::doProcessTakePhoto()
{
//    ui->stackedWidget->setCurrentIndex(1);
//    camera = new QCamera;
//    camera->start();
//    viewfinder = new QCameraViewfinder;
//    viewfinder->setMinimumSize(640, 480);
//    camera->setViewfinder(viewfinder);

//    ui->stackedWidget->currentWidget()->layout()->addWidget(viewfinder);
}

void dialogSetting1::doProcessOpenPic()
{
    //从本地获取文件
}

//void dialogSetting1::doProcesscurrentIndexChanged(int ind)
//{
//    ui->comboBox_4->setCurrentIndex(ind);
//}


void dialogSetting1::paintEvent(QPaintEvent *)
{
    QPixmap pixmap=QPixmap(":/new/prefix1/img/background/理想家园.JPG");
    QPainter painter(this);
    painter.drawPixmap(this->rect(),pixmap);
}
