#include "mainwindow.h"

//qt
#include <QMovie>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QColor>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("ShowTime");

    //actions
    createActions();

    //menu
    createMenus();

    //toolbars
    createToolBars();




    //doc widget
    myDockWidget = new DockWidget(myMainCombo);
    myDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,myDockWidget);

    //text widget original show
    myTextWidget = new TextWidget();
    setCentralWidget(myTextWidget);

    connect(myMainCombo,SIGNAL(currentTextChanged(QString)),myDockWidget,SLOT(slotChangeDockWidget(QString)));
    connect(myMainCombo,SIGNAL(currentTextChanged(QString)),this,SLOT(slotSetCenterWidget(QString)));

    connect(myActions[actLoadText],SIGNAL(triggered()),this,SLOT(slotLoadText()));
    connect(myActions[actLoadMP4],SIGNAL(triggered()),this,SLOT(slotLoadMedia()));
    connect(myActions[actLoadPicture],SIGNAL(triggered()),this,SLOT(slotLoadPicture()));

    //variable
    flagVideo = false;

    setMinimumSize(QSize(800,600));
}

void MainWindow::slotSetCenterWidget(QString text)
{
    if(flagVideo)
    {
        flagVideo = false;
        myPlaylist->clear();
        myPlayer->stop();
    }
    if(text!="Load Text(.txt)")
    {
        if(text=="Load Movies(.mp4)")
        {
            flagVideo = true;
            myVideoWidget = new VideoWidget();
            myPlayer = myVideoWidget->getPlayer();
            myPlaylist = new QMediaPlaylist();

            setCentralWidget(myVideoWidget);
        }
        else if(text=="Load Pictures(.png,.jpg,.bmp....)")
        {

            myPicWgt = new PictureWidget();
            myPicScene = myPicWgt->getScene();

            setCentralWidget(myPicWgt);
        }
        else
        {

            QWidget *widget = new QWidget();
            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(new QLabel(text));
            widget->setLayout(layout);
            setCentralWidget(widget);
            if(flagVideo)
            {
                flagVideo = false;
                myPlaylist->clear();
                myPlayer->stop();
            }
        }

    }
    else
    {
        if(flagVideo)
        {
            flagVideo = false;
            myPlaylist->clear();
            myPlayer->stop();
        }
        myTextWidget = new TextWidget();
        setCentralWidget(myTextWidget);
    }

}

//create actions
void MainWindow::createActions()
{
    myActions.resize(actCount);

    myActions[actLoadText] = new QAction("Load Text(.txt)",this);
    myActions[actLoadPicture] = new QAction("Load Pictures(.png,.jpg,.bmp....)",this);
    myActions[actLoadMP3] = new QAction("Load Music(.mp3)",this);
    myActions[actLoadMP4] = new QAction("Load Movies(.mp4)",this);
    myActions[actShowCamera] = new QAction("Show Camera",this);
    myActions[actExit] = new QAction("Exit",this);
    myActions[actAbout] = new QAction("About",this);

    connect(myActions[actExit],SIGNAL(triggered()),this,SLOT(close()));

}

//create menus
void MainWindow::createMenus()
{
    myMenus.resize(menuCount);

    myMenus[menuFile] = menuBar()->addMenu("File");
    foreach(QAction *act,myActions)
    {
        myMenus[menuFile]->addAction(act);
    }

}

//create toolbars
void MainWindow::createToolBars()
{
    myMainToolBar = new QToolBar("Main Tool Bar");
    myMainCombo = new QComboBox();

    myMainCombo->addItem(myActions[actLoadText]->text());
    myMainCombo->addItem(myActions[actLoadPicture]->text());
    myMainCombo->addItem(myActions[actLoadMP3]->text());
    myMainCombo->addItem(myActions[actLoadMP4]->text());
    myMainCombo->addItem(myActions[actShowCamera]->text());

    myMainToolBar->addWidget(myMainCombo);
    addToolBar(myMainToolBar);
}

void MainWindow::slotLoadText()
{
    QTreeWidget *treeWidget = myDockWidget->getTreeWidget();
    treeWidget->clear();
    myTextWidget->getTextEdit()->clear();

    QString filename = QFileDialog::getOpenFileName(this,"Load Text","","Text(*.txt)");
    QFile file(filename);

    QMessageBox box;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        box.critical(this,"Attentation","Cannot load this file");
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        myTextWidget->getTextEdit()->append(line);
    }


    QString name = filename.split("/").at(filename.split("/").size()-1);
    treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString(name))));

    QTreeWidgetItem *root = treeWidget->topLevelItem(0);
    QTreeWidgetItem *addr = new QTreeWidgetItem();
    addr->setText(0,"Address :");
    addr->setText(1,filename);
    root->addChild(addr);

    QTreeWidgetItem *fileSize = new QTreeWidgetItem();
    fileSize->setText(0,"File Size (byte):");
    fileSize->setText(1,QString("%1 byte").arg(file.size()));
    root->addChild(fileSize);

    root->setExpanded(true);

}

void MainWindow::slotLoadMedia()
{
    QTreeWidget *treeWidget = myDockWidget->getTreeWidget();
    treeWidget->clear();
    myPlaylist->clear();

    //QString filename = "/Users/Raymond/Documents/Ray/MediaQt/MediaQt/MedianQt/data/video1.mp4";
    QString filename = QFileDialog::getOpenFileName(this,"Load Movie files","","Movies(*.mp4)");
    myPlaylist->addMedia(QUrl::fromLocalFile(filename));

    QFile file(filename);

    QMessageBox box;
    if(!file.open(QIODevice::ReadOnly))
    {
        box.critical(this,"Attentation","Cannot load this file");
        return;
    }

    QString name = filename.split("/").at(filename.split("/").size()-1);
    treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString(name))));

    QTreeWidgetItem *root = treeWidget->topLevelItem(0);
    QTreeWidgetItem *addr = new QTreeWidgetItem();
    addr->setText(0,"Address :");
    addr->setText(1,filename);
    root->addChild(addr);

    QTreeWidgetItem *fileSize = new QTreeWidgetItem();
    fileSize->setText(0,"File Size (byte):");
    fileSize->setText(1,QString("%1 byte").arg(file.size()));
    root->addChild(fileSize);
    root->setExpanded(true);

    myPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    myPlayer->setPlaylist(myPlaylist);
    myPlayer->play();
}

void MainWindow::slotLoadPicture()
{
    myPicScene->clear();

    QString filename = QFileDialog::getOpenFileName(this,"Picture","","Picture(*.jpg *.png *.bmp)");
    QPixmap *pic = new QPixmap();
    pic->load(filename);
    myPicScene->addPixmap(*pic);
}























