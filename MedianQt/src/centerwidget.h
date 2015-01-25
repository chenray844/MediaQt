#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include "textwidget.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QComboBox>


class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    CenterWidget(QComboBox *combo,QWidget *parent=0);

signals:
    void signalUpdateAlltime(qint64 t);
    void signalUpdateSliderValue(qint64 value);

protected slots:
    void slotChangeCenterWidget(QString text);
    void slotUpdatePlaylist(QMediaPlaylist *list);
    void slotPositionChanged(qint64 pos);
    void slotFullScreen(bool);
    void slotChangePosition(qint64 pos);
    void slotUpdateSliderPosition(qint64 pos);

private:
    QComboBox *myCombo;
    QMediaPlaylist *myPlaylist;
    QMediaPlayer *myPlayer;
    QVideoWidget *myVideoWidget;

};

#endif // CENTERWIDGET_H

