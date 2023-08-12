/********************************************************************************
** Form generated from reading UI file 'dialogsetting1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTING1_H
#define UI_DIALOGSETTING1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogSetting1
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBox_4;
    QWidget *page_2;

    void setupUi(QDialog *dialogSetting1)
    {
        if (dialogSetting1->objectName().isEmpty())
            dialogSetting1->setObjectName(QStringLiteral("dialogSetting1"));
        dialogSetting1->resize(400, 300);
        stackedWidget = new QStackedWidget(dialogSetting1);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 9, 381, 281));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 80, 321, 102));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(170, 255, 127);\n"
"	\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"	\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/image/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(100, 100));
        pushButton_7->setAutoRepeat(false);

        horizontalLayout_7->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_8->setAutoFillBackground(false);
        pushButton_8->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(170, 255, 127);\n"
"	\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"	\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/img/image/addFromLocal.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(40, 40));
        pushButton_8->setAutoRepeat(false);

        horizontalLayout_7->addWidget(pushButton_8);

        buttonBox = new QDialogButtonBox(page);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 220, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget_2 = new QWidget(page);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 20, 321, 52));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(0, 35));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        comboBox_4 = new QComboBox(layoutWidget_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(100, 35));
        comboBox_4->setMaxVisibleItems(10);

        horizontalLayout_8->addWidget(comboBox_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(dialogSetting1);

        stackedWidget->setCurrentIndex(0);
        comboBox_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dialogSetting1);
    } // setupUi

    void retranslateUi(QDialog *dialogSetting1)
    {
        dialogSetting1->setWindowTitle(QApplication::translate("dialogSetting1", "Dialog", 0));
        label_7->setText(QApplication::translate("dialogSetting1", "\346\233\264\346\215\242\345\244\264\345\203\217\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("dialogSetting1", "\346\213\215\346\221\204", 0));
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("dialogSetting1", "\351\200\211\346\213\251\346\234\254\345\234\260\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QString());
        label_8->setText(QApplication::translate("dialogSetting1", "\346\220\234\347\264\242\345\274\225\346\223\216\357\274\232", 0));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("dialogSetting1", "\351\205\267\347\213\227", 0)
         << QApplication::translate("dialogSetting1", "\347\275\221\346\230\223\344\272\221", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class dialogSetting1: public Ui_dialogSetting1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTING1_H
