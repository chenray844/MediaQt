#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T21:14:45
#
#-------------------------------------------------

QT       += core gui xml

CONFIG += qt release

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Movie
TEMPLATE = app


SOURCES += \
    src/mainwindow.cxx \
    src/main.cxx

HEADERS  += \
    src/mainwindow.h

DESTDIR += ./bin

#CONFIG += qt release

MOC_DIR += ./moc

#指定目标文件(obj)的存放目录
OBJECTS_DIR += ./obj
