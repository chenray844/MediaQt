#include "mainwindow.h"

#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    app.setWindowIcon(QIcon(":/images/top-level/Archaia.png"));
    MainWindow *mw = new MainWindow();
    mw->show();
    return app.exec();
}
