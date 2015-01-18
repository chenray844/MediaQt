#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QDockWidget>
class QMediaPlaylist;

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QWidget *parent=0);

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);

protected slots:
    void slotAddPlaylist();

private:
    QMediaPlaylist *myPlaylist;

};

#endif // DOCWIDGET_H

