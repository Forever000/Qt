#ifndef ITEM_H
#define ITEM_H

#include <QPoint>

class Item{
public:
    Item();
    Item(QPoint pos);
    QPoint mPos; //位置

    bool mIsMine;	//是否是雷
    bool mMarked;	//是否已标记为雷

    int mNumber;	//数字
    bool mIsOpen;   //是否已打开，且非雷

};

#endif // ITEM_H




