#include "chessform.h"
#include "ui_chessform.h"

chessForm::chessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessForm)
{
    ui->setupUi(this);
    Init();
}

chessForm::~chessForm()
{
    delete ui;
}
/////////////////function////////////////////
void chessForm::Init()
{
    QStringList arry;
    arry.append("白子先");
    arry.append("黑子先");
    ui->cbox_item->addItems(arry);

    RoleInit("../Chessgame/img/white.jpg","../Chessgame/img/black.jpg");
    currentRole=Chess::Empty;

    //申请棋盘类空间
    myChess=new Chess();

    //绑定
    connect(myChess,SIGNAL(SignalSendChessDate(int,int)),this,SLOT(doProcessChessData(int,int)));
    //将棋盘显示在容器中
    ui->gridLayout->addWidget(myChess);
}

void chessForm::RoleInit(const QString whiteFilename, const QString blackFilename)
{
    ui->lbl1->setPixmap(QPixmap(whiteFilename));
    ui->lbl1->setScaledContents(true);

    ui->lbl2->setPixmap(QPixmap(blackFilename));
    ui->lbl2->setScaledContents(true);
}

void chessForm::setRole(Chess::ChessType role)
{
    currentRole=role;
    if(role==Chess::Black)
    {
        ui->lbl1->setVisible(false);
        ui->lbl2->setVisible(true);
    }
    else
    {
        ui->lbl1->setVisible(true);
        ui->lbl2->setVisible(false);
    }
    ui->lcdNumber1->display(0);
    ui->lcdNumber2->display(0);
}

void chessForm::setChessInit()
{
    //初始化棋盘数据
    //memset(formChessData,0,sizeof(int)*64);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            formChessData[i][j]=Chess::Empty;
        }
    }

    formChessData[3][3]=Chess::Black;
    formChessData[3][4]=Chess::White;
    formChessData[4][3]=Chess::White;
    formChessData[4][4]=Chess::Black;

    myChess->setChessStatus(formChessData);

    ui->lcdNumber1->display(2);
    ui->lcdNumber2->display(2);
}

void chessForm::RoleChange()
{
    if(currentRole == Chess::White)
    {
        currentRole = Chess::Black;
    }
    else
    {
        currentRole = Chess::White;
    }
    if(currentRole==Chess::Black)
    {
        ui->lbl1->setVisible(false);
        ui->lbl2->setVisible(true);
    }
    else
    {
        ui->lbl1->setVisible(true);
        ui->lbl2->setVisible(false);
    }
}

void chessForm::ChessCount()
{
    int blackCount=0,whiteCount=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(formChessData[i][j] == Chess::White)
            {
                whiteCount++;
            }
            else if(formChessData[i][j] == Chess::Black)
            {
                blackCount++;
            }
        }
    }
    ui->lcdNumber1->display(whiteCount);
    ui->lcdNumber2->display(blackCount);
}

void chessForm::RebootRole(Chess::ChessType role)
{
    int flag=0;
    int ret,oldret=0;
    int c_i,c_j;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            //遍历判断能否下子
            if(formChessData[i][j]==Chess::Empty)
            {
                ret=judgeRule(i,j,formChessData,role,false);
                if(ret>oldret)
                {
                    flag++;
                    c_i=i,c_j=j;
                    oldret=ret;
                }
            }
        }
    }
    if(flag)
    {
        //能下子
        judgeRule(c_i,c_j,formChessData,role,true);
        myChess->setChessStatus(formChessData);

        //切换界面显示
        RoleChange();
    }
    else
    {
        RoleChange();
    }

}
/////////////////////////////待思考////////////////////////////////////
int chessForm::judgeRule(int x, int y, void *chess, Chess::ChessType currentRole, bool eatChess)
{
    //棋盘的8个方向
    int dir[8][2]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    int temp_x=x,temp_y=y;
    int i=0,eatNum=0;
    typedef int (*p)[8];//行指针
    p chessFlag=p(chess);

    if(chessFlag[temp_x][temp_y] != Chess::Empty)
    {
        return 0;
    }

    for(i=0;i<8;i++)
    {
        //准备判断相邻棋子
        temp_x+=dir[i][0];
        temp_y+=dir[i][1];
        if((temp_x<8 && temp_x>=0 && temp_y<8 && temp_y>=0)
                &&(chessFlag[temp_x][temp_y]!=currentRole) && (chessFlag[temp_x][temp_y]!=Chess::Empty))
        {
            temp_x+=dir[i][0];
            temp_y+=dir[i][1];
            while(temp_x<8 && temp_x>=0 && temp_y<8 && temp_y>=0)
            {
                if(chessFlag[temp_x][temp_y]==Chess::Empty)
                {
                    break;
                }
                if(chessFlag[temp_x][temp_y]==currentRole)
                {
                    if(eatChess==true)
                    {
                        chessFlag[x][y]=currentRole;
                        temp_x-=dir[i][0];
                        temp_y-=dir[i][1];
                        while((temp_x!=x)||(temp_y!=y))
                        {
                            chessFlag[temp_x][temp_y]==currentRole;
                            temp_x-=dir[i][0];
                            temp_y-=dir[i][1];
                            eatNum++;
                        }
                    }
                    else
                    {
                        temp_x-=dir[i][0];
                        temp_y-=dir[i][1];
                        while((temp_x!=x)||(temp_y!=y))
                        {
                            temp_x-=dir[i][0];
                            temp_y-=dir[i][1];
                            eatNum++;
                        }
                    }
                    break;
                }
                temp_x+=dir[i][0];
                temp_y+=dir[i][1];
            }
        }
        temp_x=x;
        temp_y=y;
    }
    return eatNum;

}
///////////////////event/////////////////////
void chessForm::paintEvent(QPaintEvent *)
{
    //画背景
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap("../Chessgame/img/01.jpg"));
}

//////////////////////slots//////////////////

void chessForm::on_btn_pvp_clicked()
{
    currentPK=PVP;
    //界面初始化
    if(ui->cbox_item->currentText().contains("白"))
    {
        setRole(Chess::White);
    }
    else
    {
        setRole(Chess::Black);
    }
    //棋盘初始化
    setChessInit();
}

void chessForm::doProcessChessData(int i, int j)
{
    qDebug()<<"i："<<i<<"j："<<j<<endl;
    int ret=judgeRule(i,j,formChessData,currentRole,true);
    if(ret)
    {
        //数据送给棋盘，用于更新界面
        myChess->setChessStatus(formChessData);
        if(currentPK==PVP)
        {
            //角色转换
            RoleChange();
            //数据统计
            ChessCount();
        }
        else if(currentPK == PVC)
        {
            //角色转换
            RoleChange();

            //机器下子
            RebootRole(currentRole);

            //数据统计
            ChessCount();

        }

    }
}
////////////////////////end/////////////////////////////////////


//////////////////////////////PVC///////////////////////////////


void chessForm::on_btn_pvc_clicked()
{
    currentPK=PVC;
    //界面初始化
    if(ui->cbox_item->currentText().contains("白"))
    {
        setRole(Chess::White);
    }
    else
    {
        setRole(Chess::Black);
    }
    //棋盘初始化
    setChessInit();
}
