#-------------------------------------------------
#
# Project created by QtCreator 2023-03-18T10:37:34
#
#-------------------------------------------------

QT       += core gui sql multimedia concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQ_v1_1
TEMPLATE = app


SOURCES += main.cpp\
        loginwidget.cpp \
    userregister.cpp \
    qmusic.cpp

HEADERS  += loginwidget.h \
    userregister.h \
    qmusic.h

FORMS    += loginwidget.ui \
    qmusic.ui

RESOURCES += \
    img/res.qrc

DISTFILES += \
    img/image/about.png \
    img/image/add.png \
    img/image/addFromLocal.png \
    img/image/clear.png \
    img/image/current-music.png \
    img/image/default.png \
    img/image/detail.png \
    img/image/dialog-music.png \
    img/image/duration.png \
    img/image/exit.png \
    img/image/favo-music.png \
    img/image/like.png \
    img/image/local-music.png \
    img/image/loop.png \
    img/image/loop2.png \
    img/image/loop-one.png \
    img/image/loop-one2.png \
    img/image/lyric.png \
    img/image/min.png \
    img/image/music.png \
    img/image/music_list.png \
    img/image/music-dir.png \
    img/image/music-file.png \
    img/image/MusicListItem.png \
    img/image/music-playing.png \
    img/image/music-voice.png \
    img/image/myMusicList.png \
    img/image/MyPlayer.png \
    img/image/next.png \
    img/image/next2.png \
    img/image/non-music.png \
    img/image/pase.png \
    img/image/pause2.png \
    img/image/play.png \
    img/image/play2.png \
    img/image/play-random.png \
    img/image/pre.png \
    img/image/pre2.png \
    img/image/quit.png \
    img/image/random2.png \
    img/image/remove.png \
    img/image/remove_dup.png \
    img/image/setting.png \
    img/image/singer.png \
    img/image/skin.png \
    img/image/sliderHandle.png \
    img/image/sort-alpha-asc_ea48_ether.png \
    img/image/systemTrayIcon.png \
    img/image/Title.png \
    img/image/To-like.png \
    img/image/To-playlist.png \
    img/image/volumeHandle.png
