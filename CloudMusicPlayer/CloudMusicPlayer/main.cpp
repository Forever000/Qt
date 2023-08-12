#include "cloudmusicplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CloudMusicPlayer w;
    w.show();

    return a.exec();
}
