#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

////////////////////function/////////////////////////////
void MainWindow::Init()
{
    codename="UTF-8";
    //文件
    connect(ui->action_New,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByNew(bool)));
    connect(ui->action_Open,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByOpen(bool)));
    connect(ui->action_UTF_8,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByUTF_8(bool)));
    connect(ui->action_GB2312,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByGB2312(bool)));
    connect(ui->action_Save,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerBySave(bool)));
    connect(ui->action_SaveAs,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerBySaveAs(bool)));
    connect(ui->action_Exit,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByExit(bool)));
    //编辑
    connect(ui->action_Redo,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByRedo(bool)));
    connect(ui->action_Undo,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByUndo(bool)));
    connect(ui->action_Cut,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByCut(bool)));
    connect(ui->action_Copy,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByCopy(bool)));
    connect(ui->action_Past,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByPast(bool)));

    //窗口
    connect(ui->action_Close,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByClose(bool)));
    connect(ui->action_CloseAll,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByCloseAll(bool)));
    connect(ui->action_Tile,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByTile(bool)));//平铺
    connect(ui->action_Cascade,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByCascade(bool)));//层叠
    connect(ui->action_New,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByNext(bool)));
    connect(ui->action_Previous,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByPrevious(bool)));

    //帮助
    connect(ui->action_About,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByAbout(bool)));
    connect(ui->action_AboutQt,SIGNAL(triggered(bool)),this,SLOT(doProcessTriggerByAboutQt(bool)));
}




///////////////////////function end///////////////////////////////
////////////////////event/////////////////////////////
void MainWindow::closeEvent(QCloseEvent *)
{
    doProcessTriggerByExit(false);
}



///////////////////////event end///////////////////////////////
////////////////////slots/////////////////////////////

void MainWindow::doProcessTriggerByNew(bool)
{
    qDebug()<<"sss"<<endl;
    subText *subWindow=new subText();
    //在mdiArea中添加一个子窗体，设置编码方式
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->SetCodename(codename);
    //新建文件的格式设置
    subWindow->NewFile();

    subWindow->show();
}
void MainWindow::doProcessTriggerByOpen(bool)
{
    subText *subWindow=new subText();
    ui->mdiArea->addSubWindow(subWindow);
    //OpenFile在自定义类文件中，在MainWindow类中包含了自定义类名字，因此可以使用该函数
    subWindow->SetCodename(codename);
    subWindow->OpenFile();

    subWindow->show();
}
void MainWindow::doProcessTriggerByUTF_8(bool)
{
    this->codename="UTF-8";
}
void MainWindow::doProcessTriggerByGB2312(bool)
{
    //GB高版本可以兼容低版本2312
    this->codename="GB18030";
}
void MainWindow::doProcessTriggerBySave(bool)
{
    //获取当前激活的子窗体，获取子窗体中的文本，调用自定义的保存文件函数将其保存
    QMdiSubWindow *subWin= ui->mdiArea->activeSubWindow();
    //若当前没有窗体打开/激活，那么终止
    if(subWin == NULL)
        return;
    QWidget *wid = subWin->widget();
    if(wid == NULL)
        return;
    subText *sub=(subText *)wid;
    if(sub == NULL)
        return;
    sub->SaveFile();
}
void MainWindow::doProcessTriggerBySaveAs(bool)
{
    //获取当前激活的子窗体，获取子窗体中的文本，调用自定义的保存文件函数将其保存
    QMdiSubWindow *subWin= ui->mdiArea->activeSubWindow();
    //若当前没有窗体打开/激活，那么终止
    if(subWin == NULL)
        return;
    QWidget *wid = subWin->widget();
    if(wid == NULL)
        return;
    subText *sub=(subText *)wid;
    if(sub == NULL)
        return;
    sub->SaveAsFile();
}
void MainWindow::doProcessTriggerByExit(bool)
{
    ui->mdiArea->closeAllSubWindows();//关闭所有子窗体
    this->close();//关闭主窗体
    //MainWindow::close();
}
//编辑
subText *MainWindow::getActiveChildForm()
{
    subText *sub=NULL;
    //获取当前激活的窗体
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();
    if(subWin==NULL)
    {
        return sub;
    }
    //获取激活的窗体的widget
    QWidget *wid = subWin->widget();
    if(wid==NULL)
    {
        return sub;
    }
    sub=(subText *)wid;
    return sub;
}

void MainWindow::doProcessTriggerByRedo(bool)
{
    subText *sub=getActiveChildForm();
    if(sub!=NULL)
    {
        sub->redo();
    }
}
void MainWindow::doProcessTriggerByUndo(bool)
{
    subText *sub=getActiveChildForm();
    if(sub!=NULL)
    {
        sub->undo();
    }
}
void MainWindow::doProcessTriggerByCut(bool)
{
    subText *sub=getActiveChildForm();
    if(sub!=NULL)
    {
        sub->cut();
    }
}
void MainWindow::doProcessTriggerByCopy(bool)
{
    subText *sub=getActiveChildForm();
    if(sub!=NULL)
    {
        sub->copy();
    }
}
void MainWindow::doProcessTriggerByPast(bool)
{
    subText *sub=getActiveChildForm();
    if(sub!=NULL)
    {
        sub->paste();
    }
}


//窗口
void MainWindow::doProcessTriggerByClose(bool)
{
    ui->mdiArea->closeActiveSubWindow();
}
void MainWindow::doProcessTriggerByCloseAll(bool)
{
    ui->mdiArea->closeAllSubWindows();
}
void MainWindow::doProcessTriggerByTile(bool)
{
    ui->mdiArea->tileSubWindows();
}
void MainWindow::doProcessTriggerByCascade(bool)
{
    ui->mdiArea->cascadeSubWindows();
}
void MainWindow::doProcessTriggerByNext(bool)
{
    ui->mdiArea->activateNextSubWindow();
}
void MainWindow::doProcessTriggerByPrevious(bool)
{
    ui->mdiArea->activatePreviousSubWindow();
}
//帮助
void MainWindow::doProcessTriggerByAbout(bool)
{
    QString str="This is a interesting notepad";
    QMessageBox::about(this,"About",str);
}
void MainWindow::doProcessTriggerByAboutQt(bool)
{
    QMessageBox::aboutQt(this,"关于Qt");
}

///////////////////////slots end///////////////////////////////
