#include <QtGui/QApplication>
#include "lib/headers/MainWindow.h"

//! [0]
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//! [0]
