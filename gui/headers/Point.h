#ifndef POINT_H
#define POINT_H

#include "Vertex.h"
class Point{
public:
    Point(double x, double y);
    double x();
    double y();
    double distance(Point* p);
    double distance(Vertex* v);
private:
    double xp, yp;
};

#endif // POINT_H
