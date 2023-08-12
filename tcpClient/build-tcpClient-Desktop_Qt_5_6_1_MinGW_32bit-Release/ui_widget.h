/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit_Client;
    QTextEdit *textEdit_Server;
    QGridLayout *gridLayout_2;
    QPushButton *btn_send;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Server;
    QLabel *label_2;
    QLineEdit *lineEdit_Server_Port;
    QPushButton *btn_bind;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(679, 572);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit_Client = new QTextEdit(Widget);
        textEdit_Client->setObjectName(QStringLiteral("textEdit_Client"));

        gridLayout->addWidget(textEdit_Client, 3, 0, 1, 1);

        textEdit_Server = new QTextEdit(Widget);
        textEdit_Server->setObjectName(QStringLiteral("textEdit_Server"));

        gridLayout->addWidget(textEdit_Server, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        gridLayout_2->addWidget(btn_send, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_Server = new QLineEdit(Widget);
        lineEdit_Server->setObjectName(QStringLiteral("lineEdit_Server"));

        horizontalLayout->addWidget(lineEdit_Server);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_Server_Port = new QLineEdit(Widget);
        lineEdit_Server_Port->setObjectName(QStringLiteral("lineEdit_Server_Port"));

        horizontalLayout->addWidget(lineEdit_Server_Port);

        btn_bind = new QPushButton(Widget);
        btn_bind->setObjectName(QStringLiteral("btn_bind"));

        horizontalLayout->addWidget(btn_bind);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "TcpClient", 0));
        btn_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP", 0));
        lineEdit_Server->setText(QApplication::translate("Widget", "192.168.1.3", 0));
        label_2->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250Port", 0));
        lineEdit_Server_Port->setText(QApplication::translate("Widget", "9000", 0));
        btn_bind->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
