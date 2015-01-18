#include "mainwindow.h"

//qt
#include <QMovie>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Movie Show");

    //doc widget
    myDockWidget = new DockWidget();
    myDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,myDockWidget);

    //center widget
    myCenterWidget = new CenterWidget();
    setCentralWidget(myCenterWidget);

    connect(myDockWidget,SIGNAL(signalUpdatePlaylist(QMediaPlaylist*)),
            myCenterWidget,SLOT(slotUpdatePlaylist(QMediaPlaylist*)));
    connect(this,SIGNAL(signalUpdatePlaylist(QMediaPlaylist*)),myCenterWidget,SLOT(slotUpdatePlaylist(QMediaPlaylist*)));


    setMinimumSize(QSize(800,600));

}

void MainWindow::slotPositionChanged(qint64 pos)
{

    qDebug()<<"position of the mp3 is :"<<pos;

}
