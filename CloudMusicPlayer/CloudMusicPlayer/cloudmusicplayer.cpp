#include "cloudmusicplayer.h"
#include "ui_cloudmusicplayer.h"
#include<QDebug>
#include<QFileDialog>
#include<QMessageBox>
#include<QStandardPaths>
#include<QtConcurrent>
#include<QFrame>
#include<QStatusBar>


CloudMusicPlayer::CloudMusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CloudMusicPlayer)
{
    ui->setupUi(this);
//    QFrame *frame=new QFrame(this);

    Init();

//    static int s=0;
//    qDebug()<<"CloudMusicPlayer构造函数执行次数"<<++s<<endl;
}

CloudMusicPlayer::~CloudMusicPlayer()
{
    delete ui;
}

void CloudMusicPlayer::Init()
{
    //系统托盘初始化
    InitSystemTrayIcon();

    //窗口设置圆角后，会出现留白，需要添加以下代码
    setAttribute(Qt::WA_TranslucentBackground, true);
    //去除标题栏（发现去除标题栏之后无法移动窗口，此时需要重写鼠标事件）
    setWindowFlags(Qt::FramelessWindowHint);

    mediaPlayer=new QMediaPlayer(this);
    ui->volumeSlider->setVisible(false);//初始化状态下音乐滑块不可见

    ui->playProgressSlider->setStyleSheet("QSlider::groove:horizontal {"
                                          "border: 1px solid #bbb;"
                                          "background: yellow;"
                                          "height: 10px;"
                                          "border-radius: 5px;}"
                                      "QSlider::handle:horizontal {"
                                          "background: qradialgradient(cx:0.5, cy:0.5, radius: 0.5, fx:0.5, fy:0.5,"
                                              "stop:0.6 #45ADED, stop:0.8 #1C64A6);"
                                          "border: 1px solid #bbb;"
                                          "width: 16px;"
                                          "height: 16px;"
                                          "margin: -3px 0;"
                                          "border-radius: 8px;}"
                                      "QSlider::sub-page:horizontal {"
                                          "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #45ADED, stop:1 #1C64A6);"
                                          "border-radius: 2px;}");
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
    connect(ui->btn_User,SIGNAL(clicked(bool)),this,SLOT(doProcessbtn_User()));
    //实现换肤功能
    connect(ui->btn_Skin,SIGNAL(clicked(bool)),this,SLOT(doProcessbtn_SkinClick()));

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
    connect(ui->btn_Setting,SIGNAL(clicked(bool)),this,SLOT(doProcessSetting()));

    //未写在点击user按钮内的原因：user按钮只点击一次，执行完毕便不会检测当前对象的信号情况
    loginwidget=new loginWidget();//新建一个对象，初始化，打开数据库
    dialog=new QDialog(this);
    userRegisterPage= new userRegister();
    //登录成功，删除对话框，接收登录的用户信息
    connect(loginwidget,SIGNAL(signal_loginSuccess()),dialog,SLOT(close()));
    connect(loginwidget,SIGNAL(signal_loginName(QString)),this,SLOT(receive_signal_loginSuccess(QString)));

    //接收登录界面发送过来的注册按钮点击信号，将注册界面加载在dialog中
    connect(loginwidget,SIGNAL(signal_register_click()),this,SLOT(UpdateDialogWidget()));

    connect(dialog,SIGNAL(rejected()),this,SLOT(doProcessCloseloginwidgetORuserRegisterPage()));



  /////////////////////////////////////对网络搜索绑定/////////////////////////////////
    network_manager=new QNetworkAccessManager();
    network_request=new QNetworkRequest();

    connect(ui->btn_search,SIGNAL(clicked(bool)),this,SLOT(doProcessbtn_searchClick()));
    connect(network_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished_slot(QNetworkReply*)));    //回复结束的时候QnetworkReply会释放finished信号

    //歌曲播放
    network_manager2 = new QNetworkAccessManager();
    network_request2 = new QNetworkRequest();
    connect(network_manager2, &QNetworkAccessManager::finished, this, &CloudMusicPlayer::replyFinished2);
    connect(ui->tableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(tableWidget_cellDoubleClicked(QTableWidgetItem*)));

    //行编辑的占位符文本。只要行编辑为空，设置此属性将使行编辑显示一个灰色的占位符文本。
    ui->ledit_songName->setPlaceholderText("输入歌曲名,回车一键搜索");
    //输入完成，回车一键搜索
    connect(ui->ledit_songName,SIGNAL(returnPressed()),ui->btn_search,SLOT(click()));

    connect(ui->btn_Listening,SIGNAL(clicked(bool)),this,SLOT(doProcessListenRecorder()));



    //接收注册成功界面发送过来的信号，重新加载登录界面至dialog中

    //接收信号，将userRegisterPage加入Dialog中

    //实现登录功能，将登录功能加载到当前页面，登录之后显示用户所存储的歌曲

