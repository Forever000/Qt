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
    QPushButton *btn_sure;
    QLabel *label;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(635, 468);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_sure = new QPushButton(Widget);
        btn_sure->setObjectName(QStringLiteral("btn_sure"));
        btn_sure->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(btn_sure, 0, 2, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 3);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 40));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 0, 1, 3);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        btn_sure->setText(QApplication::translate("Widget", "Go", 0));
        label->setText(QApplication::translate("Widget", "URL", 0));
        lineEdit->setText(QApplication::translate("Widget", "http://v9-xg-web-s.ixigua.com/0c2d63e537e1e5d7f03e21b2949e2ed1/629f1038/video/tos/cn/tos-cn-ve-4-alinc2/0c23367de19f4a75b25f7d97cd728247/?a=1768&ch=0&cr=0&dr=0&er=0&lr=default&cd=0%7C0%7C0%7C0&cv=1&br=351&bt=351&cs=0&ds=1&ft=FnzETNN6VkJwbIMmq8dzJLeOYZlcaHfyF2bLNckW0iZm&mime_type=video_mp4&qs=0&rc=N2k5NDozPGgzZmczZDtnZkBpMzl0NDg6Zm5kOjMzNDczM0BgYTNjNWJgXzExLTQ1MTEvYSNeamJycjQwM25gLS1kLTBzcw%3D%3D&l=2022060715343301015801819601067381", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
