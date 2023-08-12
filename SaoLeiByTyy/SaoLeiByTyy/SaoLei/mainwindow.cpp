#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBar->hide(); //将工具栏隐藏

    connect(ui->menu,SIGNAL(aboutToShow()),this,SLOT(OnMenuNewGame()));
    connect(ui->menu_2,SIGNAL(aboutToShow()),this,SLOT(OnMenu_Settings()));
    connect(ui->actiona, SIGNAL(triggered()), this, SLOT(OnMenuLevel1()));
    connect(ui->actionb, SIGNAL(triggered()), this, SLOT(OnMenuLevel2()));
    connect(ui->actionc, SIGNAL(triggered()), this, SLOT(OnMenuLevel3()));

    mFlagImage=QPixmap(":/flag.png");
    mBombImage=QPixmap(":/bomb.png");

    mRows=9;
    mColumes=9;
    mCountMine=10;
    timenum = 0;
    timestart = 1;
    NewGame();

    connect(timer,&QTimer::timeout,[=](){
        timenum++;
    });

//    //启动定时器
//    QTimer *timer = new QTimer(this);
//    connect(timer,&QTimer::timeout,[=](){
//        static int num=1;
//        ui->timelabel->setText(QString::number(num++));
//    });
//    timer->start(1000);

}
MainWindow::~MainWindow()
{
    delete ui;
}

//随机初始化雷点位置
void MainWindow::InitItems(){
    mMines.clear();
    for(int i=0;i<mCountMine;i++){
        //qsrand()随机生成数 取时间作为产生随机数的种子
        qsrand(QTime::currentTime().msec());
        int x=qrand()%mColumes;
        int y=qrand()%mRows;
        while(mMines.contains(QPoint(x,y))){
            x=qrand()%mColumes;
            y=qrand()%mRows;
        }
        mMines.append(QPoint(x,y));
    }
    //建立2维数组保存所有元素位置，方便索引
    for(int i=0;i<mColumes;i++){
        QVector<Item*> rowItems;
        for(int j=0;j<mRows;j++){
            QPoint pos = QPoint(i,j);
            Item* pItem = new Item(pos);
            if(mMines.contains(pos)){ //该位置是雷
                pItem->mIsMine = true;
            }
            rowItems.append(pItem);
        }
        mItems.append(rowItems);
    }
    //计算雷附近格子的数字
    for(int i=0;i<mColumes;i++){
        for(int j=0;j<mRows;j++){
            if(mItems[i][j]->mIsMine){
                continue;
            }
            int nCountMines = 0;
            //求每个点附近的8个点的是雷的总数
            for(int m=-1;m<=1;m++){
                for(int n=-1;n<=1;n++){
                    if(m==0&&n==0){
                        continue;
                    }
                    QPoint ptNew = QPoint(i+m,j+n);
                    if(!PointInGameArea(ptNew)){
                        continue;
                    }
                    if(mItems[i+m][j+n]->mIsMine){
                        nCountMines++;
                    }
                }
            }
            mItems[i][j]->mNumber = nCountMines;
        }
    }
}
//释放所有格子
void MainWindow::ReleaseItems(){
    for(int i=0;i<mItems.size();i++){
        for(int j=0;j<mItems[i].size();j++){
            if(mItems[i][j]!=NULL){
                delete mItems[i][j];
                mItems[i][j]=NULL;
            }
        }
    }
    mItems.clear();
}
//新开一局游戏
void MainWindow::NewGame(){
    mIsGameFail = false;
    resize(START_X*2+mColumes*RECT_WIDTH,START_Y*2+mRows*RECT_HIGHT);

    ReleaseItems();
    InitItems();
    timenum = 0;
    flagnum = 0;
    timestart = 1;
    timer->stop();
}
//点到雷，游戏失败
void MainWindow::GameFail(){
    mIsGameFail = true;//游戏是否失败 true
    for(int i=0;i<mItems.size();i++){
        for(int j=0;j<mItems[i].size();j++){//i,j循环遍历所有元素
            if(mItems[i][j]->mIsMine){ //若元素是雷
                mItems[i][j]->mMarked = true; //标记为雷
            }
            else{
                mItems[i][j]->mMarked = false; //不标记为雷
                mItems[i][j]->mIsOpen = true; //标记为已经打开，且非雷
            }
        }
    }

}
//是否找到所有雷
bool MainWindow::FindAll(){
    bool bFindAll = true;
    //遍历二维数组QVector<QVector<Item*>> mItems; //所有元素
    for(int i=0;i<mItems.size();i++){
        for(int j=0;j<mItems[i].size();j++){
            Item * pItem = mItems[i][j];
            //只要存在一个雷没被标记，或存在一个非雷没被打开，就不算找完
            if(pItem->mIsMine){
                if(!pItem->mMarked){ //检查是否有雷未被标记
                    bFindAll = false;
                }
            }
            else{
                if(!pItem->mIsOpen){ //检查是否有雷未被打开
                    bFindAll = false;
                }
            }
        }
    }
    return bFindAll;
}
void MainWindow::paintEvent(QPaintEvent *){
    DrawChessboard();
    DrawItems();
    DrawTimeandFlag();
    update();
}
void MainWindow::mousePressEvent(QMouseEvent *e){
    //得到鼠标处的格子坐标
    QPoint pt;
    pt.setX( (e->pos().x() - START_X ) / RECT_WIDTH);
    pt.setY( (e->pos().y() - START_X ) / RECT_HIGHT);
    //是否点在游戏区域内
    if(!PointInGameArea(pt)){
        return;
    }
    //获取所点击的矩形元素
    Item* pItem = mItems[pt.x()][pt.y()];
    //左键打开元素，右键插旗帜标记
    if(e->button() == Qt::LeftButton){

        //第一次点击左键时开始计时，并保证后续不会重复启动start
        if(timestart==1){
            timer->start(1000);
            timestart = 2;
        }

        //不是已标记的或已打开的空白点，也就是未处理的
        if(!pItem->mMarked && !pItem->mIsOpen){
            //若是雷，就GAME OVER
            if(pItem->mIsMine){
                timer->stop();
                QMessageBox::information(NULL,  "GAME OVER","GAME OVER,FAIL!", QMessageBox::Yes , QMessageBox::Yes);
                GameFail();
                return;
            }
            else {
                //打开
                pItem->mIsOpen = true;
                if(pItem->mNumber == 0){
                    //如果数字是0，也就是不含任何相邻雷的元素，那么递归打开所有的相邻数字是0的元素
                    //也就是点到一个空白处，一下打开一大片的效果
                    OpenEmptyItem(pt);
                }
                //如果找到所有雷
                if(FindAll()){
                    timer->stop();
                    QMessageBox::information(NULL,  "GAME OVER","SUCCESS!", QMessageBox::Yes , QMessageBox::Yes);
                    return;
                }
            }
        }
    }
    //右键插旗帜
    else if (e->button() == Qt::RightButton) {
        //已标记过的，取消标记
        if(pItem->mMarked){
            pItem->mMarked = false;
            flagnum-=1;
        }
        else if (!pItem->mIsOpen&&flagnum<mCountMine) {
            //没标记也没打开，就是未处理的，插旗帜标记上
            pItem->mMarked = true;
            flagnum+=1;
            if(FindAll()){
                QMessageBox::information(NULL,  "GAME OVER","SUCCESS!", QMessageBox::Yes , QMessageBox::Yes);
                //GameSuccess();
                return;
            }
        }
        else{
             QMessageBox::information(NULL,  "WARNING","旗帜数量超过了雷数!", QMessageBox::Yes , QMessageBox::Yes);
        }
    }
}


