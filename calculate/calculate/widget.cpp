#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    a.clear();
    b.clear();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_0_clicked()
{
    a+="0";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_1_clicked()
{
    a+="1";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_2_clicked()
{
    a+="2";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_3_clicked()
{
    a+="3";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_4_clicked()
{
    a+="4";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_5_clicked()
{
    a+="5";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_6_clicked()
{
    a+="6";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_7_clicked()
{
    a+="7";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_8_clicked()
{
    a+="8";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_9_clicked()
{
    a+="9";
    ui->lineEdit_shuru->setText(a);
}

void Widget::on_pushButton_dian_clicked()
{
    a+=".";
    ui->lineEdit_shuru->setText(a);
}
//清除当前的字符串
void Widget::on_pushButton_C_clicked()
{
    a.clear();
    b.clear();
    ui->lineEdit_shuru->setText(a);
}
//字符串倒位剔除
void Widget::on_pushButton_backspace_clicked()
{
    a.chop(1);
    ui->lineEdit_shuru->setText(a);
}
//符号+
void Widget::on_pushButton_jia_clicked()
{
    b.insert(0,a);
    a.clear();
    b.insert(1,"+");
    ui->lineEdit_shuru->setText(a);
}
//符号-
void Widget::on_pushButton_jian_clicked()
{
    b.insert(0,a);
    a.clear();
    b.insert(1,"-");
    ui->lineEdit_shuru->setText(a);
}
//符号*
void Widget::on_pushButton_cheng_clicked()
{
    b.insert(0,a);
    a.clear();
    b.insert(1,"*");
    ui->lineEdit_shuru->setText(a);
}
//符号/
void Widget::on_pushButton_chu_clicked()
{
    b.insert(0,a);
    a.clear();
    b.insert(1,"/");
    ui->lineEdit_shuru->setText(a);
}
//符号=
void Widget::on_pushButton_deng_clicked()
{
    //当点击“=”时候，字符串数组里边只用了2位，
    // 第1个是数字，第二位是运算符，第2个数字虽然已经输入显示，但是需要在运算的时候才加入
    if(b.count()==2)
    {
        b.insert(2,a);
        if(b.at(1)=="+")
        {
            float result=QString(b.at(0)).toFloat()+QString(b.at(2)).toFloat();
            ui->lineEdit_shuru->setText(QString::number(result));
            //将运算结果转化为字符串重新输入到数组中，重复计算，提高使用的效率
            /*
            QString x=QString(b.at(0));
            QString y=QString(b.at(1));
            QString z=QString(b.at(2));
            QString w=QString::number(result);
            x.append(y).append(z).append("=").append(w);
            ui->lineEdit_shuru->setText(x);
            */
            a.clear();
            b.clear();
            a=QString::number(result);
        }
        else if(b.at(1)=="-")
        {
            float result=QString(b.at(0)).toFloat()-QString(b.at(2)).toFloat();
            ui->lineEdit_shuru->setText(QString::number(result));
            a.clear();
            b.clear();
            a=QString::number(result);
        }
        else if(b.at(1)=="*")
        {
            float result=QString(b.at(0)).toFloat()*QString(b.at(2)).toFloat();
            ui->lineEdit_shuru->setText(QString::number(result));
            a.clear();
            b.clear();
            a=QString::number(result);
        }
        else if(b.at(1)=="/")
        {
            if(QString(b.at(2)).toInt())
            {
                float result=QString(b.at(0)).toFloat()/QString(b.at(2)).toFloat();
                ui->lineEdit_shuru->setText(QString::number(result));
                a.clear();
                b.clear();
                a=QString::number(result);
            }
            else
            {
                ui->lineEdit_shuru->setText("除数为0！");
                qDebug()<<"除数为0！"<<endl;
            }

        }
        else
        {
            qDebug()<<"输入有误！"<<endl;
        }

    }
    else
    {
        qDebug()<<"默认方法"<<endl;
        a.clear();
        b.clear();
        ui->lineEdit_shuru->setText("NULL");

    }
}
