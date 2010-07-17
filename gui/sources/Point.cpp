#include <GL/gl.h>
#include <math.h>
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

void Point::setX(int x){
    this->xp = x;
}

void Point::setY(int y){
    this->yp = y;
}

void Point::glDraw(){
    glVertex2f(this->xp, this->yp);
}
