#ifndef CHESSFORM_H
#define CHESSFORM_H

#include <QWidget>
#include"chess.h"
#include<QPainter>

namespace Ui {
class chessForm;
}

class chessForm : public QWidget
{
    Q_OBJECT

public:
    explicit chessForm(QWidget *parent = 0);
    ~chessForm();

protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_btn_pvp_clicked();
    //处理棋盘发送过来的信号
    void doProcessChessData(int i,int j);
    void on_btn_pvc_clicked();

private:
    Ui::chessForm *ui;
    enum PKType
    {
        PVP,
        PVC,
        NVN
    };
    PKType currentPK;

    Chess *myChess;
    Chess::ChessType currentRole;//当前谁先下
    int formChessData[8][8];

    void Init();

    ///x,y为棋盘的坐标，chess为棋子的状态（棋子数据二维数组），currentRole为枚举变量，
    ///eatChess为判断是否吃子，true代表可以吃子，false判断有子可吃
    ///返回值为能吃子的个数
    int judgeRule(int x,int y,void *chess,Chess::ChessType currentRole,bool eatChess);

    void RoleInit(const QString whiteFilename,const QString blackFilename);

    void setRole(Chess::ChessType currentRole);

    void setChessInit();//棋盘初始化

    void RoleChange();

    void ChessCount();//棋盘数据的统计

    void RebootRole(Chess::ChessType role);//机器下子
};

#endif // CHESSFORM_H
