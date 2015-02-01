#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>

class PictureWidget : public QWidget
{
    Q_OBJECT
public:
    PictureWidget(QWidget *parent=0);
    ~PictureWidget();

    //scene
    QGraphicsScene * getScene(){return myScene;}

private:
    QGraphicsScene *myScene;
    QGraphicsView *myView;
};

#endif // PICTUREWIDGET_H

