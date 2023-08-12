/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWidget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_Login_in_2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_Register_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_userName_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_userPwd_2;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;

    void setupUi(QWidget *loginWidget)
    {
        if (loginWidget->objectName().isEmpty())
            loginWidget->setObjectName(QStringLiteral("loginWidget"));
        loginWidget->resize(402, 300);
        loginWidget->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(loginWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_Login_in_2 = new QPushButton(loginWidget);
        btn_Login_in_2->setObjectName(QStringLiteral("btn_Login_in_2"));
        btn_Login_in_2->setMaximumSize(QSize(100, 50));

        horizontalLayout_4->addWidget(btn_Login_in_2);

        verticalSpacer_6 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_4->addItem(verticalSpacer_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btn_Register_2 = new QPushButton(loginWidget);
        btn_Register_2->setObjectName(QStringLiteral("btn_Register_2"));
        btn_Register_2->setMaximumSize(QSize(100, 50));

        horizontalLayout_4->addWidget(btn_Register_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        gridLayout_2->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(loginWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_userName_2 = new QLineEdit(loginWidget);
        lineEdit_userName_2->setObjectName(QStringLiteral("lineEdit_userName_2"));
        lineEdit_userName_2->setMaximumSize(QSize(230, 100));

        horizontalLayout_5->addWidget(lineEdit_userName_2);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(loginWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(50, 50));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_userPwd_2 = new QLineEdit(loginWidget);
        lineEdit_userPwd_2->setObjectName(QStringLiteral("lineEdit_userPwd_2"));
        lineEdit_userPwd_2->setMaximumSize(QSize(230, 100));
        lineEdit_userPwd_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_userPwd_2);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 2, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(loginWidget);

        QMetaObject::connectSlotsByName(loginWidget);
    } // setupUi

    void retranslateUi(QWidget *loginWidget)
    {
        loginWidget->setWindowTitle(QApplication::translate("loginWidget", "Form", 0));
        btn_Login_in_2->setText(QApplication::translate("loginWidget", "\347\231\273\345\275\225", 0));
        btn_Register_2->setText(QApplication::translate("loginWidget", "\346\263\250\345\206\214", 0));
        label_3->setText(QApplication::translate("loginWidget", "\350\264\246\345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("loginWidget", "\345\257\206\347\240\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class loginWidget: public Ui_loginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
