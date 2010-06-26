#include <QMatrix4x4>
#include <QMatrix2x2>
#include <GL/gl.h>
#include "headers/Triangle.h"

//! [0]
Triangle::Triangle(int _id, Vertex* A, Vertex* B, Vertex* C){
    this->idp =  _id;
    this->vertexs.insert(this->vertexs.begin() + 0, A);
    this->vertexs.insert(this->vertexs.begin() + 1, B);
    this->vertexs.insert(this->vertexs.begin() + 2, C);
    this->triangles.insert(this->triangles.begin() + 0,0);
    this->triangles.insert(this->triangles.begin() + 1,0);
    this->triangles.insert(this->triangles.begin() + 2,0);

    this->restricted.insert(this->restricted.begin() + 0, false);
    this->restricted.insert(this->restricted.begin() + 1, false);
    this->restricted.insert(this->restricted.begin() + 2, false);
}
//! [0]

//! [1]
int Triangle::getId(){
    return this->idp;
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

void Triangle::glDraw(Constant::GLTriangleType type){
    Vertex* v0 = this->getVertex(0);
    Vertex* v1 = this->getVertex(1);
    Vertex* v2 = this->getVertex(2);
    switch(type){
    case Constant::SELECTED:
        glBegin(GL_TRIANGLES);
        glColor4f(1.0, 0.0, 0.0, 0.1);
        glVertex2f(v0->getX(), v0->getY());
        glVertex2f(v1->getX(), v1->getY());
        glVertex2f(v2->getX(), v2->getY());
        glEnd();
    case Constant::NOT_SELECTED:
        glBegin(GL_LINE_STRIP);
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex2f(v0->getX(), v0->getY());
        glVertex2f(v1->getX(), v1->getY());
        glVertex2f(v2->getX(), v2->getY());
        glVertex2f(v0->getX(), v0->getY());
        glEnd();
        glPointSize(3.0);
        glBegin(GL_POINTS);
        glColor4f(0.0, 0.0, 0.0, 1.0);
        glVertex2f(v0->getX(), v0->getY());
        glVertex2f(v1->getX(), v1->getY());
        glVertex2f(v2->getX(), v2->getY());
        glEnd();
        glPointSize(1.0);
    default:
        break;
    }
}

double Triangle::orientation(Vertex *A, Vertex *B, QPoint P){
    int ax, ay, bx, by, cx, cy;
    ax = A->getX();
    ay = A->getY();
    bx = B->getX();
    by = B->getY();
    cx = P.x();
    cy = P.y();
    QMatrix4x4 M(1, 0, 0, 0, 0, ax, ay, 1, 0, bx, by, 1, 0, cx, cy, 1);
    return M.determinant();
}

Constant::IncludeType Triangle::include(QPoint point){
    Vertex* A = this->getVertex(0);
    Vertex* B = this->getVertex(1);
    Vertex* C = this->getVertex(2);
    double orA, orB, orC;
    orA = this->orientation(A, B, point);
    orB = this->orientation(B, C, point);
    orC = this->orientation(C, A, point);
    if (0.0 < orA && 0.0 < orB && 0.0 < orC)
        return Constant::INCLUDED;
    else if ((orA == 0.0 && orB == 0.0 && orC == 0.0) || (0.0 < orA && orB == 0.0 && orC == 0.0) || (orA == 0.0 && 0.0 < orB && orC == 0.0)  || (orA == 0.0 && orB == 0.0 && 0.0 < orC) || (0 < orA && orB && orC == 0) || (orA == 0.0 && 0.0 < orB && 0.0 < orC)  || (0.0 < orA && orB == 0.0 && 0.0 < orC))
        return Constant::BORDER_INCLUDED;
    else
        return Constant::NOT_INCLUDED;
}


int Triangle::id(){
    return this->idp;
}

Triangle::~Triangle(){

}

