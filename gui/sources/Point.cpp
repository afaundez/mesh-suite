#include "headers/Point.h"
#include <math.h>

Point::Point(double x, double y){
    this->xp = x;
    this->yp = y;
}

double Point::x(){
    return this->xp;
}

double Point::y(){
    return this->yp;
}

double Point::distance(Vertex *v){
    return this->distance(new Point(v->x(), v->y()));
}

double Point::distance(Point *p){
    return sqrt(pow(this->xp - p->x(), 2) + pow(this->yp-p->y(), 2));
}
