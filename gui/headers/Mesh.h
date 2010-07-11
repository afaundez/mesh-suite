#ifndef MESH_H
#define MESH_H

#include <QHash>
#include <QPoint>
#include "Triangle.h"

class Mesh
{

public:
    Mesh(QString fileName);
    ~Mesh();
    void addTriangle(Triangle* T);
    Triangle* createAndAddTriangle(Vertex* A, Vertex* B, Vertex *C);
    void addVertex(Vertex* A);
    Vertex* createAndAddVertex(double x, double y);
    void drawMesh(Point* lastPos);
    float lowerX, lowerY;
    float higherX, higherY;
    float scale;
    bool hasTriangles();
    Triangle* getSelectedTriangle();
    void setSelectedTriangle(Triangle* T);
    void removeTriangle(Triangle* T);
    void removeTriangle(int tid);
    void removeAndDeleteTriangle(Triangle* T);
    void removeAndDeleteTriangle(int tid);
    bool isVirgin();
    void setVirgin(bool virgin);

private:
    QHash<int, Triangle*>    triangles;
    QHash<int, Vertex*>      vertexs;
    int cv, ct;
    Triangle* selectedTriangle;
    bool virginp;
};

#endif // MESH_H