//    mediaPlayer->setAudioRole();
//    player = new QMediaPlayer;
//    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    QUrl fileUrl=":/Users/gys/Music/Cash Cash _ Christina Perri - Hero.mp3";

}
void CloudMusicPlayer::doProcess_btn_openfileClick()
{
    qDebug()<<"1"<<endl;
    QStringList fileNames = QFileDialog::getOpenFileNames(this,"请选择音乐所在目录","C:\\Users\\gys\\Music",tr("Music (*.mp3)"));//打开已经存在的目录
    qDebug()<<"fileNames"<<fileNames<<endl;
    for(int i=0;i<fileNames.length();i++)
    {
        qDebug()<<"fileNames.at(i)"<<fileNames.at(i)<<"--------"<<endl;
        QString str=fileNames.at(i);
        QStringList list1 = str.split(QLatin1Char('/'));
        QString songName=list1.last();
        ui->listWidget->addItem(songName);
    }


    //音乐导入之后默认选择第0行作为选中行
    if(fileNames.length()!=0)
    {
        ui->listWidget->setCurrentRow(0);
        //模拟点击
        QModelIndex test=ui->listWidget->currentIndex();
        ui->listWidget->clicked(test);
    }
    else
    {
        QMessageBox::warning(this,"warning","----未选中文件----\n请重新添加音乐列表！");
        return;
    }

    //将当前列表中的数据重新写入数据库，并对数据库中的数据去重
    if(currentuserName.isEmpty())
    {
        currentuserName="";
    }
    //对当前列表中的歌曲进行解析，获取歌曲的详细信息
    //歌曲信息
    //当前的url需要对fileNames进行遍历
    for(int i=0;i<fileNames.count();i++)
    {
        //歌曲信息切分
        url = fileNames.at(i);
        QString str=fileNames.at(i);
        QStringList list1 = str.split(QLatin1Char('/'));
        QString songName=list1.last();

        QSqlQuery query;
        QString insert_sql = "INSERT INTO MusicInfo (userName, url, title) VALUES (?, ?, ?)";
        query.prepare(insert_sql);
        query.addBindValue(currentuserName);//当前用户名
        query.addBindValue(url);//当前url
        query.addBindValue(songName);
        query.exec();

    }
    //对当前用户的重复歌曲去重
    QSqlQuery querys;
    QString removeDupl_sql="DELETE FROM MusicInfo WHERE rowid NOT IN ( SELECT rowid FROM MusicInfo GROUP BY ( userName || 'seprator' || url ) );";
    querys.exec(removeDupl_sql);
    if(querys.exec(removeDupl_sql))
    {
        qDebug()<<"执行成功！"<<endl;
    }
    else
    {
        QMessageBox::warning(this,"warning",querys.lastError().text());
        qDebug()<<"cloudmusicplayer---QSqlQuery::lastError()"<<querys.lastError().text()<<endl;
    }

}
void CloudMusicPlayer::doProcess_btn_preClick()
{

    qDebug()<<"2"<<endl;
    //如果当前列表为空
    if(ui->listWidget->count()!=0)//避免出现listWidget中的数据个数为0导致的程序崩溃
    {
        int currentNum = ui->listWidget->currentRow();//当前所在行号
        int rowcount = ui->listWidget->model()->rowCount();//当前列表的总行数
        qDebug()<<rowcount<<currentNum<<endl;
        //当前总行数为1，当前currentNum为-1，那么无论是上一首还是下一首，均为当前行
        if(currentNum==0)
        {
            ui->listWidget->setCurrentRow(rowcount-1);//如果当前歌曲为第0行，则点击上一曲之后，设置当前播放歌曲为最后一个
        }
        else if(rowcount==1&&currentNum==-1)
        {
            ui->listWidget->setCurrentRow(ui->listWidget->currentRow());
        }
        else
        {
            ui->listWidget->setCurrentRow(currentNum-1);
        }
        QModelIndex test=ui->listWidget->currentIndex();
        ui->listWidget->clicked(test);

        //如果是网络歌曲，那么当前使用该方式是播放不了的,因此
        //////////////引入数据库，在数据库中查询歌曲名字，获取url//////////////
        QSqlQuery sql_query;
        QString selectSqlBySongName;
        if(currentuserName.isEmpty())
        {
            //公共音乐区
            selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName='' AND title = ?";
            sql_query.prepare(selectSqlBySongName);
            sql_query.addBindValue(ui->listWidget->currentItem()->text());//当前歌曲名字
        }
        else
        {
            //在线用户的音乐区
            selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName = ? AND title = ?";
            sql_query.prepare(selectSqlBySongName);
            sql_query.addBindValue(currentuserName);//添加登录成功的用户名字
            sql_query.addBindValue(ui->listWidget->currentItem()->text());//当前歌曲名字
        }

        if(sql_query.exec())
        {
            if(sql_query.next())
            {
                url=QUrl(sql_query.value(1).toString());
            }
        }

        mediaPlayer->setMedia(QUrl::fromLocalFile(url.toString()));
        qDebug()<<"2"<<endl;
        mediaPlayer->setVolume(ui->volumeSlider->value());
        ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
        mediaPlayer->play();
        qDebug()<<"3"<<endl;
        m_IsPlaying=true;
    }
    else
    {
        qDebug()<<"当前列表为空！"<<endl;
        QMessageBox::warning(this,"warning","----当前列表为空----\n请先添加音乐列表！");
        return;
    }
}
void CloudMusicPlayer::doProcess_btn_playClick()
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
                //////////////引入数据库，在数据库中查询歌曲名字，获取url//////////////
                QSqlQuery sql_query;
                QString selectSqlBySongName;
                if(currentuserName.isEmpty())
                {
                    //公共音乐区/////注意，从本地导入的歌曲只显示歌曲名字，否则找不到
                    selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName='' AND title = ?";
                    sql_query.prepare(selectSqlBySongName);
                    sql_query.addBindValue(ui->listWidget->currentItem()->text());//当前歌曲名字
                }
                else
                {
                    //当前用户的音乐区
                    selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName = ? AND title = ?";
                    sql_query.prepare(selectSqlBySongName);
                    sql_query.addBindValue(currentuserName);//添加登录成功的用户名字
                    sql_query.addBindValue(ui->listWidget->currentItem()->text());//当前歌曲名字
                }

                if(sql_query.exec())
                {
                    if(sql_query.next())
                    {
                        url=QUrl(sql_query.value(1).toString());
        //                QListWidgetItem *item=new QListWidgetItem;

        //                item->setText(url.toString());
        //                ui->listWidget->addItem(item);
                    }
                }
                mediaPlayer->setMedia(QUrl::fromLocalFile(url.toString()));
                mediaPlayer->setVolume(ui->volumeSlider->value());
                ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
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
            ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/pase.png"));
            mediaPlayer->pause();
            m_IsPlaying = false;//设置播放状态为非停止，便于下次调用
            break;
        }
        //暂停状态,继续播放
        case QMediaPlayer::PausedState:
        {
            ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
            mediaPlayer->play();
            m_IsPlaying=true;
            break;
        }
    }

}

