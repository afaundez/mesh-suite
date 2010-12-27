#include <GL/gl.h>
#include <math.h>
#include "lib/geometric/headers/Triangle.h"
#include "lib/refinement/headers/Util.h"

//! [0]
Triangle::Triangle(int id, Vertex* v0, Vertex* v1, Vertex* v2){
    this->idp =  id;
    this->vertexsp.insert(0, v0);
    this->vertexsp.insert(1, v1);
    this->vertexsp.insert(2, v2);

    this->neighboursp.insert(0,0);
    this->neighboursp.insert(1,0);
    this->neighboursp.insert(2,0);

    double d0 = Util::distance(v1, v2);
    double d1 = Util::distance(v2, v0);
    double d2 = Util::distance(v0, v1);;

    double a0	= acos( (d1*d1+d2*d2-d0*d0)/(2*d1*d2) )/Constant::pi*180.0;
    double a1	= acos( (d2*d2+d0*d0-d1*d1)/(2*d2*d0) )/Constant::pi*180.0;
    double a2	= acos( (d0*d0+d1*d1-d2*d2)/(2*d0*d1) )/Constant::pi*180.0;

    this->internalAnglesp.insert(0, a0);
    this->internalAnglesp.insert(1, a1);
    this->internalAnglesp.insert(2, a2);

    this->restrictedEdgesp.insert(0, false);
    this->restrictedEdgesp.insert(1, false);
    this->restrictedEdgesp.insert(2, false);
}
//! [0]

void Triangle::setRestricted(int edge){
    this->restrictedEdgesp.replace(edge, true);
}

bool Triangle::isRestricted(int edge){
    return this->restrictedEdgesp.at(edge);
}

//! [2]
void Triangle::setNeighbours(Triangle* A, Triangle* B, Triangle* C){
    this->neighboursp.replace(0,A);
    this->neighboursp.replace(1,B);
    this->neighboursp.replace(2,C);
    return;
}
//! [2]

//! [3]
Triangle* Triangle::getNeighbour(Vertex* P){
    return this->vertexsp.at(0)->id() == P->id() ? this->neighboursp.at(0) : this->vertexsp.at(1)->id() == P->id() ? this->neighboursp.at(1) : this->vertexsp.at(2)->id() == P->id() ? this->neighboursp.at(2) : 0;
}
//! [3]

//! [4]
Triangle* Triangle::getNeighbour(int p){
    return this->neighboursp.at(p);
}
//! [4]

//! [5]
Vertex* Triangle::getVertex(int p){
    if (0 <= p && p < 3)
        return this->vertexsp.at(p);
    return 0;
}
//! [5]

void Triangle::glDraw(Constant::GLTriangleType type, double value){
    Vertex* v0 = this->getVertex(0);
    Vertex* v1 = this->getVertex(1);
    Vertex* v2 = this->getVertex(2);
    Point *c;
    double radius;
    int step;
    switch(type){
    case Constant::SELECTED:
        // TRIANGLE ITSELF
        glBegin(GL_TRIANGLES);
        glColor4f(0.415686275, 0.415686275, 1.0, 0.5);
        glVertex2f(v0->x(), v0->y());
        glVertex2f(v1->x(), v1->y());
        glVertex2f(v2->x(), v2->y());
        glEnd();

        // CIRCUNCIRCLE
        glBegin(GL_LINE_LOOP);
        step = 100;
        c = this->circumcenter();
        radius =  this->circumradius();
        glColor4f(0.0, 1.0, 0.0, 0.5);
        for(int i = 0; i < step; i++)
            glVertex2f(c->x() + radius*cos(2*Constant::pi/step*i), c->y() + radius*sin(2*Constant::pi/step*i));
        glEnd();
    case Constant::NOT_SELECTED:
        // IF ANNOYING
        if(this->isAnnoying(value)){
            glBegin(GL_TRIANGLES);
            glColor4f(1.0, 0.282352941, 0.282352941, 0.2);
            glVertex2f(v0->x(), v0->y());
            glVertex2f(v1->x(), v1->y());
            glVertex2f(v2->x(), v2->y());
            glEnd();
        }
        // TRIANGLE BORDER
        glBegin(GL_LINES);
        for(int i = 0; i < 3; i++){
            glColor4f(0.0, 0.0, 0.0, 0.1);
            if( this->isRestricted(i) )
                glColor4f(1.0, 0.0, 0.0, 1.0);
            if( this->isBoundary(i) )
                glColor4f(0.0, 0.0, 1.0, 1.0);
            glVertex2f(this->vertex((i+1)%3)->x(), this->vertex((i+1)%3)->y());
            glVertex2f(this->vertex((i+2)%3)->x(), this->vertex((i+2)%3)->y());
        }
        glEnd();
    default:
        break;
    }
}

