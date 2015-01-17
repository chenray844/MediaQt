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

protected slots:
    void slotPositionChanged(qint64);

private:
    QLabel *myPositionLabel;
    DockWidget *myDockWidget;
    CenterWidget *myCenterWidget;

};


#endif // MAINWINDOW_H

