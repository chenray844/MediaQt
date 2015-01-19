
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

    connect(myPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(slotPositionChanged(qint64)));
}

void CenterWidget::slotUpdatePlaylist(QMediaPlaylist *list)
{
    myPlaylist = list;
    qDebug()<<"Update play list";
    myPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    myPlayer->setPlaylist(myPlaylist);
    myPlayer->play();

    //qint64 t = myPlayer->duration();
    //emit signalUpdateAlltime(t);

}

void CenterWidget::slotPositionChanged(qint64 pos)
{
    //qDebug()<<"Median Position"<<pos;
    emit signalUpdateAlltime(pos);
}

void CenterWidget::slotFullScreen(bool flag)
{
    myVideoWidget->setFullScreen(flag);

}

void CenterWidget::slotChangePosition(qint64 pos)
{

    myPlayer->setPosition(pos);
}