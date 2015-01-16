#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Hello");
    QLabel *lb = new QLabel("Hello World");
    setCentralWidget(lb);
    setMinimumSize(QSize(500,500));
}
