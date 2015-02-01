#include "picturewidget.h"
#include <QVBoxLayout>
#include <QPixmap>

PictureWidget::PictureWidget(QWidget *parent)
{
    Q_UNUSED(parent);
    QVBoxLayout *layout = new QVBoxLayout();

    myScene = new QGraphicsScene();

    myView = new QGraphicsView();
    myView->setScene(myScene);

    layout->addWidget(myView);
    setLayout(layout);

}

PictureWidget::~PictureWidget()
{
    delete myScene;
    delete myView;
}
