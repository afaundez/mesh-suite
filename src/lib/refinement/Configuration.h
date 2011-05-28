#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QVector>
#include "Constant.h"
#include "lib/geometric/Triangle.h"
#include "lib/geometric/Point.h"
#include "lib/geometric/Mesh.h"

class Configuration{

public:
    Configuration(Mesh* m, Triangle* t, QVector<Point*> p, QVector<int> e, Constant::IncludeCase ic);
    QVector<Point*> points();
    QVector<int> edges();
    Triangle* triangle();
    Mesh* mesh();
    Constant::IncludeCase includeCase();
    ~Configuration();

private:
    QVector<Point*> pp;
    QVector<int> ep;
    Triangle* tp;
    Mesh* mp;
    Constant::IncludeCase icp;
};
#endif // CONFIGURATION_H
