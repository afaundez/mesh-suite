#include "headers/Vertex.h"
#include <GL/gl.h>
#include <math.h>

//! [0]
Vertex::Vertex(int id, double x, double y)
{
    this->idp    = id;
    this->xp     = x;
    this->yp     = y;
}
//! [0]

//! [1]
int Vertex::id(){
    return this->idp;
}
//! [1]

//! [2]
double Vertex::x(){
    return this->xp;
}
//! [2]

//! [3]
double Vertex::y(){
    return this->yp;
}
//! [3]

double Vertex::distance(Vertex *Q){
    return sqrt(pow(this->xp - Q->x(), 2) + pow(this->yp - Q->y(), 2));
}

void Vertex::glDraw(){
    glVertex2f(this->xp, this->yp);
}
