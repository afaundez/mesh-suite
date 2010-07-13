#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include <QVector>
#include <vector>
#include "Vertex.h"
#include "Point.h"


class Triangle
{

public:
    Triangle(int id, Vertex* v0, Vertex* v1, Vertex* v2);
    int id();
    void setNeighbours(Triangle* n0, Triangle* n1, Triangle* n2);
    Triangle* getNeighbour(Vertex* P);
    Triangle* getNeighbour(int p);
    bool hasNeighbour(int pos);
    int isNeighbour(Triangle* neighbour);
    Vertex* getVertex(int p);
    void glDraw(Constant::GLTriangleType type);
    double orientation(Vertex* A, Vertex* B, Point* P);
    Constant::IncludeCase include(Point* point);
    Constant::IncludeCase circumcircleInclude(Point* p);
    Constant::IncludeCase circumcircleInclude(Vertex* v);
    Point* getCircumcenter();
    double getCircumradius();
    void setNeighbour(int pos, Triangle* neighbour);
    int getLongestEdge();
    Constant::RestrictedType getRestrictedType();
    int getIndex(Vertex* v);
    void replaceNeighbour(Triangle* ti, Triangle* tf);
    int wichBorder(Point* p);
    ~Triangle();

private:
    int idp;
    QVector<bool> restrictedEdges;
    QVector<double> internalAngles;
    QVector<Vertex*> vertexs;
    QVector<Triangle*> neighbours;
};
#endif // TRIANGLE_H