void CloudMusicPlayer::doProcess_btn_nextClick()
{
    qDebug()<<"4"<<endl;
    //如果当前列表为空
    if(ui->listWidget->count()!=0)//避免出现listWidget中的数据个数为0导致的程序崩溃
    {
        int currentNum = ui->listWidget->currentRow();//当前所在行号
        int rowcount = ui->listWidget->model()->rowCount();//当前列表的总行数
        qDebug()<<rowcount<<currentNum<<endl;
        //当前总行数为1，当前currentNum为-1，那么无论是上一首还是下一首，均为当前行
        if(rowcount==1&&currentNum==-1)
        {
            ui->listWidget->setCurrentRow(ui->listWidget->currentRow());
        }
//        if(currentNum==0)
//        {
//            ui->listWidget->setCurrentRow(rowcount-1);//如果当前歌曲为第0行，则点击上一曲之后，设置当前播放歌曲为最后一个
//        }
//        else
//        {
//            ui->listWidget->setCurrentRow(currentNum-1);
//        }
        ui->listWidget->setCurrentRow((currentNum+1)%rowcount);//数据结构，循环列表
        QModelIndex test=ui->listWidget->currentIndex();
        ui->listWidget->clicked(test);
        //////////////引入数据库，在数据库中查询歌曲名字，获取url//////////////
        QSqlQuery sql_query;
        QString selectSqlBySongName;
        if(currentuserName.isEmpty())
        {
            //公共音乐区/////注意，从本地导入的歌曲只显示歌曲名字，否则找不到
            selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName='' AND title = ?";
            sql_query.prepare(selectSqlBySongName);
            sql_query.addBindValue(ui->listWidget->currentItem()->text());//当前歌曲名字
        }
        else
        {
            //当前用户的音乐区
            selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName = ? AND title = ?";
            sql_query.prepare(selectSqlBySongName);
            sql_query.addBindValue(currentuserName);//登录成功的用户名字
            sql_query.addBindValue(ui->listWidget->currentItem()->text());//当前歌曲名字
        }

        if(sql_query.exec())
        {
            if(sql_query.next())
            {
                url=QUrl(sql_query.value(1).toString());
//                QListWidgetItem *item=new QListWidgetItem;

//                item->setText(url.toString());
//                ui->listWidget->addItem(item);
            }
        }
        mediaPlayer->setMedia(QUrl::fromLocalFile(url.toString()));
        mediaPlayer->setVolume(ui->volumeSlider->value());
        ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
        mediaPlayer->play();
        m_IsPlaying=true;
    }
    else
    {
        QMessageBox::warning(this,"warning","----当前列表为空----\n请先添加音乐列表！");
        return;
    }
}

void CloudMusicPlayer::doProcess_btn_volumeClick()
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
        ui->volumeSlider->setStyleSheet("QSlider::groove:vertical {"
                                            "border: 1px solid #bbb;"
                                            "background: yellow;"
                                            "width: 10px;"
                                            "border-radius: 5px;}"
                                        "QSlider::handle:vertical {"
                                            "background: qradialgradient(cx:0.5, cy:0.5, radius: 0.5, fx:0.5, fy:0.5,"
                                                "stop:0.6 #45ADED, stop:0.8 #1C64A6);"
                                            "border: 1px solid #bbb;"
                                            "width: 16px;"
                                            "height: 16px;"
                                            "margin: 0 -6px;"
                                            "border-radius: 8px;}"
                                        "QSlider::sub-page:vertical {"
                                        "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(69, 173, 237, 255), stop:1 rgba(28, 100, 166, 255));"
                                        "border-radius: 8px;}");
    }

}

void CloudMusicPlayer::doProcess_btn_AboutClick()
{
    QMessageBox::about(this,"AboutApp","Windows下基于Qt的云音乐播放器\n创作者：GYS\n");
}
void CloudMusicPlayer::doProcess_btn_About2Click()
{
    QMessageBox::about(this,"AboutApp","Windows下基于Qt的云音乐播放器\n创作者：GYS\n");
}

void CloudMusicPlayer::doProcess_btn_MinmumClick()
{
    //退出到系统托盘最小化
    showMinimized();
}

void CloudMusicPlayer::doProcess_btn_QuitClick()
{
    close();
}

void CloudMusicPlayer::doProcessbtn_User()
{
    loginwidget->show();
    dialog->setWindowTitle("用户登录");
    dialog->setWindowModality(Qt::ApplicationModal);
    if(dialog->layout())
    {
        delete dialog->layout();
    }
    dialog->setLayout(new QVBoxLayout);
    dialog->layout()->addWidget(loginwidget);
    dialog->exec();

//    loginwidget->show();
    // 将新窗口移动到主窗口中间
    int x = this->pos().x() + (this->width() - loginwidget->width()) / 2;
    int y = this->pos().y() + (this->height() - loginwidget->height()) / 2;
    loginwidget->move(x, y);

}
void CloudMusicPlayer::doProcessCloseloginwidgetORuserRegisterPage()
{
    if(loginwidget->isEnabled())
    {
        qDebug()<<"shanchu1"<<endl;
        loginwidget->close();
    }
    if(userRegisterPage->isEnabled())
    {
        qDebug()<<"shanchu2"<<endl;
        userRegisterPage->close();
    }
}

