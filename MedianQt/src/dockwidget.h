#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QDockWidget>

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QWidget *parent=0);

};

#endif // DOCWIDGET_H

