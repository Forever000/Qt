#include "subtext.h"

subText::subText(QWidget *parent) : QTextEdit(parent)
{
    isEdit=false;
    this->filename.clear();
    myFile=new QFile(this);
}

void subText::NewFile()
{
    static int index=1;
    QString title=QString("未命名文档[%1][*]").arg(index);
    this->setWindowTitle(title);
    index++;

    //编辑后，启用星号*
    connect(this->document(),SIGNAL(contentsChanged()),
            this,SLOT(doProcessContentsChanged()));
}
void subText::OpenFile()
{
    QString filename = QFileDialog::getOpenFileName(this,"打开文件","../notepad","Text(*.cpp *.h *.docx *.txt)");
    if(filename.isEmpty())
    {
        return;
    }


    //把文件路径保存，文件设置到窗体
    //为了方便用户对当前打开的文档输入之后直接对编辑过的文档保存，将当前打开的文件名保存起来，下次直接写入
    //或者将其另存为
    this->filename=filename;

    /*第一种获取文件名的方式

    //将文件路径使用“/”分隔符切割，之后取数组里边的最后一个值，即为文件名
    QStringList list=filename.split("/");
    QString title=list.at(list.length()-1);

    */
    //第二种获取文件名的方式(自带函数自动给筛选)
    QFileInfo info(filename);
    QString title= QString("[%1][*]").arg(info.fileName());

    this->setWindowTitle(title);




    //对文件进行操作（用流式文件打开）
    myFile->setFileName(filename);
    bool ret= myFile->open(QIODevice::ReadOnly|QIODevice::Text);
    if(!ret)
    {
        QMessageBox::warning(this,"Warning","打开失败！");
        return;
    }
    QTextStream stream(myFile);
    stream.setCodec(this->codename.toLocal8Bit().data());
    while(!stream.atEnd())
    {
        QString str=stream.readLine();
        this->append(str);
    }
    //打开后，启用星号*
    connect(this->document(),SIGNAL(contentsChanged()),
            this,SLOT(doProcessContentsChanged()));
    myFile->close();

}

void subText::SetCodename(const QString codename)
{
    this->codename=codename;
}

int subText::SaveFile()
{
    int ret=-1;
    if(!isEdit)
    {
        return ret;
    }
    //this->filename为全局的变量
    //即当前的文件是新建的，文件名是空的
    if(this->filename.isEmpty())
    {
        //获取填写的文件名
        QString filename = QFileDialog::getSaveFileName(this,"保存提示！",".","Text(*.cpp *.h *.txt)");
        if(filename.isEmpty())
        {
            return ret;
        }
        this->filename=filename;
    }
    //如果对当前已经打开的文件进行操作，那么直接保存
    myFile->setFileName(this->filename);
    bool result = myFile->open(QIODevice::WriteOnly|QIODevice::Text);
    if(!result)
    {
        QMessageBox::warning(this,"Warning","文件打开失败！");
        return ret;
    }
    QTextStream stream(myFile);
    stream.setCodec(this->codename.toLocal8Bit().data());
    //将当前文字写入字符流
    stream<<this->toPlainText();
    stream.flush();
    myFile->close();
    this->setWindowModified(false);//保存后，去除已经更改的标记
    isEdit=false;
    QMessageBox::information(this,"成功提示！","保存成功！");
    ret=0;
    return ret;

}
void subText::SaveAsFile()
{
    bool isEdit=this->isEdit;
    this->isEdit=true;
    //先将当前文件路径保存，之后清空全局的，再次保存的时候就可以自定义其他的文件名了
    QString filename=this->filename;
    this->filename.clear();
    int ret=SaveFile();
    //如果未编辑、未填写文件名、文件打开失败，则将局部保存的变量名再赋给全局文件名
    if(ret<0)
    {
        this->isEdit=isEdit;
        this->filename=filename;
    }
    //如果对文件操作过但没有保存，而是直接另存为，那个当前操作的文件目录已经改变，
    //再进行保存或者操作后保存只能保存到已经另存的路径文件下

}

void subText::doProcessContentsChanged()
{
    isEdit=true;
    //This property holds whether the document shown in the window has unsaved changes.
    this->setWindowModified(true);
}

////////////////////////////////事件///////////////////////////////////////////
void subText::closeEvent(QCloseEvent *event)
{
    if(!isEdit)
    {
        return;
    }
    QMessageBox::StandardButton ret = QMessageBox::information(this,"保存提示","是否需要保存？",
                QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::Yes);
    if(ret==QMessageBox::Yes)
    {
        SaveFile();
        event->accept();
    }
    else if(ret==QMessageBox::No)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
void subText::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu *myMenu = new QMenu(this);
    QAction *redo = myMenu->addAction(QIcon(":/new/prefix1/img/帮助.png"),
                                      "恢复",this,SLOT(redo()),QKeySequence::Redo);
    redo->setEnabled(this->document()->isRedoAvailable());

    QAction *undo = myMenu->addAction(QIcon(":/new/prefix1/img/窗口.png"),
                                      "撤销",this,SLOT(undo()),QKeySequence::Undo);
    undo->setEnabled(this->document()->isUndoAvailable());

    myMenu->addSeparator();//添加分隔符

    QAction *cut = myMenu->addAction(QIcon(":/new/prefix1/img/编辑.png"),
                                     "剪贴",this,SLOT(cut()),QKeySequence::Cut);
    cut->setEnabled(this->textCursor().hasSelection());

    QAction *copy = myMenu->addAction(QIcon(":/new/prefix1/img/文件.png"),
                                      "复制",this,SLOT(copy()),QKeySequence::Copy);
    copy->setEnabled(this->textCursor().hasSelection());

    QAction *paste = myMenu->addAction(QIcon(":/new/prefix1/img/另存为.png"),
                                       "粘贴",this,SLOT(paste()),QKeySequence::Paste);

    myMenu->addSeparator();//添加分隔符

    QAction *clear = myMenu->addAction(QIcon(":/new/prefix1/img/另存为.png"),
                                       "清除",this,SLOT(clear()),QKeySequence(tr("Ctrl+D")));
    clear->setEnabled(!this->document()->isEmpty());
    QAction *selectAll = myMenu->addAction(QIcon(":/new/prefix1/img/另存为.png"),
                                           "全选",this,SLOT(selectAll()),QKeySequence::SelectAll);
    selectAll->setEnabled(!this->document()->isEmpty());


    //非模态显示菜单
    myMenu->exec(e->globalPos());//鼠标点击的当前位置
}
