#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QDockWidget>
#include <QTreeWidget>
#include <QComboBox>

class QMediaPlaylist;
class QLabel;
class QSlider;
class QVBoxLayout;

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QComboBox *combo,QWidget *parent=0);
    QTreeWidget * getTreeWidget() {return myTreeWidget;}

signals:
    void signalUpdatePlaylist(QMediaPlaylist *list);
    void signalFullScreen(bool);
    void signalChangedPosition(qint64 pos);
    void signalSetWidget();

protected slots:
    //dock widget changed
    void slotChangeDockWidget(QString text);
    void slotTestDockWidget();


    void slotAddPlaylist();
    void slotLoadMovie();
    void slotLoadAVIMovie();
    void slotFullScreen();
    void slotResetScreen();
    void slotSetWidget();

    void slotUpdateAlltime(qint64 t);
    void slotChangedPosition();
    void slotUpdateSliderValue(qint64 value);
    void slotRealtimeShow(int pos);

private:
    QComboBox *myCombo;
    QVBoxLayout * createDockWidgetLayout(QString text);
    QVBoxLayout * myMainDockLayout;


    QMediaPlaylist *myPlaylist;
    QTreeWidget *myTreeWidget;
    QLabel *myTimeLabel;
    QLabel *myCurrentTimeLabel;
    QSlider *mySlider;
    QLabel *myMinLabel;
    QLabel *myMaxLabel;

};

#endif // DOCWIDGET_H