void CloudMusicPlayer::receive_signal_loginSuccess(QString usrName)
{
    //登录成功，清除listWidget的当前列表，添加数据库中的信息
    ui->listWidget->clear();
    loginwidget->hide();
    /*
    //登录之后只展示用户之前添加过并写入数据库中的音乐，同时，
    //当用户点击添加音乐时，仍然可以添加音乐至listwidget中，
    //此时，在添加音乐时，可以检测当前的用户userName是否为空，
    //如果为空，则直接添加，不用更新数据库，否则，添加之后，将当前listwidget中的音乐更新至数据库
    */
    currentuserName=usrName;
    ui->btn_User->setToolTip(currentuserName);
    qDebug()<<"登陆成功！加载数据库中歌曲"<<endl;
    QSqlQuery sql_query;
    QString select_sql = "select url, author, title, duration, albumTitle, audioBitRate from MusicInfo where userName = ?";
    sql_query.prepare(select_sql);
    sql_query.addBindValue(currentuserName);//添加登录成功的用户名字
    if(sql_query.exec())
    {
        while(sql_query.next())
        {
            url=QUrl(sql_query.value(0).toString());
            author=sql_query.value(1).toString();
            title=sql_query.value(2).toString();
            duration=sql_query.value(3).toLongLong();
            albumTitle=sql_query.value(4).toString();
            audioBitRate=sql_query.value(5).toInt();
            QListWidgetItem *item=new QListWidgetItem;

            item->setText(title);
            ui->listWidget->addItem(item);
        }
    }
    //默认模拟点击第一行，防止上一曲出现崩溃
    ui->listWidget->setCurrentRow(0);
    //模拟点击
    QModelIndex test=ui->listWidget->currentIndex();
    ui->listWidget->clicked(test);
}

void CloudMusicPlayer::doProcessitemDoubleClicked(QListWidgetItem *item)
{

//    ui->listWidget->setCurrentRow(0);
//    QModelIndex test=ui->listWidget->currentIndex();
//    ui->listWidget->clicked(test);

    This_Widget="listWidget";
    //默认当前item为歌曲名字
    ////////////////使用当前方式，当前listWidget展示的文字必须是路径，为了美化播放列表，将使用数据库/////////////
    //////////////引入数据库，在数据库中查询歌曲名字，获取url//////////////
    QSqlQuery sql_query;
    QString selectSqlBySongName;
    if(currentuserName.isEmpty())
    {
        //公共音乐区/////注意，从本地导入的歌曲只显示歌曲名字，否则找不到
        selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName='' AND title = ?";
        sql_query.prepare(selectSqlBySongName);
        sql_query.addBindValue(item->text());//当前歌曲名字
        qDebug()<<item->text()<<"---------------"<<endl;
    }
    else
    {
        //在线用户的音乐区
        selectSqlBySongName = "SELECT * FROM MusicInfo WHERE userName = ? AND title = ?";
        sql_query.prepare(selectSqlBySongName);
        sql_query.addBindValue(currentuserName);//添加登录成功的用户名字
        sql_query.addBindValue(item->text());//当前歌曲名字
    }

    if(sql_query.exec())
    {
        if(sql_query.next())
        {
            url=QUrl(sql_query.value(1).toString());
//                QListWidgetItem *item=new QListWidgetItem;

//                item->setText(url.toString());
//                ui->listWidget->addItem(item);
        }
    }
    qDebug()<<url.toString()<<"---------------"<<endl;
    mediaPlayer->setMedia(QUrl::fromLocalFile(url.toString()));
    mediaPlayer->setVolume(ui->volumeSlider->value());
    ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
    mediaPlayer->play();
}

void CloudMusicPlayer::doProcessVolumevalueChanged(int num)
{
    mediaPlayer->setVolume(num);
}

void CloudMusicPlayer::doProcessdurationChanged(qint64 duration)
{
    //当前duration为毫秒数，毫秒/1000->秒，毫秒/1000/60->分钟数
    QString str = QString("%1:%2:%3").arg(duration/1000/60/60,2,10,QLatin1Char('0'))
            .arg(duration/1000/60,2,10,QLatin1Char('0')).arg(duration/1000%60,2,10,QLatin1Char('0'));
    ui->total_lbl->setText(str);
    //设置slider的范围
    ui->playProgressSlider->setRange(0,duration);
}

void CloudMusicPlayer::doProcesspositionChanged(qint64 pos)
{

    QString str = QString("%1:%2:%3").arg(pos/1000/60/60,2,10,QLatin1Char('0'))
            .arg(pos/1000/60,2,10,QLatin1Char('0')).arg(pos/1000%60,2,10,QLatin1Char('0'));
    ui->cur_lbl->setText(str);
    //将当前的播放进度同步至slider
    ui->playProgressSlider->setValue(pos);
    //检测当前播放完毕，则播放列表下一首
    if(str==ui->total_lbl->text()&&str!="00:00:00")
    {
        qDebug()<<"播放完毕"<<endl;
        //更换为暂停按钮
        ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/pase.png"));
        ///////在后前添加判断当前播放列表是哪一个
        //获取当前点击列表中的行，对当前点击的行加1，模拟双击操作
        if(This_Widget=="listWidget")
        {
            ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
            QModelIndex test=ui->listWidget->currentIndex();
            ui->listWidget->clicked(test);//选中当前行
            ui->listWidget->itemDoubleClicked(ui->listWidget->currentItem());
            return;
        }
        if(This_Widget=="tableWidget")
        {
            ui->tableWidget->setCurrentCell(ui->tableWidget->currentRow()+1,0);
            ui->tableWidget->itemDoubleClicked(ui->tableWidget->item(ui->tableWidget->currentRow(),0));
            return;
        }
    }

}

