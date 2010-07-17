#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#include "Point.h"

namespace Util{

    static double distance(Point* a, Point *b){
        return sqrt(pow(b->x() - a->x(), 2) + pow(b->y() - a->y(), 2));
    }

    static Point* midpoint(Point* a, Point *b){
        return new Point( (b->x() + a->x())/2.0, (b->y() + a->y())/2.0 );
    }

    static double circleTest(Point *a, Point *b, Point *c, Point* p){
        double pxs = p->x() * p->x();
        double pys = p->y() * p->y();

        double A = a->x() - p->x(); double B = a->y() - p->y();
        double C = (a->x() * a->x() - pxs) + (a->y() * a->y() - pys);

        double D = b->x() - p->x(); double E = b->y() - p->y();
        double F = (b->x() * b->x() - pxs) + (b->y() * b->y() - pys);

        double G = c->x() - p->x(); double H = c->y() - p->y();
        double I = (c->x() * c->x() - pxs) + (c->y() * c->y() - pys);

        return A*E*I - A*F*H + B*F*G - B*D*I + C*D*H - C*E*G;
    }
}

#endif // UTIL_H
