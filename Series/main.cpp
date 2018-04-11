#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int ret = 0;
    Widget* w = Widget::newWidget();
    if(w != NULL )
    {
        w->show();

        ret = a.exec();
        delete w;
    }
    return ret;
}
