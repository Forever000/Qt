#ifndef QMUSIC_H
#define QMUSIC_H

#include <QWidget>
#include<QMediaPlayer>
#include<QAudioOutput>
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

namespace Ui {
class QMusic;
}

class QMusic : public QWidget
{
    Q_OBJECT

public:
    explicit QMusic(QWidget *parent = 0);
    ~QMusic();

private:
    Ui::QMusic *ui;
    void Init();
    bool m_IsPlaying = false;//播放器当前状态为停止
    QAudioOutput *audioOuput;//音频输出对象
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
    bool isPressQMusicWidget;

    QMenu *menu_changeSkin;





private slots:
    void doProcess_btn_openfileClick();
    void doProcess_btn_preClick();
    void doProcess_btn_playClick();
    void doProcess_btn_nextClick();
    void doProcess_btn_volumeClick();
    void doProcess_btn_AboutClick();
    void doProcess_btn_About2Click();
    void doProcess_btn_MinmumClick();
    void doProcess_btn_QuitClick();
    void doProcessitemDoubleClicked(QListWidgetItem* item);
    void doProcessVolumevalueChanged(int num);
    void doProcessdurationChanged(qint64 duration);
    void doProcesspositionChanged(qint64 pos);
    //系统托盘点击事件
    void systemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason);
    //换肤功能
    void doProcessbtn_SkinClick();

    void doProcessbtnbackgroud_to_default();
    void doProcessbtnbackgroud_to_custom();



};

#endif // QMUSIC_H
