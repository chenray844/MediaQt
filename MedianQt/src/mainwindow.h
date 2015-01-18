#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dockwidget.h"
#include "centerwidget.h"

#include <QMainWindow>
#include <QLabel>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);

protected slots:
    void slotPositionChanged(qint64);

private:
    //dock and center widget
    DockWidget *myDockWidget;
    CenterWidget *myCenterWidget;

    //playlist
    QMediaPlaylist *myPlaylist;


};


#endif // MAINWINDOW_H

