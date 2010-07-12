#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Triangle.h"
#include <QVector>
#include "Point.h"
#include "Constant.h"
#include "Mesh.h"

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
