#include "qmusic.h"
#include "ui_qmusic.h"
#include<QDebug>
#include<QFileDialog>
#include<QMessageBox>
#include<QStandardPaths>
#include<QtConcurrent>

QMusic::QMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMusic)
{
    ui->setupUi(this);
    Init();
}

QMusic::~QMusic()
{
    delete ui;
}
void QMusic::Init()
{
    //系统托盘初始化
    InitSystemTrayIcon();

    //窗口设置圆角后，会出现留白，需要添加以下代码
    setAttribute(Qt::WA_TranslucentBackground, true);
    //去除标题栏（发现去除标题栏之后无法移动窗口，此时需要重写鼠标事件）
    setWindowFlags(Qt::FramelessWindowHint);

    mediaPlayer=new QMediaPlayer(this);
    ui->volumeSlider->setVisible(false);//初始化状态下音乐滑块不可见
    //按钮绑定
    connect(ui->btn_openfile,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_openfileClick()));
    connect(ui->btn_pre,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_preClick()));
    connect(ui->btn_play,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_playClick()));
    connect(ui->btn_next,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_nextClick()));
    connect(ui->btn_volume,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_volumeClick()));
    connect(ui->btn_About,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_AboutClick()));
    connect(ui->btn_About2,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_About2Click()));
    connect(ui->btn_Minmum,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_MinmumClick()));
    connect(ui->btn_Quit,SIGNAL(clicked(bool)),this,SLOT(doProcess_btn_QuitClick()));
    //listWidget鼠标双击事件
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(doProcessitemDoubleClicked(QListWidgetItem*)));

    //连接到volumeslider，获取其实时拖动的值，实时设置音乐的音量
    connect(ui->volumeSlider,SIGNAL(valueChanged(int)),this,SLOT(doProcessVolumevalueChanged(int)));

    //mediaPlayer总时长改变，同步至total_lbl
    connect(mediaPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(doProcessdurationChanged(qint64)));

    //mediaPlayer当前播放时长改变，同步至cur_lbl
    connect(mediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(doProcesspositionChanged(qint64)));

    //playProgressSlider被拖动时，音乐播放进度改变
    connect(ui->playProgressSlider,&QSlider::sliderMoved,mediaPlayer,&QMediaPlayer::setPosition);

    //实现换肤功能
    connect(ui->btn_Skin,SIGNAL(clicked(bool)),this,SLOT(doProcessbtn_SkinClick()));



    //实现登录功能，将登录功能加载到当前页面，登录之后显示用户所存储的歌曲

