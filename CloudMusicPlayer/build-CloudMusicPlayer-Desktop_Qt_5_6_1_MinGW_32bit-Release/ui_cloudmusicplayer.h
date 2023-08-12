/********************************************************************************
** Form generated from reading UI file 'cloudmusicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDMUSICPLAYER_H
#define UI_CLOUDMUSICPLAYER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloudMusicPlayer
{
public:
    QListWidget *listWidget;
    QSlider *volumeSlider;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_Listening;
    QPushButton *btn_Setting;
    QPushButton *btn_About2;
    QPushButton *btn_User;
    QPushButton *btn_Skin;
    QPushButton *btn_Minmum;
    QPushButton *btn_Quit;
    QPushButton *btn_About;
    QSlider *playProgressSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cur_lbl;
    QSpacerItem *horizontalSpacer;
    QLabel *total_lbl;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_openfile;
    QPushButton *btn_pre;
    QPushButton *btn_play;
    QPushButton *btn_next;
    QPushButton *btn_volume;
    QTableWidget *tableWidget;
    QLineEdit *ledit_songName;
    QPushButton *btn_search;

    void setupUi(QWidget *CloudMusicPlayer)
    {
        if (CloudMusicPlayer->objectName().isEmpty())
            CloudMusicPlayer->setObjectName(QStringLiteral("CloudMusicPlayer"));
        CloudMusicPlayer->resize(919, 598);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/image/systemTrayIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloudMusicPlayer->setWindowIcon(icon);
        CloudMusicPlayer->setStyleSheet(QString::fromUtf8("/*	#QMusic\n"
"	\345\260\206\346\224\271\346\240\267\345\274\217\344\273\205\351\231\220\345\256\232\345\234\250QMusic\n"
"*/\n"
"QWidget#CloudMusicPlayer\n"
"{\n"
"	border-image: url(:/new/prefix1/img/background/default.jpg);\n"
"border-radius:10px;\n"
"}\n"
"\n"
"listWidget\n"
"{\n"
"	border:none;\n"
"}"));
        listWidget = new QListWidget(CloudMusicPlayer);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(1, 78, 291, 501));
        listWidget->setStyleSheet(QLatin1String("QListWidget\n"
"{background: transparent;}"));
        volumeSlider = new QSlider(CloudMusicPlayer);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(820, 393, 22, 121));
        volumeSlider->setStyleSheet(QStringLiteral(""));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Vertical);
        widget_2 = new QWidget(CloudMusicPlayer);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(469, 1, 441, 72));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_Listening = new QPushButton(widget_2);
        btn_Listening->setObjectName(QStringLiteral("btn_Listening"));
        btn_Listening->setMinimumSize(QSize(50, 50));
        btn_Listening->setMaximumSize(QSize(50, 50));
        btn_Listening->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        icon1.addFile(QStringLiteral(":/new/prefix1/img/image/music-playing.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Listening->setIcon(icon1);
        btn_Listening->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_Listening);

        btn_Setting = new QPushButton(widget_2);
        btn_Setting->setObjectName(QStringLiteral("btn_Setting"));
        btn_Setting->setMinimumSize(QSize(50, 50));
        btn_Setting->setMaximumSize(QSize(50, 50));
        btn_Setting->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        icon2.addFile(QStringLiteral(":/new/prefix1/img/image/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Setting->setIcon(icon2);
        btn_Setting->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_Setting);

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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/img/image/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_About2->setIcon(icon3);
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
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/img/image/singer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_User->setIcon(icon4);
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
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/img/image/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Skin->setIcon(icon5);
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
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/img/image/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Minmum->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/img/image/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Quit->setIcon(icon7);
        btn_Quit->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(btn_Quit);

        btn_About = new QPushButton(CloudMusicPlayer);
        btn_About->setObjectName(QStringLiteral("btn_About"));
        btn_About->setGeometry(QRect(1, 12, 50, 50));
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
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/img/image/MusicListItem.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_About->setIcon(icon8);
        btn_About->setIconSize(QSize(50, 60));
        playProgressSlider = new QSlider(CloudMusicPlayer);
        playProgressSlider->setObjectName(QStringLiteral("playProgressSlider"));
        playProgressSlider->setGeometry(QRect(306, 491, 491, 22));
        playProgressSlider->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(CloudMusicPlayer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 450, 501, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
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

        widget = new QWidget(CloudMusicPlayer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(300, 520, 621, 72));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
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
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/img/image/addFromLocal.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_openfile->setIcon(icon9);
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
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/img/image/pre.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pre->setIcon(icon10);
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
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/prefix1/img/image/pase.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon11);
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
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/prefix1/img/image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon12);
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
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/new/prefix1/img/image/music-voice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_volume->setIcon(icon13);
        btn_volume->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(btn_volume);

        tableWidget = new QTableWidget(CloudMusicPlayer);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        if (tableWidget->rowCount() < 30)
            tableWidget->setRowCount(30);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(300, 80, 601, 361));
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QLatin1String("QTableWidget\n"
"{background: transparent;}\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(30);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        ledit_songName = new QLineEdit(CloudMusicPlayer);
        ledit_songName->setObjectName(QStringLiteral("ledit_songName"));
        ledit_songName->setGeometry(QRect(181, 25, 221, 31));
        ledit_songName->setMinimumSize(QSize(0, 0));
        ledit_songName->setStyleSheet(QLatin1String("border:none;\n"
"border-radius:10px;"));
        ledit_songName->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        ledit_songName->setEchoMode(QLineEdit::Normal);
        btn_search = new QPushButton(CloudMusicPlayer);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        btn_search->setGeometry(QRect(370, 25, 31, 31));
        btn_search->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background:transparent;\n"
"	border:none;\n"
"}\n"
""));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/new/prefix1/img/image/sliderHandle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search->setIcon(icon14);
        btn_search->setIconSize(QSize(40, 40));
        listWidget->raise();
        widget_2->raise();
        btn_About->raise();
        playProgressSlider->raise();
        layoutWidget->raise();
        widget->raise();
        tableWidget->raise();
        volumeSlider->raise();
        ledit_songName->raise();
        btn_search->raise();

        retranslateUi(CloudMusicPlayer);

        QMetaObject::connectSlotsByName(CloudMusicPlayer);
    } // setupUi

    void retranslateUi(QWidget *CloudMusicPlayer)
    {
        CloudMusicPlayer->setWindowTitle(QApplication::translate("CloudMusicPlayer", "CloudMusicPlayer", 0));
        btn_Listening->setText(QString());
        btn_Setting->setText(QString());
        btn_About2->setText(QString());
        btn_User->setText(QString());
        btn_Skin->setText(QString());
        btn_Minmum->setText(QString());
        btn_Quit->setText(QString());
        btn_About->setText(QString());
        cur_lbl->setText(QApplication::translate("CloudMusicPlayer", "00\357\274\23200", 0));
        total_lbl->setText(QApplication::translate("CloudMusicPlayer", "00\357\274\23200", 0));
        btn_openfile->setText(QString());
        btn_pre->setText(QString());
        btn_play->setText(QString());
        btn_next->setText(QString());
        btn_volume->setText(QString());
        ledit_songName->setText(QApplication::translate("CloudMusicPlayer", "\346\235\216\345\201\245", 0));
        btn_search->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CloudMusicPlayer: public Ui_CloudMusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDMUSICPLAYER_H
