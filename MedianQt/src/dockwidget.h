#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QDockWidget>
#include <QTreeWidget>

class QMediaPlaylist;
class QLabel;
class QSlider;

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QWidget *parent=0);

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);
    void signalFullScreen(bool);
    void signalChangedPosition(qint64 pos);

protected slots:
    void slotAddPlaylist();
    void slotLoadMovie();
    void slotLoadAVIMovie();
    void slotFullScreen();
    void slotResetScreen();

    void slotUpdateAlltime(qint64 t);
    void slotChangedPosition();
    void slotUpdateSliderValue(qint64 value);
    void slotRealtimeShow(int pos);

private:
    QMediaPlaylist *myPlaylist;
    QTreeWidget *myTreeWidget;
    QLabel *myTimeLabel;
    QLabel *myCurrentTimeLabel;
    QSlider *mySlider;
    QLabel *myMinLabel;
    QLabel *myMaxLabel;

};

#endif // DOCWIDGET_H

