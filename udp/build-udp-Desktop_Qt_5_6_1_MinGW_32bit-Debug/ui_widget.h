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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QPushButton *btn_bind;
    QTextEdit *textEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_ip_peer;
    QLabel *label_3;
    QLineEdit *lineEdit_port_peer;
    QPushButton *btn_send;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(610, 515);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_ip = new QLineEdit(Widget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 0, 1, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_port = new QLineEdit(Widget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 0, 3, 1, 1);

        btn_bind = new QPushButton(Widget);
        btn_bind->setObjectName(QStringLiteral("btn_bind"));

        gridLayout->addWidget(btn_bind, 0, 4, 1, 1);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 5);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_ip_peer = new QLineEdit(Widget);
        lineEdit_ip_peer->setObjectName(QStringLiteral("lineEdit_ip_peer"));

        gridLayout->addWidget(lineEdit_ip_peer, 2, 1, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        lineEdit_port_peer = new QLineEdit(Widget);
        lineEdit_port_peer->setObjectName(QStringLiteral("lineEdit_port_peer"));

        gridLayout->addWidget(lineEdit_port_peer, 2, 3, 1, 1);

        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        gridLayout->addWidget(btn_send, 2, 4, 1, 1);

        textEdit_2 = new QTextEdit(Widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 3, 0, 1, 5);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "Local IP", 0));
        lineEdit_ip->setText(QApplication::translate("Widget", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("Widget", "Port", 0));
        btn_bind->setText(QApplication::translate("Widget", "bind", 0));
        label_4->setText(QApplication::translate("Widget", "Peer IP", 0));
        lineEdit_ip_peer->setText(QApplication::translate("Widget", "127.0.0.1", 0));
        label_3->setText(QApplication::translate("Widget", "Port", 0));
        btn_send->setText(QApplication::translate("Widget", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
