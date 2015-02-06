#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dockwidget.h"
#include "videowidget.h"
#include "textwidget.h"
#include "picturewidget.h"
#include "camerawidget.h"

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
    enum Actions{actLoadText,actLoadPicture,actLoadMP3,actLoadMP4,actShowCamera,actExit,actAbout,actCount};
    enum Menus{menuFile,menuHelp,menuCount};

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);

protected slots:
    //set center widget
    void slotSetCenterWidget(QString text);
    //=====================================
    void slotLoadText();
    void slotLoadMedia();
    void slotLoadPicture();

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



    //dock widget
    DockWidget *myDockWidget;

    //text widget
    TextWidget *myTextWidget;

    //video widget
    VideoWidget *myVideoWidget;
    QMediaPlayer *myPlayer;
    QMediaPlaylist *myPlaylist;
    bool flagVideo;

    //picture show widget
    PictureWidget *myPicWgt;
    QGraphicsScene *myPicScene;

    //camera widget
    CameraWidget *myCamWgt;

};


#endif // MAINWINDOW_H

