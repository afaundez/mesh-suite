#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include <QVector>
#include <vector>
#include "lib/geometric/Vertex.h"
#include "lib/geometric/Point.h"
#include "lib/refinement/Constant.h"


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
    void glDraw(Constant::GLTriangleType type, double value);
    Constant::IncludeCase include(Point* point);
    Constant::IncludeCase circumcircleInclude(Point* p);
    Point* circumcenter();
    Point* offCenter(double alpha);
    double circumradius();
    Point* centroid();
    void setNeighbour(int pos, Triangle* neighbour);
    int getLongestEdge();
    double getLongestEdgeValue();
    int getSecondLongestEdge();
    int getSmallestEdge();
    int getSmallestAngle();
    double getSmallestAngleValue();
    double getSmallestEdgeValue();
    int getIndex(Vertex* v);
    void replaceNeighbour(Triangle* ti, Triangle* tf);
    bool isAnnoying(double angle);
    void setRestricted(int edge);
    bool isRestricted(int edge);
    bool isConstrained(int edge);
    bool isConstrained();
    bool isBoundary(int edge);
    bool isBoundary();
    int wichBorder(Point* p);
    void printInfo();



    Constant::IncludeCase edgeInclude(int edge, Point* p);
    QVector<Triangle*> lepp();

    Point* midpoint(int edge);
    Triangle* neighbour(int edge);
    Vertex* vertex(int i);
    QVector<Vertex*> vertexs();
    QVector<Triangle*> neighbours();
    double internalAngle(int i);
    QVector<double> internalAngles();
    ~Triangle();

private:
    int idp;
    QVector<bool> restrictedEdgesp;
    QVector<double> internalAnglesp;
    QVector<Vertex*> vertexsp;
    QVector<Triangle*> neighboursp;
};
#endif // TRIANGLE_H
