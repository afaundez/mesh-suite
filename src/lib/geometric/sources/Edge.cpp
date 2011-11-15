#include "src/lib/geometric/headers/Edge.h"
#include "src/lib/refinement/headers/Util.h"

Edge::Edge(int id, Vertex* v0, Vertex* v1, Constant::ObjectStatus status){
    this->idp = id;

    this->vertexsp.insert(0, v0);
    this->vertexsp.insert(1, v1);

    this->adjacenttrianglesp.insert(0,0);
    this->adjacenttrianglesp.insert(1,0);

    this->statusp = status;
}

void Edge::setStatus(Constant::ObjectStatus status){
    this->statusp = status;
}

Constant::ObjectStatus Edge::getStatus(){
    return this->statusp;
}

Vertex* Edge::getVertex(int i){
    if (0 <= i && i < 2)
        return this->vertexsp.at(i);
    return 0;
}

int Edge::id(){
    return this->idp;
}

void Edge::setAdjacentTriangles(Triangle* t0, Triangle* t1){
    this->adjacenttrianglesp.insert(0,t0);
    this->adjacenttrianglesp.insert(1,t1);
}

QVector<Triangle*> Edge::getAdjacentTriangles(){
    return this->adjacenttrianglesp;
}

void Edge::setAdjacentTriangle(int i, Triangle* t){
    this->adjacenttrianglesp.replace(i,t);
}

Triangle* Edge::getAdjacentTriangle(int i){
    if (0 <= i && i < 2)
        return this->adjacenttrianglesp.at(i);
    return 0;
}

bool Edge::hasAdjacentTriangle(int i){
    return this->adjacenttrianglesp.at(i) != 0;
}

QVector<Vertex*> Edge::getVertexs(){
    return this->vertexsp;
}

bool Edge::isConstrained(){
    if(this->adjacenttrianglesp.at(0) == 0 || this->adjacenttrianglesp.at(1) == 0)
        return true;
    return false;
}

/*Constant::IncludeCase Edge::diametralCircleInclude(Point *p){
    Constant::IncludeCase ic;
    Point* c =  this->midpoint();
    double R, r;
    R = Util::distance(this->getVertex(0), c);
    r = Util::distance(c, p);
    if (r <= R)
        ic = Constant::INCLUDED;
    //else if(r == R)
    //    ic = Constant::BORDER_INCLUDED;
    else
        ic = Constant::NOT_INCLUDED;
    return ic;
} */

bool Edge::isEncroached(){
    //Constant::IncludeCase ic;
    Point* c =  this->midpoint();
    double R, r;
    R = Util::distance(this->getVertex(0), c);

    foreach(Triangle* t, this->adjacenttrianglesp){
        for(int i = 0; i < 3; i++){
            if(t->isRestricted(i) && (t->vertex((i+1)%3) == this->getVertex(0) && t->vertex((i+2)%3) == this->getVertex(1))){
                r = Util::distance(c, t->getVertex(i));
                if (r <= R)
                    return true;
            }
        }
    }
    return false;
}

Point* Edge::midpoint(){
    return Util::midpoint(this->getVertex(0), this->getVertex(1));
}

Edge::~Edge(){

}