void CloudMusicPlayer::paintEvent(QPaintEvent *)
{
    //测试发现，不要将高精度的图片作为背景，否则会导致渲染压力大
    //例如：在默认背景下，鼠标鼠标放置在按钮上无需等待直接显示hover，
    //在更换背景图片之后，鼠标放置在按钮上需要等待一些时间才能显示hover
    QString fileName=":/new/prefix1/img/background/理想家园.JPG";
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
void CloudMusicPlayer::InitSystemTrayIcon()
{
    mySystemTray=new QSystemTrayIcon(this);
    mySystemTray->setIcon(QIcon(":/new/prefix1/img/image/systemTrayIcon.png"));
    mySystemTray->setToolTip("CloudMusic");
    //绑定信号槽，实现双击弹出或隐藏界面
    connect(mySystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
            SLOT(systemTrayIcon_activated(QSystemTrayIcon::ActivationReason)));

    //为托盘创建菜单，实现快捷点击
    QAction *action_systemTray_pre=new QAction(QIcon(":/new/prefix1/img/image/pre2.png"),"上一首",this);
    //将action与页面中的上一首按钮处理槽绑定，实现同样功能
    connect(action_systemTray_pre,SIGNAL(triggered(bool)),this,SLOT(doProcess_btn_preClick()));
    QAction *action_systemTray_play=new QAction(QIcon(":/new/prefix1/img/image/play2.png"),"播放",this);
    connect(action_systemTray_play,SIGNAL(triggered(bool)),this,SLOT(doProcess_btn_playClick()));
    QAction *action_systemTray_next=new QAction(QIcon(":/new/prefix1/img/image/next2.png"),"下一首",this);
    connect(action_systemTray_next,SIGNAL(triggered(bool)),this,SLOT(doProcess_btn_nextClick()));
    QAction *action_systemTray_quit = new QAction(QIcon(":/new/prefix1/img/image/exit.png"), "退出",this);
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
void CloudMusicPlayer::systemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason)
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

void CloudMusicPlayer::mousePressEvent(QMouseEvent *event)
{
    if(this==QApplication::widgetAt(event->globalPos()))
    {
        m_lastPos=event->globalPos();//记录鼠标按下时窗口所在屏幕的位置
        isPressQMusicWidget=true;
    }
}

void CloudMusicPlayer::mouseMoveEvent(QMouseEvent *event)
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

void CloudMusicPlayer::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos=event->globalPos();
    isPressQMusicWidget=false;
}

void CloudMusicPlayer::doProcessbtn_SkinClick()
{
    //实现菜单项
    QAction *action_backgroud_to_default = new QAction(QIcon(":/new/prefix1/img/background/default.jpg"),"默认背景",this);
    connect(action_backgroud_to_default,SIGNAL(triggered(bool)),this,SLOT(doProcessbtnbackgroud_to_default()));
    QAction *action_backgroud_to_custom=new QAction(QIcon(":/new/prefix1/img/image/setting.png"),"自定义背景",this);
    connect(action_backgroud_to_custom,SIGNAL(triggered(bool)),this,SLOT(doProcessbtnbackgroud_to_custom()));
    //将菜单项添加到菜单
    menu_changeSkin=new QMenu(this);
    menu_changeSkin->addAction(action_backgroud_to_default);
    menu_changeSkin->addAction(action_backgroud_to_custom);
    menu_changeSkin->exec(QCursor::pos());
}

void CloudMusicPlayer::doProcessbtnbackgroud_to_default()
{
    QString fileName=":/new/prefix1/img/background/default.jpg";
    //Constructs a QSettings object for accessing the settings
    //stored in the file called fileName, with parent parent.
    //If the file doesn't already exist, it is created.
    //If format is QSettings::IniFormat, fileName is the name of an INI file.
    QSettings mysettings("./CloudMusic.ini",QSettings::IniFormat);
    mysettings.setIniCodec("UTF8");
    mysettings.setValue("background/image-url",fileName);
    setStyleSheet(QString("QWidget#CloudMusicPlayer{"
                          "border-radius:10px;"
                          "border-image: url(%1);}"
                          "listWidget{"
                          "border:none;}").arg(fileName));
//    QApplication::processEvents();
    qDebug()<<"1:"<<fileName<<endl;
}

void CloudMusicPlayer::doProcessbtnbackgroud_to_custom()
{
    //从默认图片位置打开文件选择框
    QString fileName=QFileDialog::getOpenFileName(this,"选择自定义背景图片","C:\\Users\\gys\\Pictures","图片文件(*jpg *png)");
    if(!fileName.isEmpty())
    {
        QImage testImage(fileName);
        if(!testImage.isNull())
        {
            QSettings mysettings("./CloudMusic.ini",QSettings::IniFormat);
            mysettings.setIniCodec("UTF8");
            mysettings.setValue("background/image-url",fileName);
            setStyleSheet(QString("QWidget#CloudMusicPlayer{"
                                  "border-radius:10px;"
                                  "border-image: url(%1);}"
                                  "listWidget{"
                                  "border:none;}").arg(fileName));
//            QApplication::processEvents();
            qDebug()<<"2:"<<fileName<<endl;
        }
    }
}
void CloudMusicPlayer::UpdateDialogWidget()
{

    loginwidget->hide();
    userRegisterPage->show();
    dialog->setWindowTitle("用户注册");
    dialog->layout()->addWidget(userRegisterPage);
    dialog->layout()->update();
    // 将新窗口移动到主窗口中间
    int x = this->pos().x() + (this->width() - userRegisterPage->width()) / 2;
    int y = this->pos().y() + (this->height() - userRegisterPage->height()) / 2;
    userRegisterPage->move(x, y);
    //绑定注册成功的信号
    connect(userRegisterPage,SIGNAL(backToLoginWidget()),this,SLOT(reloadloginwidgetTodialog()));
    //可将槽改为doProcessbtn_User
}


