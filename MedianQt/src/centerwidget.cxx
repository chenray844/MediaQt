
#include "centerwidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>

CenterWidget::CenterWidget(QComboBox *combo, QWidget *parent)
    :myCombo(combo)
{
    Q_UNUSED(parent);

    QVBoxLayout *layout = new QVBoxLayout();
    if(myCombo->currentText()=="Load Text(.txt)")
    {
        layout->addWidget(new QTextEdit());
    }

    //myPlayer = new QMediaPlayer();

    //myVideoWidget = new QVideoWidget();
    //myPlayer->setVideoOutput(myVideoWidget);

    //layout->addWidget(myVideoWidget);

    setLayout(layout);

    //connect(myPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(slotPositionChanged(qint64)));
    //connect(myPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(slotUpdateSliderPosition(qint64)));
}

void CenterWidget::slotChangeCenterWidget(QString text)
{
    //this->
    //destroy();
    //QVBoxLayout *layout = new QVBoxLayout();
    //QWidget *widget = layout()->widget();

    if(text!="Load Text(.txt)")
    {
        //layout()->removeWidget(widget);
        layout()->addWidget(new QLabel(text));
    }
    else
    {
        layout()->addWidget(new QTextEdit());
    }

    //setLayout(layout);
}

void CenterWidget::slotUpdatePlaylist(QMediaPlaylist *list)
{
    //myPlaylist = list;
    //qDebug()<<"Update play list";
    //myPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    //myPlayer->setPlaylist(myPlaylist);
    //qDebug()<<myPlayer->error();
    //qDebug()<<myPlayer->mediaStatus();
    //myPlayer->play();

    //qint64 t = myPlayer->duration();
    //emit signalUpdateAlltime(t);

}

void CenterWidget::slotPositionChanged(qint64 pos)
{
    //qDebug()<<"Median Position"<<pos;
    //emit signalUpdateAlltime(pos);
}

void CenterWidget::slotFullScreen(bool flag)
{
    //myVideoWidget->setFullScreen(flag);

}

void CenterWidget::slotChangePosition(qint64 pos)
{

    //myPlayer->setPosition(pos);
}

void CenterWidget::slotUpdateSliderPosition(qint64 pos)
{

    //emit signalUpdateSliderValue(pos);
}
