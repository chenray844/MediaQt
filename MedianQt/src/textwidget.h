#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QTextEdit>

class TextWidget : public QWidget
{
    Q_OBJECT
public:
    TextWidget(QWidget *parent=0);
    QTextEdit * getTextEdit();

private:
    QTextEdit *myEdit;
};

#endif // TEXTWIDGET_H

