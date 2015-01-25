#include "textwidget.h"

#include <QVBoxLayout>

TextWidget::TextWidget(QWidget *parent)
{
    Q_UNUSED(parent);
    QVBoxLayout *layout = new QVBoxLayout();
    myEdit = new QTextEdit();
    layout->addWidget(myEdit);
    setLayout(layout);
}

QTextEdit * TextWidget::getTextEdit()
{
    return myEdit;
}
