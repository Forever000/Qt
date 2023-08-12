#include "chess.h"
#include "ui_chess.h"

Chess::Chess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chess)
{
    ui->setupUi(this);
    Init();
    InitChess();
}

Chess::~Chess()
{
    delete ui;
}
////////////////////////////event///////////////////////////////////
void Chess::paintEvent(QPaintEvent *)
{
    //在当前页面画图
    QPainter painter(this);
    //画矩形
    QRect ret(QPoint(0,0),QPoint(this->width(),this->height()));
    //代码优化：优先使用构造函数对创建的对象初始化，这样更节约资源，节约程序运行时间
    //ret.setTopLeft(QPoint(0,0));
    //ret.setBottomRight(QPoint(this->width(),this->height()));
    QPixmap pixmap(bg_filename);
    painter.drawPixmap(ret,pixmap);


    ////////////////////////////////////画棋盘/////////////////////////////////
    QPen pen1;
    pen1.setColor(lineColor);
    pen1.setStyle(lineStyle);
    pen1.setWidth(lineWidth);
    painter.setPen(pen1);

    for(int i=0;i<=8;i++)
    {
        //通过画出前2条横线，找出规律
        //painter.drawLine(startX,startY,9*gridWidth,startY);
        //painter.drawLine(startX,startY+gridHeight,9*gridWidth,startY+gridHeight);
        painter.drawLine(startX,startY+i*gridHeight,9*gridWidth,startY+i*gridHeight);
        //painter.drawLine(startX,startY,startX,9*gridHeight);
        painter.drawLine(startX+i*gridWidth,startY,startX+i*gridWidth,9*gridHeight);

    }
    /////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////画棋子////////////////////////////////
    //第一个格子的棋子
    //painter.drawPixmap(startX,startY,gridWidth,gridHeight,QPixmap("../Chessgame/img/ches.jpg"));

    QString chessColor;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(chessData[i][j] == White)
            {
                chessColor="../Chessgame/img/white.jpg";
            }
            else if(chessData[i][j] == Black)
            {
                chessColor="../Chessgame/img/black.jpg";
            }
            else
            {
                chessColor.clear();
                continue;
            }

            painter.drawPixmap(startX+i*gridWidth,startY+j*gridHeight,gridWidth,gridHeight,QPixmap(chessColor));
        }
    }






    /////////////////////////////////////////////////////////////////////////

}
void Chess::resizeEvent(QResizeEvent *event)
{
    gridWidth=event->size().width()/GRIDCOUNT;
    gridHeight=event->size().height()/GRIDCOUNT;
    startX=gridWidth;
    startY=gridHeight;
    qDebug()<<"startX:"<<startX<<"startY:"<<startY<<endl;
}
void Chess::mousePressEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();

    if(x>=startX && (x<=startX+8*gridWidth))
    {
        if(y>=startY && (y<=startY+8*gridHeight))
        {
            //判断点击的是哪一个格子
            int i=0,j=0;
            i=(x-startX)/gridWidth;
            j=(y-startY)/gridHeight;
//            qDebug()<<"i:"<<i<<"j:"<<j<<endl;
//            chessData[i][j]=Black;
//            this->update();
            SignalSendChessDate(i,j);
        }
    }
}
////////////////////////////event End///////////////////////////////////

void Chess::Init()
{
    bg_filename.clear();
    bg_filename="../Chessgame/img/01.jpg";
    lineColor=Qt::blue;
    lineStyle=Qt::SolidLine;
    lineWidth=2;


}

void Chess::InitChess()
{
    //初始化棋盘数据
    //memset(chessData,0,sizeof(int)*64);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            chessData[i][j]=Empty;
        }
    }

//    chessData[3][3]=Black;
//    chessData[3][4]=White;
//    chessData[4][3]=White;
//    chessData[4][4]=Black;

}

//////////////////////////自定义用户接口//////////////////////////////////
void Chess::ChangeBGIMG(const QString filename)
{
    this->bg_filename=filename;
    this->update();
}

void Chess::ChangeLine(const QColor color, const Qt::PenStyle style, const int width)
{
    this->lineColor=color;
    this->lineStyle=style;
    this->lineWidth=width;
    this->update();
}

void Chess::setChessStatus(void *p)
{
    //将当前的值拷贝到棋子数据控制容器中
    memcpy(chessData,p,sizeof(int)*8*8);
    this->update();
}
