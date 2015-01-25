#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T21:14:45
#
#-------------------------------------------------

QT       += core \
            gui \
            xml \
            multimedia \
            multimediawidgets

CONFIG += qt \
        release

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Movie
TEMPLATE = app


SOURCES += \
    src/mainwindow.cxx \
    src/main.cxx \
    src/dockwidget.cxx \
    src/centerwidget.cxx \
    src/videowidget.cxx \
    src/musicwidget.cxx \
    src/picturewidget.cxx \
    src/textwidget.cxx

HEADERS  += \
    src/mainwindow.h \
    src/dockwidget.h \
    src/centerwidget.h \
    src/videowidget.h \
    src/musicwidget.h \
    src/picturewidget.h \
    src/textwidget.h

RESOURCES += \
    src/res/resource.qrc

ICON = src/res/Archaia.icns ##set app icon

RCC_DIR += ./rcc

DESTDIR += ./bin

MOC_DIR += ./moc

#指定目标文件(obj)的存放目录
OBJECTS_DIR += ./obj

DISTFILES +=