void CloudMusicPlayer::reloadloginwidgetTodialog()
{
    qDebug()<<"reloadloginwidgetTodialog"<<endl;
    userRegisterPage->Clear_liedt_userInfo();
    userRegisterPage->close();
    loginwidget->show();
    dialog->layout()->addWidget(loginwidget);
    dialog->layout()->update();
//    dialog->exec();

    // 将新窗口移动到主窗口中间
    int x = this->pos().x() + (this->width() - loginwidget->width()) / 2;
    int y = this->pos().y() + (this->height() - loginwidget->height()) / 2;
    loginwidget->move(x, y);
    qDebug()<<"loginwidget->show();"<<endl;

}

/////////////////////////////实现网络搜索，解析功能/////////////////////////////////
/// \brief CloudMusicPlayer::doProcessbtn_searchClick
///注意：
/// cloudjson.cpp/.h实际上是对酷狗音乐的API解析实现
/// kugoujson.cpp/.h实际上是对网易云的API解析实现
/// 但是功能均能正常执行，只是名字写反了
void CloudMusicPlayer::doProcessbtn_searchClick()
{
    m_musicId.clear();
    qDebug()<<"111"<<endl;
    QString searchName=ui->ledit_songName->text();

    qDebug()<<"歌曲名字为："<<searchName<<endl;
    if(Index==0)
    {
        qDebug()<<"Index==0"<<endl;
        searchLink="http://mobilecdn.kugou.com/api/v3/search/song?format=json&keyword=";
        searchLink+=searchName+"&page=1&pagesize=30";
        qDebug()<<"搜索链接："<<searchLink<<endl;
    }
    if(Index==1)
    {
        qDebug()<<"Index==1"<<endl;
        searchLink = "http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+searchName+"}&type=1&offset=0&total=true&limit=30";//接入网易云API并且传入需要搜索的数据和返回的数量
    }

    network_request->setUrl(QUrl(searchLink));
    network_manager->get(*network_request);
}

void CloudMusicPlayer::finished_slot(QNetworkReply* reply)
{

    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
//    qDebug()<<"status_code:"<<status_code<<endl;
    //无错误返回
    qDebug()<<"status_code:"<<endl;
    if(reply->error() == QNetworkReply::NoError)
    {
        qDebug()<<"status_code2:"<<endl;
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        qDebug()<<result<<"-----------------"<<endl;
        parseJson(result);//该函数用于解析api接口返回的json
    }
    else
    {
        //处理错误
        qDebug()<<"搜索失败";
    }
}

void CloudMusicPlayer::parseJson(QString json)
{
//    ui->tableWidget_2->clear();
    //每次加载前清除数组中的数据，保证数组中存储的都是最新解析的歌曲地址
    m_Vectorlist.clear();
    m_ID.clear();
    m_musicId.clear();
    qDebug()<<"status_code3:"<<endl;
//    QString songname_original; //歌曲名
//    QString singername;        //歌手
//    QString hashStr;           //hash
//    QString album_name;        //专辑
//    int duration;          	   //时间-总时长
    if(Index==0)
    {
        //实际上是对酷狗的API解析，不要被名字误导
        JsonCloud=new cloudJson();
        JsonCloud->parseJson(json);
        m_Vectorlist=JsonCloud->m_Vectorlist;//歌曲的hash编码
        m_ID=JsonCloud->m_ID;

        //将解析出的内容放到列表中
        ui->tableWidget->setRowCount(30);
        ui->tableWidget->setColumnCount(4);
        for(int i=0;i<30;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(JsonCloud->songname_original.at(i)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(JsonCloud->singername.at(i)));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(JsonCloud->album_name.at(i)));
            QString time = QString("%1:%2").arg(JsonCloud->duration.at(i)/60,2,10,QLatin1Char('0')).arg(JsonCloud->duration.at(i)%60,2,10,QLatin1Char('0'));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(time));
        }
    }
    if(Index==1)
    {
        //实际上是对网易云的API解析，不要被名字误导
        JsonKugou=new kugouJson();
        JsonKugou->parseJson(json);
        m_musicId=JsonKugou->m_musicId;
        //将解析出的内容放到列表中
        ui->tableWidget->setRowCount(30);
        ui->tableWidget->setColumnCount(4);
        for(int i=0;i<30;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(JsonKugou->songname_original.at(i)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(JsonKugou->singername.at(i)));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(JsonKugou->album_name.at(i)));
            QString time = QString("%1:%2").arg((JsonKugou->duration.at(i))/(1000*60)%60,2,10,QLatin1Char('0')).arg((JsonKugou->duration.at(i)/1000)%60,2,10,QLatin1Char('0'));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(time));
        }

    }
}

/////////////////////////////////以上完成了解析并展示在tablewidget的功能///////////////////////////////////////