//    mediaPlayer->setAudioRole();
//    player = new QMediaPlayer;
//    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    QUrl fileUrl=":/Users/gys/Music/Cash Cash _ Christina Perri - Hero.mp3";

}
void QMusic::doProcess_btn_openfileClick()
{
    qDebug()<<"1"<<endl;
    QStringList fileNames = QFileDialog::getOpenFileNames(this,"请选择音乐所在目录","C:\\Users\\gys\\Music",tr("Music (*.mp3)"));//打开已经存在的目录
    qDebug()<<"fileNames"<<fileNames<<endl;
    ui->listWidget->addItems(fileNames);
    //音乐导入之后默认选择第0行作为选中行
    if(fileNames.length()!=0)
    {
        ui->listWidget->setCurrentRow(0);
        QModelIndex test=ui->listWidget->currentIndex();
        ui->listWidget->clicked(test);
    }
    else
    {
        QMessageBox::warning(this,"warning","----未选中文件----\n请重新添加音乐列表！");
        return;
    }

}
void QMusic::doProcess_btn_preClick()
{
    qDebug()<<"2"<<endl;
    //如果当前列表为空
    if(ui->listWidget->count()!=0)//避免出现listWidget中的数据个数为0导致的程序崩溃
    {
        int currentNum = ui->listWidget->currentRow();//当前所在行号
        int rowcount = ui->listWidget->model()->rowCount();//当前列表的总行数
        qDebug()<<rowcount<<currentNum<<endl;
        if(currentNum==0)
        {
            ui->listWidget->setCurrentRow(rowcount-1);//如果当前歌曲为第0行，则点击上一曲之后，设置当前播放歌曲为最后一个
        }
        else
        {
            ui->listWidget->setCurrentRow(currentNum-1);
        }
    //    ui->listWidget->setCurrentRow((currentNum-1)%rowcount);
        QModelIndex test=ui->listWidget->currentIndex();
        ui->listWidget->clicked(test);
        mediaPlayer->setMedia(QUrl::fromLocalFile(ui->listWidget->currentItem()->text()));
        mediaPlayer->setVolume(ui->volumeSlider->value());
        ui->btn_play->setIcon(QIcon(":/new/prefix1/image/play.png"));
        mediaPlayer->play();
        m_IsPlaying=true;
    }
    else
    {
        qDebug()<<"当前列表为空！"<<endl;
        QMessageBox::warning(this,"warning","----当前列表为空----\n请先添加音乐列表！");
        return;
    }
}
void QMusic::doProcess_btn_playClick()
{
    qDebug()<<"3"<<endl;
    //如果当前正在播放，则设置播放停止，否则，播放选中音乐
//    auto list= ui->listWidget->selectedItems();
//    qDebug()<<"list"<<ui->listWidget->currentItem()->text()<<endl;

    switch (mediaPlayer->state())//获取当前播放状态
    {
        //停止状态时，点击播放
        case QMediaPlayer::StoppedState:
        {
            if(ui->listWidget->count()!=0)//避免出现listWidget中的数据个数为0导致的程序崩溃
            {
                //判断当前是否有选中的item(将该问题转化为，文件添加到列表之后，默认选择第一个item，此时，即可避免未选中item，直接播放导致的崩溃)
                mediaPlayer->setMedia(QUrl::fromLocalFile(ui->listWidget->currentItem()->text()));
                mediaPlayer->setVolume(ui->volumeSlider->value());
                ui->btn_play->setIcon(QIcon(":/new/prefix1/image/play.png"));
                mediaPlayer->play();
                m_IsPlaying=true;

            }
            else
            {
        //            qDebug()<<"当前列表为空！"<<endl;
                QMessageBox::warning(this,"warning","----当前列表为空----\n请先添加音乐列表！");
                return;
            }
            break;
        }
        //正在播放时，点击停止
        case QMediaPlayer::PlayingState:
        {
            ui->btn_play->setIcon(QIcon(":/new/prefix1/image/pase.png"));
            mediaPlayer->pause();
            m_IsPlaying = false;//设置播放状态为非停止，便于下次调用
            break;
        }
        //暂停状态,继续播放
        case QMediaPlayer::PausedState:
        {
            ui->btn_play->setIcon(QIcon(":/new/prefix1/image/play.png"));
            mediaPlayer->play();
            m_IsPlaying=true;
            break;
        }
    }
    /*
    if(!m_IsPlaying)//如果当前播放停止，则进行选择播放
    {
        if(ui->listWidget->count()!=0)//避免出现listWidget中的数据个数为0导致的程序崩溃
        {
            //判断当前是否有选中的item(将该问题转化为，文件添加到列表之后，默认选择第一个item，此时，即可避免未选中item，直接播放导致的崩溃)
            mediaPlayer->setMedia(QUrl::fromLocalFile(ui->listWidget->currentItem()->text()));
            mediaPlayer->setVolume(ui->volumeSlider->value());
            ui->btn_play->setIcon(QIcon(":/new/prefix1/image/play.png"));
            mediaPlayer->play();
            m_IsPlaying=true;

        }
        else
        {
//            qDebug()<<"当前列表为空！"<<endl;
            QMessageBox::warning(this,"warning","----当前列表为空----\n请先添加音乐列表！");
            return;
        }
    }
    else
    {
        //如果当前正在播放，则播放停止
        ui->btn_play->setIcon(QIcon(":/new/prefix1/image/pase.png"));
        mediaPlayer->pause();
        m_IsPlaying = false;//设置播放状态为非停止，便于下次调用
    }
    */
}

void QMusic::doProcess_btn_nextClick()
{
    qDebug()<<"4"<<endl;
    //如果当前列表为空
    if(ui->listWidget->count()!=0)//避免出现listWidget中的数据个数为0导致的程序崩溃
    {
        int currentNum = ui->listWidget->currentRow();//当前所在行号
        int rowcount = ui->listWidget->model()->rowCount();//当前列表的总行数
        qDebug()<<rowcount<<currentNum<<endl;
//        if(currentNum==0)
//        {
//            ui->listWidget->setCurrentRow(rowcount-1);//如果当前歌曲为第0行，则点击上一曲之后，设置当前播放歌曲为最后一个
//        }
//        else
//        {
//            ui->listWidget->setCurrentRow(currentNum-1);
//        }
        ui->listWidget->setCurrentRow((currentNum+1)%rowcount);
        QModelIndex test=ui->listWidget->currentIndex();
        ui->listWidget->clicked(test);
        mediaPlayer->setMedia(QUrl::fromLocalFile(ui->listWidget->currentItem()->text()));
        mediaPlayer->setVolume(ui->volumeSlider->value());
        ui->btn_play->setIcon(QIcon(":/new/prefix1/image/play.png"));
        mediaPlayer->play();
        m_IsPlaying=true;
    }
    else
    {
//        qDebug()<<"当前列表为空！"<<endl;
        QMessageBox::warning(this,"warning","----当前列表为空----\n请先添加音乐列表！");
        return;
    }
}

