#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dockwidget.h"
#include "centerwidget.h"

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QComboBox>

class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);

    //actions
    enum Actions{actLoadText,actLoadPicture,actLoadMP3,actLoadMP4,actExit,actAbout,actCount};
    enum Menus{menuFile,menuHelp,menuCount};

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);

protected slots:
    void slotPositionChanged(qint64);
    void slotSetCenterWidget(QString text);
    void slotLoadText();

private:
    //create actions
    void createActions();

    //create menus
    void createMenus();

    //create toolbars
    void createToolBars();

    //actions
    QVector<QAction *> myActions;

    //menu
    QVector<QMenu *> myMenus;

    //toolbar
    QToolBar *myMainToolBar;

    //combo box
    QComboBox *myMainCombo;//choose which widget will be viewed in the dock and center widget



    //dock and center widget
    DockWidget *myDockWidget;
    CenterWidget *myCenterWidget;

    //text widget
    TextWidget *myTextWidget;

    //playlist
    QMediaPlaylist *myPlaylist;




};


#endif // MAINWINDOW_H

