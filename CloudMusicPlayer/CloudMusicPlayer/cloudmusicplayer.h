#ifndef CLOUDMUSICPLAYER_H
#define CLOUDMUSICPLAYER_H

#include <QWidget>
#include<QMediaPlayer>
#include<QListWidgetItem>
#include<QPaintEvent>
#include<QPainter>
#include<QSystemTrayIcon>
#include<QAction>
#include<QMenu>
#include<QPoint>
#include<QMouseEvent>
#include<QApplication>
#include<QCursor>
#include<QSettings>
#include"loginwidget.h"
#include"userregister.h"
#include<QDialog>
#include<QLayoutItem>
#include<QNetworkReply>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QString>
#include<QVector>
#include<QTableWidgetItem>
#include"dialogsetting1.h"
#include"cloudjson.h"
#include"kugoujson.h"
#include<QAudioFormat>
#include<QAudioInput>
#include<QAudioOutput>

namespace Ui {
class CloudMusicPlayer;
}

class CloudMusicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit CloudMusicPlayer(QWidget *parent = 0);
    ~CloudMusicPlayer();

private:
    Ui::CloudMusicPlayer *ui;
    //手动绑定信号槽，对象初始化
    void Init();
    //播放器当前状态为停止，实际上QMediaPlayer提供有专门的接口
    bool m_IsPlaying = false;
    QMediaPlayer *mediaPlayer;//媒体播放对象

    //使用绘图事件，设置背景图
    void paintEvent(QPaintEvent *);//绘图事件在运行的时候自动被调用

    //系统托盘
    QSystemTrayIcon *mySystemTray;
    //初始化系统托盘
    void InitSystemTrayIcon();

    //重写鼠标事件，实现拖动窗口移动
    QPoint m_lastPos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    /*
     * 如果仅重写鼠标事件，则会导致在按住当前界面上的控件时，
     * 当按住这个动作一直存在并将鼠标从控件移动到QWidget的区域时，
     * 界面也会跟着移动，并且这样的移动时直接跳了过去，这样就很不完美，
     * 而且在界面很小，控件很多的情况下，拖动显得非常卡顿，
     * 所以我们就需要在mouse事件中添加一个判断，
     * 判断当前鼠标按下是否是处于QWidget所在的区域。
    */
    bool isPressQMusicWidget;//标志位

    //皮肤切换菜单
    QMenu *menu_changeSkin;

    //使用dialog装填登录和注册界面
    QDialog *dialog;
    loginWidget *loginwidget;
    userRegister *userRegisterPage;

    //接收当前登录的用户名
    QString currentuserName;

    //歌曲信息
    QUrl url;
    //歌手
    QString author;
    //歌曲名
    QString title;
    //时长
    qint64 duration;
    //唱片集
    QString albumTitle;
    //比特率
    int audioBitRate;

    //动态数组存储歌曲的哈希编码、专辑的ID
    QVector<QString> m_Vectorlist;
    QVector<QString> m_ID;
    //网络搜索及JSON文件解析
    //网络功能对象、函数
    QNetworkAccessManager * network_manager;
    QNetworkRequest * network_request;
    QNetworkAccessManager * network_manager2;
    QNetworkRequest * network_request2;
    void replyFinished2(QNetworkReply *reply);
    void parseJson(QString json);//解析歌曲列表
    void parseJsonSongInfo(QString json);//解析单独歌曲信息

    //通过标志位判断当前聚焦的是哪个列表，从而对当前列表进行顺序播放
    QString This_Widget;

    dialogSetting1 *diaSeting;

    int Index=0;
    QString searchLink;
    QString KGAPISTR;
    QVector<int> m_musicId;

    bool invalidMediaDialogShown = false;
    cloudJson *JsonCloud;
    kugouJson *JsonKugou;

    QFile *file;
    QAudioInput *input;
    QAudioOutput *output;

    int clickFlag=1;


private slots:
    //按钮信号槽
    void doProcess_btn_openfileClick();
    void doProcess_btn_preClick();
    void doProcess_btn_playClick();
    void doProcess_btn_nextClick();
    void doProcess_btn_volumeClick();
    void doProcess_btn_AboutClick();
    void doProcess_btn_About2Click();
    void doProcess_btn_MinmumClick();
    void doProcess_btn_QuitClick();
    void doProcessbtn_User();
    //换肤功能
    void doProcessbtn_SkinClick();
    void doProcessbtnbackgroud_to_default();
    void doProcessbtnbackgroud_to_custom();
    //滑动条控制音乐播放进度
    void doProcessdurationChanged(qint64 duration);
    void doProcesspositionChanged(qint64 pos);
    //鼠标双击播放音乐事件
    void doProcessitemDoubleClicked(QListWidgetItem* item);
    //音量调节
    void doProcessVolumevalueChanged(int num);
    //系统托盘点击事件
    void systemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason);
    //接收登录成功信号
    void receive_signal_loginSuccess(QString);
    //更新Dialog中的登录或注册窗口
    void UpdateDialogWidget();
    void reloadloginwidgetTodialog();
    //网络搜索功能槽函数
    void doProcessbtn_searchClick();//点击开始搜索
    //accessmanager获取数据完成
    void finished_slot(QNetworkReply* reply);
    //双击播放修复
    void tableWidget_cellDoubleClicked(QTableWidgetItem* item);
    //对话框修复
    void doProcessCloseloginwidgetORuserRegisterPage();

    void doProcessSetting();

    void doProcessengineChose(int);

    void doProcessListenRecorder();
};

#endif // CLOUDMUSICPLAYER_H
