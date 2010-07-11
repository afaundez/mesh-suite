#include <QMatrix4x4>
#include <QMatrix2x2>
#include <GL/gl.h>
#include "headers/Triangle.h"

//! [0]
Triangle::Triangle(int id, Vertex* v0, Vertex* v1, Vertex* v2){
    this->idp =  id;
    this->vertexs.insert(0, v0);
    this->vertexs.insert(1, v1);
    this->vertexs.insert(2, v2);
    this->neighbours.insert(0,0);
    this->neighbours.insert(1,0);
    this->neighbours.insert(2,0);
    this->internalAngles.insert(0, 0.0);
    this->internalAngles.insert(1, 0.0);
    this->internalAngles.insert(2, 0.0);
    this->restrictedEdges.insert(0, false);
    this->restrictedEdges.insert(1, false);
    this->restrictedEdges.insert(2, false);
}
//! [0]

//! [2]
void Triangle::setNeighbours(Triangle* A, Triangle* B, Triangle* C){
    this->neighbours.insert(this->neighbours.begin() + 0,A);
    this->neighbours.insert(this->neighbours.begin() + 1,B);
    this->neighbours.insert(this->neighbours.begin() + 2,C);
    return;
}
//! [2]

//! [3]
Triangle* Triangle::getNeighbour(Vertex* P){
    return this->vertexs.at(0)->id() == P->id() ? this->neighbours.at(0) : this->vertexs.at(1)->id() == P->id() ? this->neighbours.at(1) : this->vertexs.at(2)->id() == P->id() ? this->neighbours.at(2) : 0;
}
//! [3]

//! [4]
Triangle* Triangle::getNeighbour(int p){
    return this->neighbours.at(p);
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
        glVertex2f(v0->x(), v0->y());
        glVertex2f(v1->x(), v1->y());
        glVertex2f(v2->x(), v2->y());
        for(unsigned int i = 0; i < 3; i++){
            Triangle* neighbour = this->getNeighbour(i);
            if(neighbour != 0){
                Vertex* nv0 = neighbour->getVertex(0);
                Vertex* nv1 = neighbour->getVertex(1);
                Vertex* nv2 = neighbour->getVertex(2);
                glColor4f(0.0, 1.0, 0.0, 0.1);
                glVertex2f(nv0->x(), nv0->y());
                glVertex2f(nv1->x(), nv1->y());
                glVertex2f(nv2->x(), nv2->y());
            }
        }
        glEnd();
    case Constant::NOT_SELECTED:
        glBegin(GL_LINE_STRIP);
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex2f(v0->x(), v0->y());
        glVertex2f(v1->x(), v1->y());
        glVertex2f(v2->x(), v2->y());
        glVertex2f(v0->x(), v0->y());
        glEnd();
        glPointSize(3.0);
        glBegin(GL_POINTS);
        glColor4f(0.0, 0.0, 0.0, 1.0);
        glVertex2f(v0->x(), v0->y());
        glVertex2f(v1->x(), v1->y());
        glVertex2f(v2->x(), v2->y());
        glEnd();
        glPointSize(1.0);
    default:
        break;
    }
}

double Triangle::orientation(Vertex *A, Vertex *B, Point* P){
    int ax, ay, bx, by, cx, cy;
    ax = A->x();
    ay = A->y();
    bx = B->x();
    by = B->y();
    cx = P->x();
    cy = P->y();
    QMatrix4x4 M(1, 0, 0, 0, 0, ax, ay, 1, 0, bx, by, 1, 0, cx, cy, 1);
    return M.determinant();
}

Constant::IncludeCase Triangle::include(Point* point){
    Vertex* A = this->getVertex(0);
    Vertex* B = this->getVertex(1);
    Vertex* C = this->getVertex(2);
    double orA, orB, orC;
    orA = this->orientation(A, B, point);
    orB = this->orientation(B, C, point);
    orC = this->orientation(C, A, point);
    if (0.0 < orA && 0.0 < orB && 0.0 < orC)
        return Constant::INCLUDED;
    else if ((0.0 < orA && orB == 0.0 && orC == 0.0) || (orA == 0.0 && 0.0 < orB && orC == 0.0)  || (orA == 0.0 && orB == 0.0 && 0.0 < orC))
        return Constant::CORNER_INCLUDED;
    else if ((0.0 < orA && 0.0 < orB && orC == 0.0) || (orA == 0.0 && 0.0 < orB && 0.0 < orC)  || (0.0 < orA && orB == 0.0 && 0.0 < orC))
        return Constant::BORDER_INCLUDED;
    else
        return Constant::NOT_INCLUDED;
}


int Triangle::id(){
    return this->idp;
}

int Triangle::getLongestEdge(){
    int l0, l1, l2;
    l0 = this->vertexs.at(1)->distance(this->vertexs.at(2));
    l1 = this->vertexs.at(2)->distance(this->vertexs.at(0));
    l2 = this->vertexs.at(0)->distance(this->vertexs.at(1));
    if(l0 <= l1 && l0 <= l2)
        return 0;
    else if (l1 <= l0 && l1 <= l2)
        return 1;
    else
        return 0;
}

bool  Triangle::hasNeighbour(int pos){
    if(this->neighbours.at(pos) == 0)
        return false;
    return true;
}

int Triangle::isNeighbour(Triangle* neighbour){
    int a0, a1, a2, b0, b1, b2;
    a0 = this->getVertex(0)->id();
    a1 = this->getVertex(1)->id();
    a2 = this->getVertex(2)->id();
    b0 = neighbour->getVertex(0)->id();
    b1 = neighbour->getVertex(1)->id();
    b2 = neighbour->getVertex(2)->id();
    if( (a0 == b0 && a1 == b2) ||
        (a0 == b1 && a1 == b0) ||
        (a0 == b2 && a1 == b1))
        return 2;
    if( (a1 == b0 && a2 == b2) ||
        (a1 == b1 && a2 == b0) ||
        (a1 == b2 && a2 == b1))
        return 0;
    if( (a2 == b0 && a0 == b2) ||
        (a2 == b1 && a0 == b0) ||
        (a2 == b2 && a0 == b1))
        return 1;
    return -1;
}

void Triangle::setNeighbour(int pos, Triangle* neighbour){
    this->neighbours.replace(pos, neighbour);
}

Triangle::~Triangle(){

}

