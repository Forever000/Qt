/********************************************************************************
** Form generated from reading UI file 'qmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMUSIC_H
#define UI_QMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMusic
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_openfile;
    QPushButton *btn_pre;
    QPushButton *btn_play;
    QPushButton *btn_next;
    QPushButton *btn_volume;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_About2;
    QPushButton *btn_User;
    QPushButton *btn_Skin;
    QPushButton *btn_Minmum;
    QPushButton *btn_Quit;
    QPushButton *btn_About;
    QListWidget *listWidget;
    QSlider *volumeSlider;
    QSlider *playProgressSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cur_lbl;
    QSpacerItem *horizontalSpacer;
    QLabel *total_lbl;

    void setupUi(QWidget *QMusic)
    {
        if (QMusic->objectName().isEmpty())
            QMusic->setObjectName(QStringLiteral("QMusic"));
        QMusic->resize(908, 587);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/systemTrayIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QMusic->setWindowIcon(icon);
        QMusic->setStyleSheet(QString::fromUtf8("/*	#QMusic\n"
"	\345\260\206\346\224\271\346\240\267\345\274\217\344\273\205\351\231\220\345\256\232\345\234\250QMusic\n"
"*/\n"
"QWidget#QMusic\n"
"{\n"
"	border-image: url(:/new/prefix1/background/default.jpg);\n"
"}\n"
"\n"
"listWidget\n"
"{\n"
"	border:none;\n"
"}\n"
""));
        widget = new QWidget(QMusic);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(310, 500, 581, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_openfile = new QPushButton(widget);
        btn_openfile->setObjectName(QStringLiteral("btn_openfile"));
        btn_openfile->setMinimumSize(QSize(50, 50));
        btn_openfile->setMaximumSize(QSize(50, 50));
        btn_openfile->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(170, 255, 127);\n"
"	\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/addFromLocal.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_openfile->setIcon(icon1);
        btn_openfile->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_openfile);

        btn_pre = new QPushButton(widget);
        btn_pre->setObjectName(QStringLiteral("btn_pre"));
        btn_pre->setMinimumSize(QSize(50, 50));
        btn_pre->setMaximumSize(QSize(50, 50));
        btn_pre->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/pre.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pre->setIcon(icon2);
        btn_pre->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_pre);

        btn_play = new QPushButton(widget);
        btn_play->setObjectName(QStringLiteral("btn_play"));
        btn_play->setMinimumSize(QSize(50, 50));
        btn_play->setMaximumSize(QSize(50, 50));
        btn_play->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(170, 255, 127);\n"
"	\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/image/pase.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon3);
        btn_play->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_play);

        btn_next = new QPushButton(widget);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        btn_next->setMinimumSize(QSize(50, 50));
        btn_next->setMaximumSize(QSize(50, 50));
        btn_next->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(170, 255, 127);\n"
"	\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon4);
        btn_next->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_next);

        btn_volume = new QPushButton(widget);
        btn_volume->setObjectName(QStringLiteral("btn_volume"));
        btn_volume->setMinimumSize(QSize(50, 50));
        btn_volume->setMaximumSize(QSize(50, 50));
        btn_volume->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(170, 255, 127);\n"
