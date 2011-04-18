#include <QtGui/QApplication>
#include "src/lib/gui/headers/MainWindow.h"

//! [0]
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//! [0]
