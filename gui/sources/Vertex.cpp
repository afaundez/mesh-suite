#include "headers/Vertex.h"
#include <GL/gl.h>
#include <math.h>

//! [0]
Vertex::Vertex(int _id, double _x, double _y)
{
    this->id    = _id;
    this->x     = _x;
    this->y     = _y;
}
//! [0]

//! [1]
int Vertex::getId(){
    return this->id;
}
//! [1]

//! [2]
double Vertex::getX(){
    return this->x;
}
//! [2]

//! [3]
double Vertex::getY(){
    return this->y;
}
//! [3]

double Vertex::distance(Vertex *Q){
    return sqrt(pow(this->x - Q->getX(), 2) + pow(this->y - Q->getY(), 2));
}

void Vertex::glDraw(){
    glVertex2f(this->x, this->y);
}