"	\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/image-hover/music-voice-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_volume->setIcon(icon5);
        btn_volume->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_volume);

        widget_2 = new QWidget(QMusic);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(630, 0, 271, 71));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_About2 = new QPushButton(widget_2);
        btn_About2->setObjectName(QStringLiteral("btn_About2"));
        btn_About2->setMinimumSize(QSize(50, 50));
        btn_About2->setMaximumSize(QSize(50, 50));
        btn_About2->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/image/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_About2->setIcon(icon6);
        btn_About2->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_About2);

        btn_User = new QPushButton(widget_2);
        btn_User->setObjectName(QStringLiteral("btn_User"));
        btn_User->setMinimumSize(QSize(50, 50));
        btn_User->setMaximumSize(QSize(50, 50));
        btn_User->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/image/singer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_User->setIcon(icon7);
        btn_User->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_User);

        btn_Skin = new QPushButton(widget_2);
        btn_Skin->setObjectName(QStringLiteral("btn_Skin"));
        btn_Skin->setMinimumSize(QSize(50, 50));
        btn_Skin->setMaximumSize(QSize(50, 50));
        btn_Skin->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/image/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Skin->setIcon(icon8);
        btn_Skin->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_Skin);

        btn_Minmum = new QPushButton(widget_2);
        btn_Minmum->setObjectName(QStringLiteral("btn_Minmum"));
        btn_Minmum->setMinimumSize(QSize(50, 50));
        btn_Minmum->setMaximumSize(QSize(50, 50));
        btn_Minmum->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/image/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Minmum->setIcon(icon9);
        btn_Minmum->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_Minmum);

        btn_Quit = new QPushButton(widget_2);
        btn_Quit->setObjectName(QStringLiteral("btn_Quit"));
        btn_Quit->setMinimumSize(QSize(50, 50));
        btn_Quit->setMaximumSize(QSize(50, 50));
        btn_Quit->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/image/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Quit->setIcon(icon10);
        btn_Quit->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_Quit);

        btn_About = new QPushButton(QMusic);
        btn_About->setObjectName(QStringLiteral("btn_About"));
        btn_About->setGeometry(QRect(10, 0, 50, 50));
        btn_About->setMinimumSize(QSize(50, 50));
        btn_About->setMaximumSize(QSize(50, 50));
        btn_About->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/prefix1/image/Title.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_About->setIcon(icon11);
        btn_About->setIconSize(QSize(50, 60));
        listWidget = new QListWidget(QMusic);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 70, 311, 511));
        listWidget->setStyleSheet(QStringLiteral("background: transparent;"));
        volumeSlider = new QSlider(QMusic);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(790, 340, 22, 160));
        volumeSlider->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"border:none;"));
        volumeSlider->setValue(99);
        volumeSlider->setOrientation(Qt::Vertical);
        playProgressSlider = new QSlider(QMusic);
        playProgressSlider->setObjectName(QStringLiteral("playProgressSlider"));
        playProgressSlider->setGeometry(QRect(320, 470, 451, 22));
        playProgressSlider->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(QMusic);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(320, 450, 451, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cur_lbl = new QLabel(layoutWidget);
        cur_lbl->setObjectName(QStringLiteral("cur_lbl"));
        cur_lbl->setMinimumSize(QSize(80, 0));
        QFont font;
        font.setPointSize(10);
        cur_lbl->setFont(font);
        cur_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(cur_lbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        total_lbl = new QLabel(layoutWidget);
        total_lbl->setObjectName(QStringLiteral("total_lbl"));
        total_lbl->setMinimumSize(QSize(80, 0));
        total_lbl->setFont(font);
        total_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(total_lbl);


        retranslateUi(QMusic);

        QMetaObject::connectSlotsByName(QMusic);
    } // setupUi

    void retranslateUi(QWidget *QMusic)
    {
        QMusic->setWindowTitle(QApplication::translate("QMusic", "\344\272\221\351\237\263\344\271\220", 0));
        btn_openfile->setText(QString());
        btn_pre->setText(QString());
        btn_play->setText(QString());
        btn_next->setText(QString());
        btn_volume->setText(QString());
        btn_About2->setText(QString());
        btn_User->setText(QString());
        btn_Skin->setText(QString());
        btn_Minmum->setText(QString());
        btn_Quit->setText(QString());
        btn_About->setText(QString());
        cur_lbl->setText(QApplication::translate("QMusic", "00\357\274\23200", 0));
        total_lbl->setText(QApplication::translate("QMusic", "00\357\274\23200", 0));
    } // retranslateUi

};

namespace Ui {
    class QMusic: public Ui_QMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMUSIC_H
