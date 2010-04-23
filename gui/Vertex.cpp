#include "Vertex.h"

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
