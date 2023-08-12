#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "item.h"
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define RECT_WIDTH 30
#define RECT_HIGHT 30

#define START_X 100
#define START_Y 100

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int timenum;//总用时间
    int flagnum;//旗帜数
    int timestart=1;//用于启动计数器，让计时器只启动一次
    QTimer *timer = new QTimer(this);//计时器
    void DrawTimeandFlag();//显示用时和旗帜数

    void InitItems();//随机初始化雷点位置
    void ReleaseItems();

    void NewGame(); //新开一局游戏
    void GameFail(); //点到雷，游戏失败
    bool FindAll(); //是否找到所有雷
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void OnMenuNewGame();
    void OnMenuLevel1();
    void OnMenuLevel2();
    void OnMenuLevel3();

private:
//    QPixmap bgimage;
//    void resizeEvent(QResizeEvent *event);

    void DrawChessboard();
    void DrawItems(); //绘制所有格子
    void DrawItem(QPainter& painter,Item* pItem);//绘制单个格子

    void OpenEmptyItem(QPoint pt);//点击空白元素(相邻雷数为0)时，递归查找相邻的空白元素，以及空白元素附近的数字元素(数字是雷数)
    bool PointInGameArea(QPoint pt);//判断坐标是否超过游戏区域

private:
    Ui::MainWindow *ui;
    QPixmap mFlagImage; //小红旗图片
    QPixmap mBombImage; //雷图片

    int mRows; //行数
    int mColumes; //列数
    int mCountMine; //雷数
    QVector<QPoint> mMines; //雷的坐标点
    QVector<QVector<Item*>> mItems; //所有元素
    bool mIsGameFail; //是否是游戏失败，失败了需要显示雷
};
#endif // MAINWINDOW_H
