/********************************************************************************
** Form generated from reading UI file 'chessform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSFORM_H
#define UI_CHESSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessForm
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QLabel *lbl1;
    QLCDNumber *lcdNumber1;
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *lbl2;
    QLCDNumber *lcdNumber2;
    QFrame *frame_3;
    QComboBox *cbox_item;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_pvp;
    QPushButton *btn_pvc;
    QPushButton *btn_pvn;

    void setupUi(QWidget *chessForm)
    {
        if (chessForm->objectName().isEmpty())
            chessForm->setObjectName(QStringLiteral("chessForm"));
        chessForm->resize(653, 430);
        gridLayout_2 = new QGridLayout(chessForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_2 = new QFrame(chessForm);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 200));
        frame_2->setMaximumSize(QSize(150, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lbl1 = new QLabel(frame_2);
        lbl1->setObjectName(QStringLiteral("lbl1"));
        lbl1->setGeometry(QRect(30, 10, 91, 91));
        lcdNumber1 = new QLCDNumber(frame_2);
        lcdNumber1->setObjectName(QStringLiteral("lcdNumber1"));
        lcdNumber1->setGeometry(QRect(30, 110, 101, 101));
        lcdNumber1->setDigitCount(2);

        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        frame = new QFrame(chessForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 200));
        frame->setMaximumSize(QSize(150, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lbl2 = new QLabel(frame);
        lbl2->setObjectName(QStringLiteral("lbl2"));
        lbl2->setGeometry(QRect(30, 10, 91, 91));
        lcdNumber2 = new QLCDNumber(frame);
        lcdNumber2->setObjectName(QStringLiteral("lcdNumber2"));
        lcdNumber2->setGeometry(QRect(30, 110, 101, 101));
        lcdNumber2->setDigitCount(2);

        gridLayout_2->addWidget(frame, 0, 2, 1, 1);

        frame_3 = new QFrame(chessForm);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(500, 50));
        frame_3->setMaximumSize(QSize(16777215, 150));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        cbox_item = new QComboBox(frame_3);
        cbox_item->setObjectName(QStringLiteral("cbox_item"));
        cbox_item->setGeometry(QRect(20, 50, 151, 51));
        widget = new QWidget(frame_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(211, 48, 391, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_pvp = new QPushButton(widget);
        btn_pvp->setObjectName(QStringLiteral("btn_pvp"));
        btn_pvp->setMinimumSize(QSize(0, 51));

        horizontalLayout->addWidget(btn_pvp);

        btn_pvc = new QPushButton(widget);
        btn_pvc->setObjectName(QStringLiteral("btn_pvc"));
        btn_pvc->setMinimumSize(QSize(0, 51));

        horizontalLayout->addWidget(btn_pvc);

        btn_pvn = new QPushButton(widget);
        btn_pvn->setObjectName(QStringLiteral("btn_pvn"));
        btn_pvn->setMinimumSize(QSize(0, 51));

        horizontalLayout->addWidget(btn_pvn);


        gridLayout_2->addWidget(frame_3, 1, 0, 1, 3);


        retranslateUi(chessForm);

        QMetaObject::connectSlotsByName(chessForm);
    } // setupUi

    void retranslateUi(QWidget *chessForm)
    {
        chessForm->setWindowTitle(QApplication::translate("chessForm", "Form", 0));
        lbl1->setText(QApplication::translate("chessForm", "TextLabel", 0));
        lbl2->setText(QApplication::translate("chessForm", "TextLabel", 0));
        btn_pvp->setText(QApplication::translate("chessForm", "\344\272\272\344\272\272\345\257\271\346\210\230", 0));
        btn_pvc->setText(QApplication::translate("chessForm", "\344\272\272\346\234\272\345\257\271\346\210\230", 0));
        btn_pvn->setText(QApplication::translate("chessForm", "\347\275\221\347\273\234\345\257\271\346\210\230", 0));
    } // retranslateUi

};

namespace Ui {
    class chessForm: public Ui_chessForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSFORM_H
