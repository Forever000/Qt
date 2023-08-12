/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            start->setObjectName(QStringLiteral("start"));
        start->resize(576, 575);
        QIcon icon;
        icon.addFile(QStringLiteral(":/bomb.png"), QSize(), QIcon::Normal, QIcon::Off);
        start->setWindowIcon(icon);
        start->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(start);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 450, 311, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_start = new QPushButton(widget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setStyleSheet(QStringLiteral("background-image: url(:/exit.png);"));

        horizontalLayout->addWidget(pushButton_start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_exit = new QPushButton(widget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setStyleSheet(QStringLiteral("background-image: url(:/start.png);"));

        horizontalLayout->addWidget(pushButton_exit);


        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QWidget *start)
    {
        start->setWindowTitle(QApplication::translate("start", "\346\211\253\351\233\267\346\270\270\346\210\217", 0));
        pushButton_start->setText(QApplication::translate("start", "\345\274\200\345\247\213\346\270\270\346\210\217", 0));
        pushButton_exit->setText(QApplication::translate("start", "\351\200\200\345\207\272\346\270\270\346\210\217", 0));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
