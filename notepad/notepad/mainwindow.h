#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"subtext.h"
#include<QDebug>
#include<QMdiSubWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void doProcessTriggerByNew(bool);
    void doProcessTriggerByOpen(bool);
    void doProcessTriggerByUTF_8(bool);
    void doProcessTriggerByGB2312(bool);
    void doProcessTriggerBySave(bool);
    void doProcessTriggerBySaveAs(bool);
    void doProcessTriggerByExit(bool);
    void doProcessTriggerByClose(bool);
    void doProcessTriggerByCloseAll(bool);
    void doProcessTriggerByTile(bool);
    void doProcessTriggerByCascade(bool);
    void doProcessTriggerByNext(bool);
    void doProcessTriggerByPrevious(bool);
    void doProcessTriggerByAbout(bool);
    void doProcessTriggerByAboutQt(bool);
    void doProcessTriggerByRedo(bool);
    void doProcessTriggerByUndo(bool);
    void doProcessTriggerByCut(bool);
    void doProcessTriggerByCopy(bool);
    void doProcessTriggerByPast(bool);


private:
    Ui::MainWindow *ui;
    QString codename;

    void Init();
    subText *getActiveChildForm();
};

#endif // MAINWINDOW_H
