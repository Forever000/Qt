#include "item.h"

Item::Item()
{
    mPos = QPoint(-1,-1);

    mNumber = 0;
    mIsMine = false;
    mMarked = false;
    mIsOpen = false;
}

Item::Item(QPoint pos)
{
    mPos = pos;

    mNumber = 0;
    mIsMine = false;
    mMarked = false;
    mIsOpen = false;
}