void QMusic::doProcess_btn_volumeClick()
{
    qDebug()<<"5"<<endl;
    if(ui->volumeSlider->isVisible())
    {
        ui->volumeSlider->setVisible(false);
    }
    else
    {
        //设置滑块可见之后，通过获取滑块的值，调整歌曲的音量
        ui->volumeSlider->setVisible(true);
//        mediaPlayer->setVolume(ui->volumeSlider->value());
    }
}

void QMusic::doProcess_btn_AboutClick()
{
    QMessageBox::about(this,"AboutApp","这是一个具有XXX功能的APP。创作者：XXX");
}
void QMusic::doProcess_btn_About2Click()
{
    QMessageBox::about(this,"AboutApp","这是一个具有XXX功能的APP。创作者：XXX");
}

void QMusic::doProcess_btn_MinmumClick()
{
    //退出到系统托盘最小化
    showMinimized();
}

void QMusic::doProcess_btn_QuitClick()
{
    close();
}

void QMusic::doProcessitemDoubleClicked(QListWidgetItem *item)
{

//    ui->listWidget->setCurrentRow(0);
//    QModelIndex test=ui->listWidget->currentIndex();
//    ui->listWidget->clicked(test);

    mediaPlayer->setMedia(QUrl::fromLocalFile(item->text()));
    mediaPlayer->setVolume(ui->volumeSlider->value());
    ui->btn_play->setIcon(QIcon(":/new/prefix1/image/play.png"));
    mediaPlayer->play();
}

void QMusic::doProcessVolumevalueChanged(int num)
{
    mediaPlayer->setVolume(num);
}

void QMusic::doProcessdurationChanged(qint64 duration)
{
    //当前duration为毫秒数，毫秒/1000->秒，毫秒/1000/60->分钟数
    QString str = QString("%1:%2:%3").arg(duration/1000/60/60,2,10,QLatin1Char('0')).arg(duration/1000/60,2,10,QLatin1Char('0')).arg(duration/1000%60,2,10,QLatin1Char('0'));
    ui->total_lbl->setText(str);
    //设置slider的范围
    ui->playProgressSlider->setRange(0,duration);
}

void QMusic::doProcesspositionChanged(qint64 pos)
{
    QString str = QString("%1:%2:%3").arg(pos/1000/60/60,2,10,QLatin1Char('0')).arg(pos/1000/60,2,10,QLatin1Char('0')).arg(pos/1000%60,2,10,QLatin1Char('0'));
    ui->cur_lbl->setText(str);
    //将当前的播放进度同步至slider
    ui->playProgressSlider->setValue(pos);
}

void QMusic::paintEvent(QPaintEvent *)
{
    //测试发现，不要将高精度的图片作为背景，否则会导致渲染压力大
    //例如：在默认背景下，鼠标鼠标放置在按钮上无需等待直接显示hover，
    //在更换背景图片之后，鼠标放置在按钮上需要等待一些时间才能显示hover
    QString fileName=":/new/prefix1/background/default.jpg";
    QSettings mysettings("./CloudMusic.ini", QSettings::IniFormat);
    mysettings.setIniCodec("UTF8");
    QString str = mysettings.value("background/image-url", fileName).toString();

    // Use QtConcurrent to load the image asynchronously
    QFuture<QPixmap> future = QtConcurrent::run([&]() {
        return QPixmap(str);
    });

    // Wait for the image to be loaded and draw it onto the widget
    QPixmap pixmap = future.result();
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
}

