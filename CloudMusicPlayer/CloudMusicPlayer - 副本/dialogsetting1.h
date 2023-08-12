#ifndef DIALOGSETTING1_H
#define DIALOGSETTING1_H

#include <QDialog>
#include<QCameraViewfinder>
#include<QCamera>
#include<QAbstractButton>

namespace Ui {
class dialogSetting1;
}

class dialogSetting1 : public QDialog
{
    Q_OBJECT

public:
    explicit dialogSetting1(QWidget *parent = 0);
    ~dialogSetting1();
    void Init();

signals:
    int engineChose(int index);

private slots:
    void doProcessbuttonBoxClick(QAbstractButton*);
    void doProcessTakePhoto();
    void doProcessOpenPic();
//    void doProcesscurrentIndexChanged(int);

private:
    Ui::dialogSetting1 *ui;

    QDialog *camdialog;
    QCamera *camera;
    QCameraViewfinder *viewfinder;


};

#endif // DIALOGSETTING1_H
