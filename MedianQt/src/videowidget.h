#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QWidget>

class VideoWidget : public QWidget
{
    Q_OBJECT
public:
    VideoWidget(QWidget *parent=0);
    QMediaPlayer * getPlayer();

private:
    QMediaPlayer *myPlayer;

};

#endif // VIDEOWIDGET_H