int Triangle::wichBorder(Point* p){
    Vertex* v0 = this->vertex(0);
    Vertex* v1 = this->vertex(1);
    Vertex* v2 = this->vertex(2);
    double or0, or1, or2;
    or0 = Util::orientation(v1, v2, p);
    or1 = Util::orientation(v2, v0, p);
    or2 = Util::orientation(v0, v1, p);
    if(0.0 - 0.000001 < or0 && or0 < 0.0 + 0.000001)
        return 0;
    else if(0.0 - 0.000001 < or1 && or1 < 0.0 + 0.000001)
        return 1;
    else if(0.0 - 0.000001 < or2 && or2 < 0.0 + 0.000001)
        return 2;
    else
        return -1;
}

Constant::IncludeCase Triangle::include(Point* p){
    Vertex* v0 = this->getVertex(0);
    Vertex* v1 = this->getVertex(1);
    Vertex* v2 = this->getVertex(2);
    double or0, or1, or2;
    or0 = Util::orientation(v1, v2, p);
    or1 = Util::orientation(v2, v0, p);
    or2 = Util::orientation(v0, v1, p);
    if (0.0 + 0.000001 < or0 && 0.0 + 0.000001 < or1 && 0.0 + 0.000001 < or2)
        return Constant::INCLUDED;
    else if ((0.0 + 0.000001 < or0  && 0.0 + 0.000001 < or1  && 0.0 - 0.000001 <= or2 && or2 <= 0.0 + 0.000001) ||
             (0.0 - 0.000001 <= or0  && or0 <= 0.0 + 0.000001  && 0.0 + 0.000001 < or1 && 0.0 + 0.000001 < or2) ||
             (0.0 + 0.000001 < or0  && 0.0 - 0.000001 <= or1  && or1 <= 0.0 + 0.000001 && 0.0 + 0.000001 < or2))
        return Constant::BORDER_INCLUDED;
    else if ((0.0 + 0.000001 < or0 && 0.0 - 0.000001 <= or1 && or1 <= 0.0 + 0.000001 && 0.0 - 0.000001 <= or2 && or2 <= 0.0 + 0.000001) ||
             (0.0 - 0.000001 <= or0 && or0 <= 0.0 + 0.000001 && 0.0 + 0.000001 < or1 && 0.0 - 0.000001 <= or2 && or2 <= 0.0 + 0.000001) ||
             (0.0 - 0.000001 <= or0 && or0 <= 0.0 + 0.000001 && 0.0 - 0.000001 <= or1 && or1 <= 0.0 + 0.000001 && 0.0 + 0.000001 < or2))
        return Constant::CORNER_INCLUDED;
    else
        return Constant::NOT_INCLUDED;
}

Constant::IncludeCase Triangle::circumcircleInclude(Point *p){
    Constant::IncludeCase ic;
    double det = Util::circleTest(this->vertex(0), this->vertex(1), this->vertex(2), p);
    if (0.0 + 0.000001 < det){
        ic = Constant::INCLUDED;
    }
    else if(0.0 - 0.000001 <= det && det <= 0.0 + 0.000001)
        ic = Constant::BORDER_INCLUDED;
    else
        ic = Constant::NOT_INCLUDED;
    return ic;
}

Constant::IncludeCase Triangle::edgeInclude(int edge, Point *p){
    Constant::IncludeCase ic;
    Point* c =  this->midpoint(edge);
    double R, r;
    R = Util::distance(this->vertex((edge+1)%3), c);
    r = Util::distance(c, p);
    if (r < R)
        ic = Constant::INCLUDED;
    else if(r == R)
        ic = Constant::BORDER_INCLUDED;
    else
        ic = Constant::NOT_INCLUDED;
    return ic;
}

QVector<Triangle*> Triangle::lepp(){
    QVector<Triangle*> ret;
    ret.append(this);
    Triangle* aux = this->neighbour(this->getLongestEdge());
    while(aux != 0){
        if(aux->neighbour(aux->getLongestEdge()) == 0){
            ret.append(aux);
            break;
        }
        if (ret.last()->id() == aux->neighbour(aux->getLongestEdge())->id()){
            break;
        }
        ret.append(aux);
        aux = aux->neighbour(aux->getLongestEdge());
    }
    return ret;
}

double Triangle::circumradius(){
    return Util::distance(this->circumcenter(), this->vertex(0));
}

