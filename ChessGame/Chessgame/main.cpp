#include"chessform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Chess w;
//    w.show();
    chessForm w;
    w.show();

    return a.exec();
}
