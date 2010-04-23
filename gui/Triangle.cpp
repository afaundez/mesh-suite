#include "Triangle.h"

//! [0]
Triangle::Triangle(int _id, Vertex* A, Vertex* B, Vertex* C){
    this->id =  _id;
    this->vertexs.insert(this->vertexs.begin() + 0, A);
    this->vertexs.insert(this->vertexs.begin() + 1, B);
    this->vertexs.insert(this->vertexs.begin() + 2, C);
    this->triangles.insert(this->triangles.begin() + 0,0);
    this->triangles.insert(this->triangles.begin() + 1,0);
    this->triangles.insert(this->triangles.begin() + 2,0);
}
//! [0]

//! [1]
int Triangle::getId(){
    return this->id;
}
//! [1]

//! [2]
void Triangle::setTriangles(Triangle* A, Triangle* B, Triangle* C){
    this->triangles.insert(this->triangles.begin() + 0,A);
    this->triangles.insert(this->triangles.begin() + 1,B);
    this->triangles.insert(this->triangles.begin() + 2,C);
    return;
}
//! [2]

//! [3]
Triangle* Triangle::getOppositeTriangle(Vertex* P){
    return this->vertexs.at(0) == P ? this->triangles.at(0) : this->vertexs.at(1) == P ? this->triangles.at(1) : this->vertexs.at(2) == P ? this->triangles.at(2) : 0;
}
//! [3]

//! [4]
Triangle* Triangle::getOppositeTriangle(int p){
    return this->triangles.at(p);
}
//! [4]

//! [5]
Vertex* Triangle::getVertex(int p){
    if (0 <= p && p < 3)
        return this->vertexs.at(p);
    return 0;
}
//! [5]
