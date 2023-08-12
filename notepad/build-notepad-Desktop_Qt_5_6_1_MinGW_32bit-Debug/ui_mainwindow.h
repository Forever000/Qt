/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *action_Redo;
    QAction *action_Undo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Past;
    QAction *action_GB2312;
    QAction *action_UTF_8;
    QAction *action_Close;
    QAction *action_CloseAll;
    QAction *action_Tile;
    QAction *action_Cascade;
    QAction *action_Next;
    QAction *action_Previous;
    QAction *action_About;
    QAction *action_AboutQt;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_S;
    QMenu *menu_W;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(547, 425);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/\346\226\260\345\273\272\346\226\207\344\273\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/img/\346\211\223\345\274\200\346\226\207\344\273\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/img/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_SaveAs = new QAction(MainWindow);
        action_SaveAs->setObjectName(QStringLiteral("action_SaveAs"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/img/\345\217\246\345\255\230\344\270\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveAs->setIcon(icon3);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/img/\351\200\200\345\207\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon4);
        action_Redo = new QAction(MainWindow);
        action_Redo->setObjectName(QStringLiteral("action_Redo"));
        action_Redo->setIcon(icon4);
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        action_Undo->setIcon(icon4);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/img/\345\270\256\345\212\251.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon5);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        action_Copy->setIcon(icon);
        action_Past = new QAction(MainWindow);
        action_Past->setObjectName(QStringLiteral("action_Past"));
        action_Past->setIcon(icon1);
        action_GB2312 = new QAction(MainWindow);
        action_GB2312->setObjectName(QStringLiteral("action_GB2312"));
        action_UTF_8 = new QAction(MainWindow);
        action_UTF_8->setObjectName(QStringLiteral("action_UTF_8"));
        action_Close = new QAction(MainWindow);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        action_Close->setIcon(icon5);
        action_CloseAll = new QAction(MainWindow);
        action_CloseAll->setObjectName(QStringLiteral("action_CloseAll"));
        action_CloseAll->setIcon(icon1);
        action_Tile = new QAction(MainWindow);
        action_Tile->setObjectName(QStringLiteral("action_Tile"));
        action_Tile->setIcon(icon1);
        action_Cascade = new QAction(MainWindow);
        action_Cascade->setObjectName(QStringLiteral("action_Cascade"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/img/\346\226\207\344\273\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cascade->setIcon(icon6);
        action_Next = new QAction(MainWindow);
        action_Next->setObjectName(QStringLiteral("action_Next"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/img/\347\252\227\345\217\243.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Next->setIcon(icon7);
        action_Previous = new QAction(MainWindow);
        action_Previous->setObjectName(QStringLiteral("action_Previous"));
        action_Previous->setIcon(icon);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_About->setIcon(icon5);
        action_AboutQt = new QAction(MainWindow);
        action_AboutQt->setObjectName(QStringLiteral("action_AboutQt"));
        action_AboutQt->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 547, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_S = new QMenu(menu_E);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QStringLiteral("menu_W"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu->addAction(action_New);
        menu->addAction(action_Open);
        menu->addSeparator();
        menu->addAction(action_Save);
        menu->addAction(action_SaveAs);
        menu->addSeparator();
        menu->addAction(action_Exit);
        menu_E->addAction(action_Redo);
        menu_E->addAction(action_Undo);
        menu_E->addSeparator();
        menu_E->addAction(action_Cut);
        menu_E->addAction(action_Copy);
        menu_E->addAction(action_Past);
        menu_E->addSeparator();
        menu_E->addAction(menu_S->menuAction());
        menu_S->addAction(action_GB2312);
        menu_S->addAction(action_UTF_8);
        menu_W->addAction(action_Close);
        menu_W->addAction(action_CloseAll);
        menu_W->addSeparator();
        menu_W->addAction(action_Tile);
        menu_W->addAction(action_Cascade);
        menu_W->addSeparator();
        menu_W->addAction(action_Next);
        menu_W->addAction(action_Previous);
        menu_H->addAction(action_About);
        menu_H->addAction(action_AboutQt);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_SaveAs);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Exit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Redo);
        mainToolBar->addAction(action_Undo);
        mainToolBar->addAction(action_Cut);
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(action_Past);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", 0));
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266(&O)", 0));
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
        action_SaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", 0));
        action_Exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&R)", 0));
        action_Redo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&R)", 0));
        action_Undo->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215(&U)", 0));
        action_Cut->setText(QApplication::translate("MainWindow", "\345\211\252\350\264\264(&T)", 0));
        action_Copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", 0));
        action_Past->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", 0));
        action_GB2312->setText(QApplication::translate("MainWindow", "GB2312", 0));
        action_UTF_8->setText(QApplication::translate("MainWindow", "UTF-8", 0));
        action_Close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&O)", 0));
        action_CloseAll->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211(&A)", 0));
        action_Tile->setText(QApplication::translate("MainWindow", "\345\271\263\351\223\272(&T)", 0));
        action_Cascade->setText(QApplication::translate("MainWindow", "\345\261\202\345\217\240(&C)", 0));
        action_Next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(&N)", 0));
        action_Previous->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252(&P)", 0));
        action_About->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", 0));
        action_AboutQt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216QT(&O)", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        menu_S->setTitle(QApplication::translate("MainWindow", "\347\274\226\347\240\201(&S)", 0));
        menu_W->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243(&W)", 0));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