void CloudMusicPlayer::tableWidget_cellDoubleClicked(QTableWidgetItem* item)
{

    int row=item->row();
    //歌曲请求
    //设置当前Widget标志位
    This_Widget="tableWidget";
    if(Index==0)
    {
        //首先，在使用Index==1时候，调用了信号槽函数，但是当使用Index==0时候，
        //由于mediaPlayer进行了play，且信号槽仍然在监测状态，
        //因此，此时即使Index！=1，也会导致程序执行顺序混乱
        //解决方案，在次数暂时断开信号槽的连接
        disconnect(mediaPlayer,&QMediaPlayer::mediaStatusChanged,0,0);
        KGAPISTR =QString("https://www.kugou.com/yy/index.php?r=play/getdata"
        "&hash=%1&album_id=%2&_=1680098110784").arg(m_Vectorlist.at(row)).arg(m_ID.at(row));
        network_request2->setRawHeader("Cookie","kg_mid=233");
        network_request2->setHeader(QNetworkRequest::CookieHeader, 2333);
        qDebug()<<"KGAPISTR1"<<KGAPISTR<<endl;
        network_request2->setUrl(QUrl(KGAPISTR));
        network_manager2->get(*network_request2);
        qDebug()<<"执行到Index==0"<<endl;
    }
    else if(Index==1)
    {
        invalidMediaDialogShown = false;
        KGAPISTR = QString("https://music.163.com/song/media/outer/url?id=%1").arg(m_musicId.at(row));//通过网网易云API传入之前返回的歌曲的ID实现播放
        qDebug()<<"KGAPISTR----------"<<KGAPISTR<<endl;
        mediaPlayer->setMedia(QUrl::fromLocalFile(KGAPISTR));
        connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, [this,item](QMediaPlayer::MediaStatus status)
        {
            switch (status)
            {
                case QMediaPlayer::LoadingMedia:
                case QMediaPlayer::BufferingMedia:
                    // 音乐源正在加载或缓冲
                    qDebug()<<"音乐源正在加载或缓冲"<<endl;
                    setToolTip("音乐源正在加载或缓冲");
                    break;
                case QMediaPlayer::LoadedMedia:
                case QMediaPlayer::BufferedMedia:
                {
                    // 音乐源已经加载或缓冲完成，可以播放
                    qDebug()<<"音乐源已经加载或缓冲完成，可以播放"<<endl;
                    setToolTip("音乐源已加载或缓冲完成，可以播放!");
                    ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
                    mediaPlayer->play();
                    //将音乐的名字插入listwidget中
//                    ui->listWidget->addItem(JsonKugou->songname_original.at(item->row()));

                    //当前是公共用户，那么将播放的历史歌曲，插入到历史数据库中
                    if(currentuserName.isEmpty())
                    {
                         currentuserName="";/////////////////////
                    }
                    QSqlQuery query;
                    //注意：使用new是在堆区开辟了一块内存，在程序运行的时候只能由程序员进行释放，若程序结束前未释放，那么系统自动回收
                    //因此，在这里仍然可以使用刚才建立的JsonKugou对象
                    QString url=KGAPISTR;
                    QString author=JsonKugou->singername.at(item->row());
                    QString title=JsonKugou->songname_original.at(item->row());
                    QString insert_sql = "INSERT INTO MusicInfo (userName, url, author, title) VALUES (?, ?, ?, ?)";
                    query.prepare(insert_sql);
                    query.addBindValue(currentuserName);//当前用户名
                    query.addBindValue(url);//当前url
                    query.addBindValue(author);//当前url
                    query.addBindValue(title);//当前url
                    query.exec();
                    //对当前用户的重复歌曲去重
                    QSqlQuery querys;
                    QString removeDupl_sql="DELETE FROM MusicInfo WHERE rowid NOT IN ( SELECT rowid FROM MusicInfo GROUP BY ( userName || 'seprator' || url ) );";
                    querys.exec(removeDupl_sql);
                    if(querys.exec(removeDupl_sql))
                    {
                        qDebug()<<"执行成功！"<<endl;
                    }
                    else
                    {
                        QMessageBox::warning(this,"warning",querys.lastError().text());
                        qDebug()<<"cloudmusicplayer---QSqlQuery::lastError()"<<querys.lastError().text()<<endl;
                    }

                    break;
                }
                case QMediaPlayer::InvalidMedia:
                    // 音乐源无效
                    qDebug()<<"音乐源无效"<<endl;
                    if(!invalidMediaDialogShown)
                    {
                        QMessageBox::warning(this,"warning","版权等原因不可用");
                    }
                    invalidMediaDialogShown=true;
                    break;
                default:
                    break;
            }
        });
    }


    //QString KGAPISTR1 =QString("https://www.kugou.com/yy/index.php?r=play/getdata&hash=1112A64F5B265256186A306753951217&album_id=522097&_=1497972864535");

    //qDebug()<<"歌曲详细列表"<<KGAPISTR1;
    //不加头无法得到json，可能是为了防止机器爬取

//    network_manager2->get(*network_request2);
}

void CloudMusicPlayer::replyFinished2(QNetworkReply *reply)
{
    qDebug()<<"执行到replyFinished2"<<endl;
    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        qDebug()<<"result"<<result<<endl;
        parseJsonSongInfo(result);//解析json
    }
    else
    {
        //处理错误
        QMessageBox::warning(this,"歌曲播放失败",reply->errorString());
        qDebug()<<"歌曲播放失败";
    }
}


