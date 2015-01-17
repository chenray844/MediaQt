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

DockWidget::DockWidget(QWidget *parent)
    :QDockWidget(parent)
{
    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *lb = new QLabel("Hello Dock Widget");
    layout->addWidget(lb);

    QPushButton *btn = new QPushButton("Test Icon");
    btn->setIcon(QIcon(":/images/top-level/Archaia.png"));
    layout->addWidget(btn);

    layout->addStretch(1);

    widget->setLayout(layout);

    setWidget(widget);

}
