#ifndef MAIN_H
#define MAIN_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class Main;
}

class Main : public QMainWindow
{
    Q_OBJECT

public:
    Main(QWidget *parent = 0);
    ~Main();

private:
    Ui::Main *ui;
};

#endif // MAIN_H
