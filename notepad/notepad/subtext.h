#ifndef SUBTEXT_H
#define SUBTEXT_H

#include <QWidget>
#include<QTextEdit>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
#include<QCloseEvent>
#include<QContextMenuEvent>
#include<QMenu>

class subText : public QTextEdit
{
    Q_OBJECT
public:
    explicit subText(QWidget *parent = 0);

    void NewFile();
    void OpenFile();
    void SetCodename(const QString codename);//设置编码方式
    int SaveFile();
    void SaveAsFile();

signals:

protected:
    //子窗体内部的关闭事件
    void closeEvent(QCloseEvent *event);
    //重写鼠标菜单事件
    void contextMenuEvent(QContextMenuEvent *e);
private slots:
    //内容改变
    void doProcessContentsChanged();
private:
    QString filename;
    QFile *myFile;
    QString codename;
    bool isEdit;
};

#endif // SUBTEXT_H
