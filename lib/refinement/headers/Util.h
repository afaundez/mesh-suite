#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#include "lib/geometric/headers/Point.h"

namespace Util{

    static double distance(Point* a, Point *b){
        return sqrt(pow(b->x() - a->x(), 2) + pow(b->y() - a->y(), 2));
    };

    static Point* midpoint(Point* a, Point *b){
        return new Point( (b->x() + a->x())/2.0, (b->y() + a->y())/2.0 );
    };

    static Point* centroid(Point *a, Point *b, Point *c, Point* d){
        double x0, y0, x1, y1, x2, y2, x3, y3;
        x0 = a->x();
        x1 = b->x();
        x2 = c->x();
        x3 = d->x();
        y0 = a->y();
        y1 = b->y();
        y2 = c->y();
        y3 = d->y();
        double A = 0.5*( (x0*y1 - x1*y0) +
                         (x1*y2 - x2*y1) +
                         (x2*y3 - x3*y2) +
                         (x3*y0 - x0*y3) );
        double x = ( (x0+x1)*(x0*y1-x1*y0) +
                     (x1+x2)*(x1*y2-x2*y1) +
                     (x2+x3)*(x2*y3-x3*y2) +
                     (x3+x0)*(x3*y0-x0*y3) ) / (6.0*A);
        double y = ( (y0+y1)*(x0*y1-x1*y0) +
                     (y1+y2)*(x1*y2-x2*y1) +
                     (y2+y3)*(x2*y3-x3*y2) +
                     (y3+y0)*(x3*y0-x0*y3) ) / (6.0*A);
        return new Point(x, y);
    }



    static double orientation(Point *A, Point* B, Point* P){
        double ax, ay, bx, by, px, py;
        ax = A->x();
        ay = A->y();
        bx = B->x();
        by = B->y();
        px = P->x();
        py = P->y();
        return (ax-px)*(by-py) - (ay-py)*(bx-px);
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
    };
}

#endif // UTIL_H
