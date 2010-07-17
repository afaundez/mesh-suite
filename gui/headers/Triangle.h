#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include <QVector>
#include <vector>
#include "Vertex.h"
#include "Point.h"
#include "Constant.h"


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
    Point* getCircumcenter();
    double getCircumradius();
    Point* getCentroid();
    void setNeighbour(int pos, Triangle* neighbour);
    int getLongestEdge();
    Constant::RestrictedType getRestrictedType();
    int getIndex(Vertex* v);
    void replaceNeighbour(Triangle* ti, Triangle* tf);
    bool isAnnoying(double angle);
    int wichBorder(Point* p);


    Constant::IncludeCase edgeInclude(int edge, Point* p);

    Point* midpoint(int edge);
    Vertex* vertex(int i);
    QVector<Vertex*> vertexs();
    QVector<Triangle*> neighbours();
    ~Triangle();

private:
    int idp;
    QVector<bool> restrictedEdgesp;
    QVector<double> internalAnglesp;
    QVector<Vertex*> vertexsp;
    QVector<Triangle*> neighboursp;
};
#endif // TRIANGLE_H