Point* Triangle::circumcenter(){
    double ax, ay, bx, by, cx, cy;

    ax = this->vertexsp.at(0)->x();
    ay = this->vertexsp.at(0)->y();
    bx = this->vertexsp.at(1)->x();
    by = this->vertexsp.at(1)->y();
    cx = this->vertexsp.at(2)->x();
    cy = this->vertexsp.at(2)->y();

    double xdo, ydo, xao, yao;
    double dodist, aodist, dadist;
    double denominator;
    double dx, dy;


    xdo = cx - bx;
    ydo = cy - by;
    xao = ax - bx;
    yao = ay - by;
    dodist = xdo * xdo + ydo * ydo;
    aodist = xao * xao + yao * yao;
    dadist = (cx - ax) * (cx - ax) +
           (cy - ay) * (cy - ay);
    denominator = 0.5 / (xdo * yao - xao * ydo);
    dx = (yao * dodist - ydo * aodist) * denominator;
    dy = (xdo * aodist - xao * dodist) * denominator;

    return new Point(bx + dx, by + dy);
}

Point* Triangle::offCenter(double alpha){
    double ax, ay, bx, by, cx, cy;

    ax = this->vertexsp.at(0)->x();
    ay = this->vertexsp.at(0)->y();
    bx = this->vertexsp.at(1)->x();
    by = this->vertexsp.at(1)->y();
    cx = this->vertexsp.at(2)->x();
    cy = this->vertexsp.at(2)->y();

    double xdo, ydo, xao, yao;
    double dodist, aodist, dadist;
    double denominator;
    double dx, dy, dxoff, dyoff;
    double goodangle, offconstant;

    xdo = cx - bx;
    ydo = cy - by;
    xao = ax - bx;
    yao = ay - by;
    dodist = xdo * xdo + ydo * ydo;
    aodist = xao * xao + yao * yao;
    dadist = (cx - ax) * (cx - ax) +
           (cy - ay) * (cy - ay);
    denominator = 0.5 / (xdo * yao - xao * ydo);

    dx = (yao * dodist - ydo * aodist) * denominator;
    dy = (xdo * aodist - xao * dodist) * denominator;


    goodangle = cos(alpha * Constant::pi / 180.0);
    if (goodangle == 1.0) {
        offconstant = 0.0;
    } else {
        offconstant = 0.475 * sqrt((1.0 + goodangle) / (1.0 - goodangle));
    }
    if ((dodist < aodist) && (dodist < dadist)) {
        if (offconstant > 0.0) {
            dxoff = 0.5 * xdo - offconstant * ydo;
            dyoff = 0.5 * ydo + offconstant * xdo;
            if (dxoff * dxoff + dyoff * dyoff < dx * dx + dy * dy) {
                dx = dxoff;
                dy = dyoff;
            }
        }
    }
    else if (aodist < dadist) {
        if ((offconstant > 0.0)) {
            dxoff = 0.5 * xao + offconstant * yao;
            dyoff = 0.5 * yao - offconstant * xao;
            if (dxoff * dxoff + dyoff * dyoff < dx * dx + dy * dy) {
                dx = dxoff;
                dy = dyoff;
            }
        }
    }
    else {
        if ( (offconstant > 0.0)) {
            dxoff = 0.5 * (ax - cx) -
                    offconstant * (ay - cy);
            dyoff = 0.5 * (ay - cy) +
                    offconstant * (ax - cx);
            if (dxoff * dxoff + dyoff * dyoff <
                (dx - xdo) * (dx - xdo) + (dy - ydo) * (dy - ydo)) {
                    dx = xdo + dxoff;
                    dy = ydo + dyoff;
            }
        }
    }
    return new Point(bx + dx, by + dy);
}

Point* Triangle::centroid(){
    return new Point( (this->vertexsp.at(0)->x()+this->vertexsp.at(1)->x()+this->vertexsp.at(2)->x())/3.0, (this->vertexsp.at(0)->y()+this->vertexsp.at(1)->y()+this->vertexsp.at(2)->y())/3.0);
}


int Triangle::id(){
    return this->idp;
}

int Triangle::getLongestEdge(){
    double l0, l1, l2;
    l0 = Util::distance(this->vertex(1), this->vertex(2));
    l1 = Util::distance(this->vertex(2), this->vertex(0));
    l2 = Util::distance(this->vertex(0), this->vertex(1));
    if(l1 <= l0 && l2 <= l0)
        return 0;
    else if (l0 <= l1 && l2 <= l1)
        return 1;
    else
        return 2;
}

double Triangle::getLongestEdgeValue(){
    int i =  this->getLongestEdge();
    return Util::distance(this->vertex((i+1)%3), this->vertex((i+2)%3));
}

