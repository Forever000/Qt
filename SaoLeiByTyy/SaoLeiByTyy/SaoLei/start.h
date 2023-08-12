#ifndef START_H
#define START_H

#include <QWidget>
#include <QLabel>
#include "mainwindow.h"


namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();

//    QLabel bgl;
    void paintEvent(QPaintEvent *);


private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::start *ui;
    MainWindow *mw;

};

#endif // START_H
