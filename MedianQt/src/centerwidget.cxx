
#include "centerwidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

CenterWidget::CenterWidget(QWidget *parent)
{
    //UNUSE_PARAM(parent);
    Q_UNUSED(parent);

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *lb = new QLabel("Hello Center Widget");
    layout->addWidget(lb);
    setLayout(layout);
}
