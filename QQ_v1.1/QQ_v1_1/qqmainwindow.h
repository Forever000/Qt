#ifndef QQMAINWINDOW_H
#define QQMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class QQMainWindow;
}

class QQMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QQMainWindow(QWidget *parent = 0);
    ~QQMainWindow();

private:
    Ui::QQMainWindow *ui;
};

#endif // QQMAINWINDOW_H