//系统托盘初始化
void QMusic::InitSystemTrayIcon()
{
    mySystemTray=new QSystemTrayIcon(this);
    mySystemTray->setIcon(QIcon(":/new/prefix1/image/systemTrayIcon.png"));
    mySystemTray->setToolTip("CloudMusic");
    //绑定信号槽，实现双击弹出或隐藏界面
    connect(mySystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(systemTrayIcon_activated(QSystemTrayIcon::ActivationReason)));

    //为托盘创建菜单，实现快捷点击
    QAction *action_systemTray_pre=new QAction(QIcon(":/new/prefix1/image/pre2.png"),"上一首",this);
    //将action与页面中的上一首按钮处理槽绑定，实现同样功能
    connect(action_systemTray_pre,SIGNAL(triggered(bool)),this,SLOT(doProcess_btn_preClick()));
    QAction *action_systemTray_play=new QAction(QIcon(":/new/prefix1/image/play2.png"),"播放",this);
    connect(action_systemTray_play,SIGNAL(triggered(bool)),this,SLOT(doProcess_btn_playClick()));
    QAction *action_systemTray_next=new QAction(QIcon(":/new/prefix1/image/next2.png"),"下一首",this);
    connect(action_systemTray_next,SIGNAL(triggered(bool)),this,SLOT(doProcess_btn_nextClick()));
    QAction *action_systemTray_quit = new QAction(QIcon(":/new/prefix1/image/exit.png"), "退出",this);
    connect(action_systemTray_quit, SIGNAL(triggered(bool)), this, SLOT(close()));

    //创建菜单，将action加入
    QMenu *pContextMenu = new QMenu(this);
    pContextMenu->addAction(action_systemTray_pre);
    pContextMenu->addAction(action_systemTray_play);
    pContextMenu->addAction(action_systemTray_next);
    pContextMenu->addAction(action_systemTray_quit);
    mySystemTray->setContextMenu(pContextMenu);
    mySystemTray->show();
}
void QMusic::systemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::DoubleClick:
        //显/隐主界面
        if(isHidden()){
            show();
        }else{
            hide();
        }
        break;
    default:
        break;
    }
}

void QMusic::mousePressEvent(QMouseEvent *event)
{
    if(this==QApplication::widgetAt(event->globalPos()))
    {
        m_lastPos=event->globalPos();//记录鼠标按下时窗口所在屏幕的位置
        isPressQMusicWidget=true;
    }

}

void QMusic::mouseMoveEvent(QMouseEvent *event)
{
    if(isPressQMusicWidget)
    {
        //移动的x和y的位置
        this->move(this->x()+(event->globalX()-m_lastPos.x()),
                   this->y()+(event->globalY()-m_lastPos.y()));
        //更新窗口所在的屏幕位置
        m_lastPos=event->globalPos();
    }
}

void QMusic::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos=event->globalPos();
    isPressQMusicWidget=false;
}

void QMusic::doProcessbtn_SkinClick()
{
    //实现菜单项
    QAction *action_backgroud_to_default = new QAction(QIcon(":/new/prefix1/background/default.jpg"),"默认背景",this);
    connect(action_backgroud_to_default,SIGNAL(triggered(bool)),this,SLOT(doProcessbtnbackgroud_to_default()));
    QAction *action_backgroud_to_custom=new QAction(QIcon(":/new/prefix1/image/setting.png"),"自定义背景",this);
    connect(action_backgroud_to_custom,SIGNAL(triggered(bool)),this,SLOT(doProcessbtnbackgroud_to_custom()));
    //将菜单项添加到菜单
    menu_changeSkin=new QMenu(this);
    menu_changeSkin->addAction(action_backgroud_to_default);
    menu_changeSkin->addAction(action_backgroud_to_custom);
    menu_changeSkin->exec(QCursor::pos());
}

void QMusic::doProcessbtnbackgroud_to_default()
{
    QString fileName=":/new/prefix1/background/default.jpg";
    //Constructs a QSettings object for accessing the settings
    //stored in the file called fileName, with parent parent.
    //If the file doesn't already exist, it is created.
    //If format is QSettings::IniFormat, fileName is the name of an INI file.
    QSettings mysettings("./CloudMusic.ini",QSettings::IniFormat);
    mysettings.setIniCodec("UTF8");
    mysettings.setValue("background/image-url",fileName);
    setStyleSheet(QString("QWidget#QMusic{"
                          "border-radius:10px;"
                          "border-image: url(%1);}"
                          "listWidget{"
                          "border:none;}").arg(fileName));
//    QApplication::processEvents();
    qDebug()<<"1:"<<fileName<<endl;
}

void QMusic::doProcessbtnbackgroud_to_custom()
{
    //从默认图片位置打开文件选择框
    QString fileName=QFileDialog::getOpenFileName(this,"选择自定义背景图片","C:\\Users\\gys\\Music","图片文件(*jpg *png)");
    if(!fileName.isEmpty())
    {
        QImage testImage(fileName);
        if(!testImage.isNull())
        {
            QSettings mysettings("./CloudMusic.ini",QSettings::IniFormat);
            mysettings.setIniCodec("UTF8");
            mysettings.setValue("background/image-url",fileName);
            setStyleSheet(QString("QWidget#QMusic{"
                                  "border-radius:10px;"
                                  "border-image: url(%1);}"
                                  "listWidget{"
                                  "border:none;}").arg(fileName));
//            QApplication::processEvents();
            qDebug()<<"2:"<<fileName<<endl;
        }
    }
}