void CloudMusicPlayer::parseJsonSongInfo(QString json)
{
    qDebug()<<"执行到parseJsonSongInfo"<<endl;
    QString audio_name;//歌手-歌名
    QString play_urlStr;//播放地址
    QString img_url;
    QString author_name="";//作者名字
    QByteArray byte_array;
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array.append(json), &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
       if(parse_doucment.isObject())
       {
           QJsonObject rootObj = parse_doucment.object();
           if(rootObj.contains("data"))
           {
               QJsonValue valuedata = rootObj.value("data");
               if(valuedata.isObject())
               {
                   QJsonObject valuedataObject = valuedata.toObject();
                   play_urlStr="";
                   if(valuedataObject.contains("play_url"))
                   {
                       QJsonValue play_url_value = valuedataObject.take("play_url");
                       if(play_url_value.isString())
                       {
                           play_urlStr = play_url_value.toString();      //歌曲的url
                           if(play_urlStr!="")
                           {
                               qDebug()<<play_urlStr;
                               mediaPlayer->setMedia(QUrl(play_urlStr));
    //                                   mediaPlayer->setVolume(50);
                               //设置播放图标
                               ui->btn_play->setIcon(QIcon(":/new/prefix1/img/image/play.png"));
                               mediaPlayer->play();
                           }
                           else
                           {
                               qDebug()<<"未找到play_urlStr"<<endl;
                           }
                       }
                   }
                   if(valuedataObject.contains("audio_name"))
                   {
                       QJsonValue play_name_value = valuedataObject.take("audio_name");
                       if(play_name_value.isString())
                       {
                           audio_name="";//先清空，再获取当前取得的歌曲名字
                           audio_name = play_name_value.toString();    //歌曲名字
                           if(audio_name!="")
                           {
                               //显示
                               qDebug()<<audio_name<<"--------------------------";
                               //添加歌曲名字到listWidget
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
                               ui->listWidget->addItem(audio_name);
    //                         ui->label_2->setText(audio_name);
                           }
                           else
                           {
                               qDebug()<<"未找到audio_name"<<endl;
                           }
                       }
                   }
                   if(valuedataObject.contains("author_name"))
                   {
                       QJsonValue author_name_value = valuedataObject.take("author_name");

                       if(author_name_value.isString())
                       {
                           author_name="";
                           author_name = author_name_value.toString();      //歌曲作者信息
                           if(author_name!="")
                           {
                               qDebug()<<author_name;
                           }
                           else
                           {
                               qDebug()<<"未找到author_name"<<endl;
                           }
                       }
                   }
                    //下一篇的歌词获取也是在这里添加代码
                    //图片显示代码在这里添加
                    //解析成功，如果当前有用户登录，且用户进行了双击，那么将用户名以及其点击的歌曲信息加入数据库，方便之后的听歌
                    //插入当前双击的歌曲信息
                    url = play_urlStr;
                    //歌曲信息解析待学习
                    author = author_name;
                    title = audio_name;
                    //                albumTitle = tempPlayer.metaData(QStringLiteral("AlbumTitle")).toString();
                    //                audioBitRate = tempPlayer.metaData(QStringLiteral("AudioBitRate")).toInt();
                    //                duration=tempPlayer.duration();


                   //当前是公共用户，那么将播放的历史歌曲，插入到历史数据库中
                   if(currentuserName.isEmpty())
                   {
                        currentuserName="";/////////////////////
                   }
                   QSqlQuery query;
                   QString insert_sql = "INSERT INTO MusicInfo (userName, url, author, title) VALUES (?, ?, ?, ?)";
                   query.prepare(insert_sql);
                   query.addBindValue(currentuserName);//当前用户名
                   query.addBindValue(url);//当前url
                   query.addBindValue(author);//当前url
                   query.addBindValue(title);//当前url
                   query.exec();
                   //对当前用户的重复歌曲去重
                   QSqlQuery querys;
                   QString removeDupl_sql="DELETE FROM MusicInfo WHERE rowid NOT IN ( SELECT rowid FROM MusicInfo GROUP BY ( userName || 'seprator' || url ) );";
                   querys.exec(removeDupl_sql);
                   if(querys.exec(removeDupl_sql))
                   {
                       qDebug()<<"执行成功！"<<endl;
                   }
                   else
                   {
                       QMessageBox::warning(this,"warning",querys.lastError().text());
                       qDebug()<<"cloudmusicplayer---QSqlQuery::lastError()"<<querys.lastError().text()<<endl;
                   }
               }
               else
               {
                   QMessageBox::warning(this,"歌曲播放失败","当前JSON文件不包含data");
                   qDebug()<<"出错";
               }
           }
       }
    }

}
void CloudMusicPlayer::doProcessSetting()
{
    diaSeting=new dialogSetting1(this);
//    QDialog *setDia=new QDialog(this);
//    setDia->setGeometry(this->geometry().center().x(),this->geometry().center().y(),500,300);
    diaSeting->setWindowTitle("设置");
    diaSeting->setWindowModality(Qt::ApplicationModal);
    diaSeting->show();
    connect(diaSeting,SIGNAL(engineChose(int)),this,SLOT(doProcessengineChose(int)));
//    setWindowFlags(Qt::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);
}

void CloudMusicPlayer::doProcessengineChose(int ind)
{
    Index=ind;
}

void CloudMusicPlayer::doProcessListenRecorder()
{
    if(clickFlag%2!=0)
    {
        file=new QFile();
        file->setFileName("./shibie");
        bool isOpen=file->open(QIODevice::WriteOnly|QIODevice::Truncate);
        if(!isOpen)
        {
            qDebug()<<"文件打开失败！"<<endl;
            return;
        }
        QAudioFormat format;
        format.setSampleRate(8000);
        format.setChannelCount(1);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);
        QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        QString str=info.deviceName();
        qDebug()<<"使用的录音设备是:"<<str<<endl;
        if(!info.isFormatSupported(format))
        {
            format = info.nearestFormat(format);
        }
        input = new QAudioInput(format, this);
        ui->btn_Listening->setIcon(QIcon(":/new/prefix1/img/image/duration.png"));
        qDebug()<<"录音开始......"<<endl;
    //    ui->label->setText("录音开始......");
        input->start(file);
    }
    if(clickFlag%2==0)
    {
        input->stop();
        file->close();
        ui->btn_Listening->setIcon(QIcon(":/new/prefix1/img/image/music-playing.png"));
        qDebug()<<"录音结束......"<<endl;
//        ui->label->setText("录音结束......");
    }


/*
 * 接下来可以使用paddlepaddle平台的音频识别软件对录音识别，从而达到音频输入
 * 或者使用paddlepaddle平台的音频识别软件对该音频进行搜索匹配，找到对应歌曲，即听歌识曲
*/


/*
 * 对录音进行播放
    if(clickFlag==3)
    {
        file->setFileName("./shibie");
        file->open(QIODevice::ReadOnly);

        QAudioFormat format;
        format.setSampleRate(8000);
        format.setChannelCount(1);
        format.setSampleSize(8);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);
        output = new QAudioOutput(format);
        output->start(file);
    }
*/
    ++clickFlag;
}
