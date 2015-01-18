#include "dockwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QToolButton>
#include <QAction>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMovie>
#include <QMediaPlaylist>

DockWidget::DockWidget(QWidget *parent)
    :QDockWidget(parent)
{
    QWidget *widget = new QWidget();

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *lb = new QLabel();
    layout->addWidget(lb);
    QMovie *movie = new QMovie("/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/animation.gif");
    lb->setMovie(movie);
    movie->start();

    QPushButton *btn = new QPushButton("Test Movie Show");
    btn->setIcon(QIcon(":/images/top-level/view.png"));
    layout->addWidget(btn);

    layout->addStretch(1);

    widget->setLayout(layout);

    setWidget(widget);

    //playlist
    myPlaylist = new QMediaPlaylist();

    connect(btn,SIGNAL(clicked()),this,SLOT(slotAddPlaylist()));
}

void DockWidget::slotAddPlaylist()
{
    QString filename = "/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/video1.mp4";
    myPlaylist->addMedia(QUrl::fromLocalFile(filename));
    qDebug()<<"add media to the list";
    emit signalUpdatePlaylist(myPlaylist);

}
