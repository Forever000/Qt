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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_Server;
    QLabel *label_2;
    QLineEdit *lineEdit_Server_Port;
    QPushButton *btn_connect;
    QProgressBar *progressBar;
    QPushButton *btn_fileUpload;
    QTextEdit *textEdit_Server;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(613, 477);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_Server = new QLineEdit(Widget);
        lineEdit_Server->setObjectName(QStringLiteral("lineEdit_Server"));

        gridLayout->addWidget(lineEdit_Server, 0, 1, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_Server_Port = new QLineEdit(Widget);
        lineEdit_Server_Port->setObjectName(QStringLiteral("lineEdit_Server_Port"));

        gridLayout->addWidget(lineEdit_Server_Port, 0, 3, 1, 1);

        btn_connect = new QPushButton(Widget);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));

        gridLayout->addWidget(btn_connect, 0, 4, 1, 1);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 0, 1, 5);

        btn_fileUpload = new QPushButton(Widget);
        btn_fileUpload->setObjectName(QStringLiteral("btn_fileUpload"));

        gridLayout->addWidget(btn_fileUpload, 2, 0, 1, 5);

        textEdit_Server = new QTextEdit(Widget);
        textEdit_Server->setObjectName(QStringLiteral("textEdit_Server"));

        gridLayout->addWidget(textEdit_Server, 3, 0, 1, 5);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP", 0));
        label_2->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250Port", 0));
        btn_connect->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
        btn_fileUpload->setText(QApplication::translate("Widget", "\344\270\212\344\274\240\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
