#include "videowidget.h"

#include <QVBoxLayout>
#include <QLabel>

VideoWidget::VideoWidget(QWidget *parent)
{
    Q_UNUSED(parent);

    QVBoxLayout *layout = new QVBoxLayout();

    myPlayer = new QMediaPlayer();
    QVideoWidget *videoWidget = new QVideoWidget();
    myPlayer->setVideoOutput(videoWidget);
    layout->addWidget(videoWidget);

    setLayout(layout);

}

QMediaPlayer * VideoWidget::getPlayer()
{
    return myPlayer;
}

