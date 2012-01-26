#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include <QVector>
#include <vector>
#include "src/lib/geometric/headers/Vertex.h"
#include "src/lib/geometric/headers/Point.h"
#include "src/lib/refinement/headers/Constant.h"


class Triangle
{

public:
    Triangle(int id, Vertex* v0, Vertex* v1, Vertex* v2, Constant::ObjectStatus status);
    int id();

    void setStatus(Constant::ObjectStatus status);
    Constant::ObjectStatus getStatus();

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
    int getIndexOfEdge(int edge_id);
    void replaceNeighbour(Triangle* ti, Triangle* tf);
    bool isAnnoying(double angle);
    void setRestricted(int t_edge, int edge_id);
    bool isRestricted(int t_edge);
    int getRestricted(int t_edge);
    bool isConstrained(int t_edge);
    bool isConstrained();
    bool isBoundary(int t_edge);
    bool isBoundary();
    int wichBorder(Point* p);
    void printInfo();



    Constant::IncludeCase edgeInclude(int t_edge, Point* p);
    QVector<Triangle*> lepp();

    Point* midpoint(int t_edge);
    Triangle* neighbour(int t_edge);
    Vertex* vertex(int i);
    QVector<Vertex*> vertexs();
    QVector<Triangle*> neighbours();
    double internalAngle(int i);
    QVector<double> internalAngles();
    ~Triangle();

private:
    int idp;
    Constant::ObjectStatus statusp;
    QVector<int> restrictedEdgesp;
    QVector<double> internalAnglesp;
    QVector<Vertex*> vertexsp;
    QVector<Triangle*> neighboursp;
};
#endif // TRIANGLE_H
