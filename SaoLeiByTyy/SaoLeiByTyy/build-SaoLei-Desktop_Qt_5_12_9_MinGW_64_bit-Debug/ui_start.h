/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_start;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName(QString::fromUtf8("start"));
        start->resize(576, 575);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bomb.png"), QSize(), QIcon::Normal, QIcon::Off);
        start->setWindowIcon(icon);
        start->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(start);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 450, 281, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_start = new QPushButton(widget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setStyleSheet(QString::fromUtf8("background-image: url(:/exit.png);"));

        horizontalLayout->addWidget(pushButton_start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_exit = new QPushButton(widget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setStyleSheet(QString::fromUtf8("background-image: url(:/start.png);"));

        horizontalLayout->addWidget(pushButton_exit);


        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QWidget *start)
    {
        start->setWindowTitle(QApplication::translate("start", "\346\211\253\351\233\267\346\270\270\346\210\217", nullptr));
        pushButton_start->setText(QApplication::translate("start", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_exit->setText(QApplication::translate("start", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
