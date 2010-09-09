#ifndef MESH_H
#define MESH_H

#include <QHash>
#include <QPoint>
#include "Triangle.h"

class Mesh
{

public:
    Mesh(QString fileName);
    void addTriangle(Triangle* T);
    Triangle* createAndAddTriangle(Vertex* A, Vertex* B, Vertex *C);
    void addVertex(Vertex* A);
    Vertex* createAndAddVertex(double x, double y);
    void drawMesh();
    bool hasTriangles();
    Triangle* getSelectedTriangle();
    void setSelectedTriangle(Triangle* T);
    Triangle* getTriangle(Point* p);
    void removeTriangle(Triangle* T);
    void removeTriangle(int tid);
    void removeAndDeleteTriangle(Triangle* T);
    void removeAndDeleteTriangle(int tid);
    bool isVirgin();
    void setVirgin(bool virgin);
    int vertexsSize();
    int trianglesSize();
    void setScale(double scale);
    double scale();
    void setXCenter(int x);
    void setYCenter(int y);
    Point* center();

    double minAngle();

    void setLastSelectedTriangleID(int id);
    int lastSelectedTriangleID();

    void setValue(double v);
    double value();
    Triangle* triangle(int id);
    QHash<int, Triangle*>    triangles();
    QHash<int, Vertex*>      vertexs();
    ~Mesh();

private:
    QHash<int, Triangle*>    trianglesp;
    QHash<int, Vertex*>      vertexsp;
    int cv, ct;
    double scalep;
    Point* centerp;
    Triangle* selectedTriangle;
    int lastSelectedTriangleIDp;
    bool virginp;
    double valuep;
};

#endif // MESH_H
