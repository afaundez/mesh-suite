#include <GL/gl.h>
#include <math.h>
#include "lib/headers/Point.h"

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

void Point::setX(double x){
    this->xp = x;
}

void Point::setY(double y){
    this->yp = y;
}

void Point::glDraw(){
    glVertex2f(this->xp, this->yp);
}
