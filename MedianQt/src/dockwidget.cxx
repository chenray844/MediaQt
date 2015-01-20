#include "dockwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QToolButton>
#include <QAction>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMovie>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QSlider>

DockWidget::DockWidget(QWidget *parent)
    :QDockWidget(parent)
{
    QWidget *widget = new QWidget();

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *lb = new QLabel();
    layout->addWidget(lb);
    QMovie *movie = new QMovie("/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/animation.gif");
    lb->setMovie(movie);
    movie->start();

    QPushButton *btn = new QPushButton("Test Movie Show");
    btn->setIcon(QIcon(":/images/top-level/view.png"));
    layout->addWidget(btn);

    myTreeWidget = new QTreeWidget();
    myTreeWidget->setColumnCount(1);
    myTreeWidget->setHeaderItem(new QTreeWidgetItem(QStringList(QString("Play List"))));

    QTreeWidgetItem *root = new QTreeWidgetItem();
    root->setText(0,"Movies");
    myTreeWidget->insertTopLevelItem(0,root);

    layout->addWidget(myTreeWidget);

    QHBoxLayout *ltime = new QHBoxLayout();
    myTimeLabel = new QLabel();
    ltime->addWidget(new QLabel("Time : "));
    ltime->addWidget(myTimeLabel);
    myCurrentTimeLabel = new QLabel();
    ltime->addWidget(new QLabel("Current time :"));
    ltime->addWidget(myCurrentTimeLabel);
    layout->addLayout(ltime);

    QPushButton *loadBtn = new QPushButton("Load Movie");
    loadBtn->setIcon(QIcon(":/images/top-level/view.png"));
    layout->addWidget(loadBtn);

    QPushButton *fullScreenBtn = new QPushButton("Full Screen");
    layout->addWidget(fullScreenBtn);

    QPushButton *resetBtn = new QPushButton("Come Back");
    layout->addWidget(resetBtn);

    //QPushButton *changePosBtn = new QPushButton("Change Position");
    //layout->addWidget(changePosBtn);

    QHBoxLayout *lSlider = new QHBoxLayout();
    myMinLabel = new QLabel();
    //myMinLabel->setText("Real Position: 0");
    myMaxLabel = new QLabel();
    mySlider = new QSlider(Qt::Horizontal);
    mySlider->setMinimum(0);
    mySlider->setMaximum(1000);
    mySlider->setTickPosition(QSlider::TicksAbove);
    lSlider->addWidget(myMinLabel);
    lSlider->addWidget(mySlider);
    lSlider->addWidget(myMaxLabel);
    //layout->addWidget(mySlider);
    layout->addLayout(lSlider);


    layout->addStretch(1);

    widget->setLayout(layout);

    setWidget(widget);

    //playlist
    myPlaylist = new QMediaPlaylist();

    connect(btn,SIGNAL(clicked()),this,SLOT(slotAddPlaylist()));
    connect(loadBtn,SIGNAL(clicked()),this,SLOT(slotLoadMovie()));
    connect(fullScreenBtn,SIGNAL(clicked()),this,SLOT(slotFullScreen()));
    connect(resetBtn,SIGNAL(clicked()),this,SLOT(slotResetScreen()));
    //connect(changePosBtn,SIGNAL(clicked()),this,SLOT(slotChangedPosition()));
    connect(mySlider,SIGNAL(sliderReleased()),this,SLOT(slotChangedPosition()));
    //connect(mySlider,SIGNAL(sliderMoved(int)),this,SLOT(slotRealtimeShow(int)));
}

void DockWidget::slotAddPlaylist()
{
    QString filename = "/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/video1.mp4";

    //QString filename = QFileDialog::getOpenFileName(this,"Load Movie files","","Movies(*.mp4)");
    //qDebug()<<filename;
    myPlaylist->addMedia(QUrl::fromLocalFile(filename));
    qDebug()<<"add media to the list";

    QTreeWidgetItem *root = myTreeWidget->topLevelItem(0);

    QTreeWidgetItem *item = new QTreeWidgetItem();
    QString text = filename.split("/").at(filename.split("/").size()-1);
    item->setText(0,text);

    root->addChild(item);


    emit signalUpdatePlaylist(myPlaylist);

}

void DockWidget::slotLoadMovie()
{
    QString filename = QFileDialog::getOpenFileName(this,"Load Movie File","","Movie(*.mp4)");
    qDebug()<<filename;
    myPlaylist->addMedia(QUrl::fromLocalFile(filename));

    QTreeWidgetItem *root = myTreeWidget->topLevelItem(0);

    QTreeWidgetItem *item = new QTreeWidgetItem();
    QString text = filename.split("/").at(filename.split("/").size()-1);
    item->setText(0,text);

    root->addChild(item);
    root->setExpanded(true);

    myTreeWidget->setCurrentItem(item);

    emit signalUpdatePlaylist(myPlaylist);

}

void DockWidget::slotFullScreen()
{
    emit signalFullScreen(true);

}

void DockWidget::slotResetScreen()
{

    emit signalFullScreen(false);
}

void DockWidget::slotUpdateAlltime(qint64 t)
{

    qDebug()<<"All time :"<<t;
    myTimeLabel->setText(QString("%1 s").arg(t/1000.0));
    mySlider->setMaximum(t);
    //myMinLabel->setText("0");
    myMaxLabel->setText(QString("%1 min").arg(t/1000.0/60.0));
}

void DockWidget::slotChangedPosition()
{
    qint64 pos = mySlider->value();
    //myCurrentTimeLabel->setText(QString("%1 s").arg(pos/1000.0));
    //qDebug()<<"Slider position :"<<pos;
    emit signalChangedPosition(pos);
}

void DockWidget::slotUpdateSliderValue(qint64 value)
{
    myCurrentTimeLabel->setText(QString("%1 s").arg(value/1000.0));
    mySlider->setValue(value);

}

void DockWidget::slotRealtimeShow(int pos)
{

    myCurrentTimeLabel->setText(QString("%1 s").arg(pos));
}
