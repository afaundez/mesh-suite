#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QVector>
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/geometric/headers/Point.h"
#include "Constant.h"
#include "src/lib/geometric/headers/Mesh.h"

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
