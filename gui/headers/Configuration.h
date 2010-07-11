#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Triangle.h"
#include <QVector>
#include "Point.h"
#include "Constant.h"

class Configuration{

public:
    Configuration(Triangle* t, QVector<Point*> p, QVector<int> e);
    QVector<Point*> points();
    QVector<int> edges();
    Triangle* triangle();
    ~Configuration();

private:
    QVector<Point*> pp;
    QVector<int> ep;
    Triangle* tp;
};
#endif // CONFIGURATION_H
