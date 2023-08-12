#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include<QPainter>
#include<QDebug>
#include<QResizeEvent>
#include<QMouseEvent>
#define GRIDCOUNT 10

namespace Ui {
class Chess;
}

class Chess : public QWidget
{
    Q_OBJECT

public:
    explicit Chess(QWidget *parent = 0);
    ~Chess();
    //定义棋子的枚举类型
    enum ChessType
    {
        Empty=0,
        White,
        Black
    };


    //为外部提供一个接口来改变bg_filename值      这是面向对象的特点
    void ChangeBGIMG(const QString bg_filename);
    //改变线的颜色、样式、宽度等等
    void ChangeLine(const QColor color,const Qt::PenStyle style,const int width);

    void setChessStatus(void *p);

protected:
    //绘图事件
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *event);

signals:
    void SignalSendChessDate(int i,int j);

private:
    Ui::Chess *ui;

    QString bg_filename;
    QColor lineColor;
    Qt::PenStyle lineStyle;
    int lineWidth;
    //设置网格的宽度、高度、画线的起始点
    int gridWidth,gridHeight,startX,startY;

    //保存棋子的数据
    int chessData[8][8];

    void Init();
    //初始化棋盘
    void InitChess();
};

#endif // CHESS_H
