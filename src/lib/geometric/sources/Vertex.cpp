#include "src/lib/geometric/headers/Vertex.h"

//! [0]
Vertex::Vertex(int id, double x, double y): Point(x, y)
{
    this->idp    = id;
}
//! [0]

//! [1]
int Vertex::id(){
    return this->idp;
}
//! [1]

Vertex::~Vertex(){
}
