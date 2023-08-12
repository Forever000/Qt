/********************************************************************************
** Form generated from reading UI file 'qqmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQMAINWINDOW_H
#define UI_QQMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Server;
    QLabel *label_2;
    QLineEdit *lineEdit_Server_Port;
    QPushButton *btn_bind;
    QTextEdit *textEdit_Client;
    QTextEdit *textEdit_Server;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Client;
    QLabel *label_4;
    QLineEdit *lineEdit_Client_Port;
    QPushButton *btn_send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QQMainWindow)
    {
        if (QQMainWindow->objectName().isEmpty())
            QQMainWindow->setObjectName(QStringLiteral("QQMainWindow"));
        QQMainWindow->resize(665, 592);
        centralwidget = new QWidget(QQMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 603, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_Server = new QLineEdit(layoutWidget);
        lineEdit_Server->setObjectName(QStringLiteral("lineEdit_Server"));

        horizontalLayout->addWidget(lineEdit_Server);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_Server_Port = new QLineEdit(layoutWidget);
        lineEdit_Server_Port->setObjectName(QStringLiteral("lineEdit_Server_Port"));

        horizontalLayout->addWidget(lineEdit_Server_Port);

        btn_bind = new QPushButton(layoutWidget);
        btn_bind->setObjectName(QStringLiteral("btn_bind"));

        horizontalLayout->addWidget(btn_bind);

        textEdit_Client = new QTextEdit(centralwidget);
        textEdit_Client->setObjectName(QStringLiteral("textEdit_Client"));
        textEdit_Client->setGeometry(QRect(21, 322, 623, 220));
        textEdit_Server = new QTextEdit(centralwidget);
        textEdit_Server->setObjectName(QStringLiteral("textEdit_Server"));
        textEdit_Server->setGeometry(QRect(21, 58, 623, 220));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 290, 603, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_Client = new QLineEdit(layoutWidget_2);
        lineEdit_Client->setObjectName(QStringLiteral("lineEdit_Client"));

        horizontalLayout_2->addWidget(lineEdit_Client);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_Client_Port = new QLineEdit(layoutWidget_2);
        lineEdit_Client_Port->setObjectName(QStringLiteral("lineEdit_Client_Port"));

        horizontalLayout_2->addWidget(lineEdit_Client_Port);

        btn_send = new QPushButton(layoutWidget_2);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout_2->addWidget(btn_send);

        QQMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QQMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 665, 26));
        QQMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(QQMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QQMainWindow->setStatusBar(statusbar);

        retranslateUi(QQMainWindow);

        QMetaObject::connectSlotsByName(QQMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QQMainWindow)
    {
        QQMainWindow->setWindowTitle(QApplication::translate("QQMainWindow", "QQ_v1.1", 0));
        label->setText(QApplication::translate("QQMainWindow", "\346\234\215\345\212\241\345\231\250IP", 0));
        lineEdit_Server->setText(QApplication::translate("QQMainWindow", "192.168.1.3", 0));
        label_2->setText(QApplication::translate("QQMainWindow", "\346\234\215\345\212\241\345\231\250Port", 0));
        lineEdit_Server_Port->setText(QApplication::translate("QQMainWindow", "9000", 0));
        btn_bind->setText(QApplication::translate("QQMainWindow", "\347\273\221\345\256\232", 0));
        label_3->setText(QApplication::translate("QQMainWindow", "\345\256\242\346\210\267\347\253\257IP", 0));
        label_4->setText(QApplication::translate("QQMainWindow", "\345\256\242\346\210\267\347\253\257Port", 0));
        btn_send->setText(QApplication::translate("QQMainWindow", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class QQMainWindow: public Ui_QQMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQMAINWINDOW_H
