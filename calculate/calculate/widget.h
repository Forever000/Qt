#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_dian_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_jia_clicked();

    void on_pushButton_jian_clicked();

    void on_pushButton_cheng_clicked();

    void on_pushButton_chu_clicked();

    void on_pushButton_deng_clicked();

private:
    Ui::Widget *ui;

    QString a;
    QStringList b;
};

#endif // WIDGET_H
