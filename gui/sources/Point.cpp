#include "headers/Point.h"

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
