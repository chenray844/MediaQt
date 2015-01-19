#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QDockWidget>
#include <QTreeWidget>

class QMediaPlaylist;
class QLabel;

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
    void slotFullScreen();
    void slotResetScreen();

    void slotUpdateAlltime(qint64 t);
    void slotChangedPosition();

private:
    QMediaPlaylist *myPlaylist;
    QTreeWidget *myTreeWidget;
    QLabel *myTimeLabel;

};

#endif // DOCWIDGET_H

