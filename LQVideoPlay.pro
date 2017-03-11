#-------------------------------------------------
#
# Project created by QtCreator 2017-01-22 T21:34:59
#
#-------------------------------------------------

QT       += core gui sql network webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQVideoPlay
TEMPLATE = app

CONFIG  +=debug_and_release
CONFIG(debug,debug|release){
    TARGET  = LQVideoPlay
    DESTDIR = $$PWD/bin/debug/
}else{
    TARGET  = LQVideoPlay
    DESTDIR = $$PWD/bin/release/
}
win32{
    LIBS    +=$$PWD/Lib/vlc/lib/libvlc.dll
    LIBS    +=$$PWD/Lib/vlc/lib/libvlccore.dll
}
unix{
    LIBS    +=$$PWD/Lib/vlc/lib/libvlc.so
}

include($$PWD/Src/Ui/Ui.pri)
include($$PWD/Src/BLL/Bll.pri)
include($$PWD/Src/Api/Api.pri)

INCLUDEPATH += $$PWD/Src/Ui
INCLUDEPATH += $$PWD/Src/Ui/TitleWidget
INCLUDEPATH += $$PWD/Src/Ui/ContentWidget
INCLUDEPATH += $$PWD/Src/Ui/StatusWidget
INCLUDEPATH += $$PWD/Src/BLL
INCLUDEPATH += $$PWD/Src/Api
INCLUDEPATH += $$PWD/Lib/vlc/include


MOC_DIR = temp/moc
RCC_DIR = temp/rcc
OBJECTS_DIR = temp/obj
UI_HEADERS_DIR = temp/ui

SOURCES += \
    Src/main.cpp

RESOURCES += \
    image.qrc
