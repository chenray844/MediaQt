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
    QPixmap pix(100,100);
    pix.fill(Qt::black);

    //setWindowIcon(QIcon(":/images/top-level/Archaia.png"));
    //setWindowIconText("Test Icon");

    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *lb = new QLabel("SHOW");
    layout->addWidget(lb);
    QMovie *movie = new QMovie("/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/animation.gif");
    lb->setMovie(movie);
    movie->start();

    QLabel *lbi = new QLabel();
    lbi->setPixmap(pix);
    layout->addWidget(lbi);

    //layout->addWidget(lb);
    QWidget *widget = new QWidget();

    //QMediaPlayer *player = new QMediaPlayer();
    //connect(player,SIGNAL(positionChanged(qint64)),
    //        this,SLOT(slotPositionChanged(qint64)));
    //player->setMedia(QUrl::fromLocalFile("/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/music1.mp3"));
    //player->setVolume(50);
    //player->play();

    QString filename = "/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/video1.mp4";
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile(filename));

    playlist->setCurrentIndex(0);
    QMediaPlayer *player = new QMediaPlayer();
    player->setPlaylist(playlist);

    QVideoWidget *videoWidget = new QVideoWidget();
    //videoWidget->adjustSize();
    videoWidget->resize(QSize(300,300));
    player->setVideoOutput(videoWidget);
    player->play();




    myPositionLabel = new QLabel();
    myPositionLabel->setText("Hello Movie Show");
    qDebug()<<"Hello Test Debug";
    //layout->addWidget(myPositionLabel);

    layout->addWidget(videoWidget);
    layout->addWidget(myPositionLabel);
    //layout->addStretch(0);

    widget->setLayout(layout);
    //setLayout(layout);
    //setCentralWidget(lb);

    myDockWidget = new DockWidget();
    //myDockWidget->setWindowIcon(QIcon(":/images/top-level/Archaia.png"));

    this->addDockWidget(Qt::LeftDockWidgetArea, myDockWidget);

    myCenterWidget = new CenterWidget();
    //myCenterWidget->setWindowIcon(QIcon(":/images/top-level/Archaia.png"));
    //setCentralWidget(myCenterWidget);

    setCentralWidget(widget);
    //setCentralWidget(videoWidget);
    setMinimumSize(QSize(800,600));

}

void MainWindow::slotPositionChanged(qint64 pos)
{

    qDebug()<<"position of the mp3 is :"<<pos;
    myPositionLabel->setText(QString("position %1").arg(pos));
}