int Triangle::getSecondLongestEdge(){
    double l0, l1, l2;
    l0 = Util::distance(this->vertex(1), this->vertex(2));
    l1 = Util::distance(this->vertex(2), this->vertex(0));
    l2 = Util::distance(this->vertex(0), this->vertex(1));
    if(l0 <= l1 && l1 <= l2)
        return 1;
    else if(l0 <= l2 && l2 <= l2)
        return 2;
    else return 0;

}

int Triangle::getSmallestEdge(){
    double l0, l1, l2;
    l0 = Util::distance(this->vertexsp.at(1), this->vertexsp.at(2));
    l1 = Util::distance(this->vertexsp.at(2), this->vertexsp.at(0));
    l2 = Util::distance(this->vertexsp.at(0), this->vertexsp.at(1));
    if(l0 <= l1 && l0 <= l2)
        return 0;
    else if (l1 <= l0 && l1 <= l2)
        return 1;
    else
        return 2;
}

int Triangle::getSmallestAngle(){
    double a0, a1, a2;
    a0 = this->internalAngle(0);
    a1 = this->internalAngle(1);
    a2 = this->internalAngle(2);
    if( a0 <= a1 && a0 <= a2)
        return 0;
    if( a1 <= a0 && a1 <= a2)
        return 1;
    return 2;
}

double Triangle::getSmallestAngleValue(){
    return this->internalAngle(this->getSmallestAngle());
}

double Triangle::getSmallestEdgeValue(){
    return Util::distance(this->vertex( (this->getSmallestEdge()+1)%3 ), this->vertex( (this->getSmallestEdge()+2)%3));
}

int Triangle::getIndex(Vertex *v){
    for(unsigned int i = 0; i < 3; i++)
        if( this->vertexsp.at(i) == v)
            return i;
    return -1;
}

void Triangle::replaceNeighbour(Triangle *ti, Triangle *tf){
    for(unsigned int i = 0; i < 3; i++)
        if(this->neighboursp.at(i) == ti){
            this->neighboursp.replace(i, tf);
            return;
        }
    return;
}

bool  Triangle::hasNeighbour(int pos){
    if(this->neighboursp.at(pos) == 0)
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
    this->neighboursp.replace(pos, neighbour);
}

bool Triangle::isAnnoying(double angle){
    for( int i = 0; i < 3 ; i++)
        if(this->internalAnglesp.at(i) < angle)
            return true;
    return false;
}

bool Triangle::isConstrained(int edge){
    if(this->restrictedEdgesp.at(edge) || this->neighbour(edge) == 0)
        return true;
    return false;
}

bool Triangle::isConstrained(){
    return (this->isConstrained(0) || this->isConstrained(1) || this->isConstrained(2) );
}

bool Triangle::isBoundary(int edge){
    return (this->neighbour(edge) == 0);
}

bool Triangle::isBoundary(){
    return (this->isBoundary(0) || this->isBoundary(1) || this->isBoundary(2));
}

QVector<Triangle*> Triangle::neighbours(){
    return this->neighboursp;
}

double Triangle::internalAngle(int i){
    return this->internalAnglesp.at(i);
}

QVector<double> Triangle::internalAngles(){
    return this->internalAnglesp;
}

QVector<Vertex*> Triangle::vertexs(){
    return this->vertexsp;
}

Vertex* Triangle::vertex(int i){
    return this->vertexsp.at(i);
}

Point* Triangle::midpoint(int edge){
    return Util::midpoint(this->vertex((edge+1)%3), this->vertex((edge+2)%3));
}

Triangle* Triangle::neighbour(int i){
    if(0 <= i && i < 3)
        return this->neighboursp.at(i);
    return 0;
}

void Triangle::printInfo(){
    qDebug("tid:%d v%d(%f, %f) v%d(%f, %f) v%d(%f, %f) l0:%f l1:%f l2:%f a0:%f a1:%f a2:%f",
            this->id(),
            this->vertex(0)->id(), this->vertex(0)->x(), this->vertex(0)->y(),
            this->vertex(1)->id(), this->vertex(1)->x(), this->vertex(1)->y(),
            this->vertex(2)->id(), this->vertex(2)->x(), this->vertex(2)->y(),
            Util::distance(this->vertex(1), this->vertex(2)),
            Util::distance(this->vertex(2), this->vertex(0)),
            Util::distance(this->vertex(0), this->vertex(1)),
            this->internalAnglesp.at(0),
            this->internalAnglesp.at(1),
            this->internalAnglesp.at(2)
            );
}

Triangle::~Triangle(){

}

