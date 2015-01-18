
#include "centerwidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

CenterWidget::CenterWidget( QWidget *parent)
{
    //UNUSE_PARAM(parent);
    Q_UNUSED(parent);

    QVBoxLayout *layout = new QVBoxLayout();

    myPlayer = new QMediaPlayer();

    myVideoWidget = new QVideoWidget();
    myPlayer->setVideoOutput(myVideoWidget);

    layout->addWidget(myVideoWidget);

    setLayout(layout);
}

void CenterWidget::slotUpdatePlaylist(QMediaPlaylist *list)
{
    myPlaylist = list;
    qDebug()<<"Update play list";
    myPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    myPlayer->setPlaylist(myPlaylist);
    myPlayer->play();

}

void CenterWidget::slotPositionChanged(qint64 pos)
{
    qDebug()<<"Median Position"<<pos;
}
