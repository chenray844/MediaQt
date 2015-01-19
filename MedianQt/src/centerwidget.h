#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>


class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    CenterWidget(QWidget *parent=0);

signals:
    void signalUpdateAlltime(qint64 t);

protected slots:
    void slotUpdatePlaylist(QMediaPlaylist *list);
    void slotPositionChanged(qint64 pos);
    void slotFullScreen(bool);
    void slotChangePosition(qint64 pos);

private:
    QMediaPlaylist *myPlaylist;
    QMediaPlayer *myPlayer;
    QVideoWidget *myVideoWidget;

};

#endif // CENTERWIDGET_H

