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

protected slots:
    void slotUpdatePlaylist(QMediaPlaylist *list);
    void slotPositionChanged(qint64 pos);

private:
    QMediaPlaylist *myPlaylist;
    QMediaPlayer *myPlayer;
    QVideoWidget *myVideoWidget;

};

#endif // CENTERWIDGET_H

