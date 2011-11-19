#include "src/lib/geometric/headers/Edge.h"
#include "src/lib/refinement/headers/Util.h"

RestrictedEdge::RestrictedEdge(int id, Vertex* v0, Vertex* v1, Constant::ObjectStatus status){
    this->idp = id;

    this->vertexsp.insert(0, v0);
    this->vertexsp.insert(1, v1);

    this->adjacenttrianglesp.insert(0,0);
    this->adjacenttrianglesp.insert(1,0);

    this->statusp = status;
}

void RestrictedEdge::setStatus(Constant::ObjectStatus status){
    this->statusp = status;
}

Constant::ObjectStatus RestrictedEdge::getStatus(){
    return this->statusp;
}

Vertex* RestrictedEdge::getVertex(int i){
    if (0 <= i && i < 2)
        return this->vertexsp.at(i);
    return 0;
}

int RestrictedEdge::id(){
    return this->idp;
}

void RestrictedEdge::setAdjacentTriangles(Triangle* t0, Triangle* t1){
    this->adjacenttrianglesp.replace(0,t0);
    this->adjacenttrianglesp.replace(1,t1);
}

QVector<Triangle*> RestrictedEdge::getAdjacentTriangles(){
    return this->adjacenttrianglesp;
}

void RestrictedEdge::setAdjacentTriangle(int i, Triangle* t){
    this->adjacenttrianglesp.replace(i,t);
}

Triangle* RestrictedEdge::getAdjacentTriangle(int i){
    if (0 <= i && i < 2)
        return this->adjacenttrianglesp.at(i);
    return 0;
}

bool RestrictedEdge::hasAdjacentTriangle(int i){
    return this->adjacenttrianglesp.at(i) != 0;
}

QVector<Vertex*> RestrictedEdge::getVertexs(){
    return this->vertexsp;
}


/*int Edge::edgeIndexInTriangle(Triangle* t){
    foreach(Vertex* v, t->vertexs()){
        if(this->id() == t->getRestricted(t->getIndex(v)));
    }

}*/

int RestrictedEdge::belongsTo(Triangle* t){
    for(int j = 0; j < 3; j++){
            if(t->vertex((j+1)%3) == this->getVertex(0) && t->vertex((j+2)%3) == this->getVertex(1) ||
               t->vertex((j+1)%3) == this->getVertex(1) && t->vertex((j+2)%3) == this->getVertex(0))
            {
                return j;
            }
        }
     return -1;

    //if(this->edgeIndexInTriangle(t) > -1) return true;
    //return false;
}

bool RestrictedEdge::isConstrained(){
    if(this->adjacenttrianglesp.at(0) == 0 || this->adjacenttrianglesp.at(1) == 0)
        return true;
    return false;
}

Constant::IncludeCase RestrictedEdge::diametralCircleInclude(Point *p){

    Constant::IncludeCase ic;
    Point* c =  this->midpoint();
    double R, r;
    R = Util::distance(this->getVertex(0), c);
    r = Util::distance(c, p);
    if (r <= R)
        ic = Constant::INCLUDED;
    else
        ic = Constant::NOT_INCLUDED;
    return ic;
}

bool RestrictedEdge::isEncroached(){
    foreach(Triangle* t, this->adjacenttrianglesp){

        if( t != 0){
            if( this->diametralCircleInclude(t->getVertex(t->getIndex(this->id()))) == Constant::INCLUDED ){
                return true;
            }
        }
    }
    return false;
}

Point* RestrictedEdge::midpoint(){
    return Util::midpoint(this->getVertex(0), this->getVertex(1));
}

RestrictedEdge::~RestrictedEdge(){

}
