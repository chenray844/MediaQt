#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dockwidget.h"
#include "centerwidget.h"

#include <QMainWindow>
#include <QLabel>
#include <QWidget>

class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);

protected slots:
    void slotPositionChanged(qint64);
    void slotSetCenterWidget();

private:
    //create menus
    void createMenus();

    //dock and center widget
    DockWidget *myDockWidget;
    CenterWidget *myCenterWidget;

    //playlist
    QMediaPlaylist *myPlaylist;

    //menu
    QMenu *fileMenu;


};


#endif // MAINWINDOW_H