void MainWindow::OnMenuNewGame(){
    NewGame();
}
//更新扫雷的难度
void MainWindow::OnMenuLevel1(){
    mRows = 9;
    mColumes = 9;
    mCountMine = 10;
    NewGame();
}
void MainWindow::OnMenuLevel2(){
    mRows = 16;
    mColumes = 16;
    mCountMine = 40;
    NewGame();
}
void MainWindow::OnMenuLevel3(){
    mRows = 16;
    mColumes = 30;
    mCountMine = 99;
    NewGame();
}


void MainWindow::DrawChessboard(){ //更新画板
    QPainter painter(this);
    painter.setBrush(QPixmap(":/bg2.jpg"));
    painter.drawRect(0,0,width(),height());
}
void MainWindow::DrawItems(){//绘画项目区域
    QPainter painter(this);
    painter.setBrush(Qt::lightGray);
    painter.setPen(QPen(QColor(Qt::black),2));
    for(int i=0;i<mColumes;i++){
        for(int j=0;j<mRows;j++){
            DrawItem(painter,mItems[i][j]);
        }
    }
}
void MainWindow::DrawItem(QPainter& painter,Item* pItem){
    if(pItem->mMarked){
        if(mIsGameFail){
            //游戏结束，显示为雷
            QRect rcSrc(0,0,mFlagImage.width(),mFlagImage.height());
            QRect rcTarget(START_X+pItem->mPos.x()*RECT_WIDTH+2,START_Y+pItem->mPos.y()*RECT_HIGHT+2,RECT_WIDTH-4,RECT_HIGHT-4);
            painter.drawPixmap(rcTarget,mBombImage,rcSrc);//显示雷的图片和位置
        }
        else{
            //游戏没有结束，显示为棋子
            QRect rcSrc(0,0,mFlagImage.width(),mFlagImage.height());
            QRect rcTarget(START_X+pItem->mPos.x()*RECT_WIDTH+2,START_Y+pItem->mPos.y()*RECT_HIGHT+2,RECT_WIDTH-4,RECT_HIGHT-4);
            painter.drawPixmap(rcTarget,mFlagImage,rcSrc);
        }
        painter.setBrush(Qt::transparent);
        painter.drawRect(START_X+pItem->mPos.x()*RECT_WIDTH,START_Y+pItem->mPos.y()*RECT_HIGHT,RECT_WIDTH,RECT_HIGHT);
        return;
    }
    else if(pItem->mIsOpen){
        if(pItem->mNumber == 0){
            painter.setBrush(Qt::white);
        }
        else{
            QFont font;
            font.setPointSize(20);
            font.setFamily("msyh");
            font.setBold(true);
            painter.setBrush(Qt::white);
            painter.drawRect( START_X + pItem->mPos.x()*RECT_WIDTH,START_Y + pItem->mPos.y()*RECT_HIGHT,RECT_WIDTH,RECT_HIGHT);

            painter.setBrush(Qt::black);
            painter.setFont(font);
            painter.drawText( START_X + pItem->mPos.x()*RECT_WIDTH  + 8,START_Y + pItem->mPos.y()*RECT_HIGHT + 22,QString("%1").arg(pItem->mNumber));
            return;
        }
    }
    else{
        painter.setBrush(QPixmap(":/bg.jpg"));
    }
    painter.drawRect(START_X + pItem->mPos.x()*RECT_WIDTH,START_Y + pItem->mPos.y()*RECT_HIGHT,RECT_WIDTH,RECT_HIGHT);
}
//运气好时点到一个空白元素，可能打开挨着的一大片
void MainWindow::OpenEmptyItem(QPoint pt){
    //对于空白元素，有上下左右4个方向挨着的空白元素，就打开继续查找空白元素
    QVector<QPoint> directions;
    directions.push_back(QPoint(-1,0));
    directions.push_back(QPoint(1,0));
    directions.push_back(QPoint(0,-1));
    directions.push_back(QPoint(0,1));
    for(int i=0;i<directions.size();i++){
        QPoint ptNew = pt+directions[i];
        if(!PointInGameArea(ptNew)){
            continue;
        }
        Item * pItem = mItems[ptNew.x()][ptNew.y()];
        if(!pItem->mIsMine && !pItem->mIsOpen && !pItem->mMarked && pItem->mNumber == 0){
            pItem->mIsOpen = true;
            //对于找到的空白元素，在它的8个方向上有数字元素就打开
            QVector<QPoint> directions2 = directions;
            directions2.push_back(QPoint(-1,-1));
            directions2.push_back(QPoint(1,1));
            directions2.push_back(QPoint(1,-1));
            directions2.push_back(QPoint(-1,1));
            for(int j=0; j<directions2.size();j++){
                QPoint ptNew2 = ptNew + directions2[j];
                if(!PointInGameArea(ptNew2)){
                    continue;
                }
                Item* pItem2 = mItems[ptNew2.x()][ptNew2.y()];
                if(!pItem2->mIsMine && !pItem2->mIsOpen && !pItem2->mMarked && pItem2->mNumber > 0){
                    pItem2->mIsOpen = true;
                }
            }
            //递归查询上下左右4个方向的空白元素
            OpenEmptyItem(ptNew);
        }

    }
}
//判断坐标是否超过游戏区域
bool MainWindow::PointInGameArea(QPoint pt){
    if(pt.x()>=0&&pt.x()<mColumes&&pt.y()>=0&&pt.y()<mRows){
        return true;
    }
    return false;
}

void MainWindow::DrawTimeandFlag(){
    QPainter painter1(this);
    QFont font;
    font.setPointSize(13);
    font.setFamily("宋体");
    painter1.setBrush(Qt::black);
    painter1.setFont(font);
    painter1.drawText(100,80,"时间："+QString::number(timenum)+"秒");
    painter1.drawText(250,80,"旗帜："+QString::number(flagnum)+"个");
}


