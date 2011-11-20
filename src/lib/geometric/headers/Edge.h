#ifndef EDGE_H
#define EDGE_H

#include <QPoint>
#include <QVector>
#include <vector>
#include "src/lib/geometric/headers/Vertex.h"
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/geometric/headers/Point.h"
#include "src/lib/refinement/headers/Constant.h"

class RestrictedEdge
{

public:
    RestrictedEdge(int id, Vertex* v0, Vertex* v1, Constant::ObjectStatus status); // direction: v0 -> v1

    int id();

    void setStatus(Constant::ObjectStatus status);
    Constant::ObjectStatus getStatus();

    Vertex* getVertex(int i);
    void setAdjacentTriangles(Triangle* t0, Triangle* t1); // i == 0 => left, i == 1 => right
    QVector<Triangle*> getAdjacentTriangles();
    void setAdjacentTriangle(int i, Triangle* t);
    Triangle* getAdjacentTriangle(int i);
    bool hasAdjacentTriangle(int i);
    QVector<Vertex*> getVertexs();
    /*int edgeIndexInTriangle(Triangle* t);*/
    int belongsTo(Triangle* t);
    bool isConstrained();
    Constant::IncludeCase diametralCircleInclude(Point *p);
    bool isEncroached();
    //Vertex* getEncroachedVertex();
    Point* midpoint();
    double length();

    ~RestrictedEdge();

private:
    int idp;
    Constant::ObjectStatus statusp;
    QVector<Vertex*> vertexsp;
    QVector<Triangle*> adjacenttrianglesp;

};

#endif // EDGE_H
