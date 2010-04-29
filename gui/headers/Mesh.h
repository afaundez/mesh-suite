#ifndef MESH_H
#define MESH_H

#include <QHash>
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
    void drawMesh(int w, int h);
    float lowerX, lowerY;
    float higherX, higherY;

private:
    QHash<int, Triangle*>    triangles;
    QHash<int, Vertex*>      vertexs;
    int cv;
    int ct;
};

#endif // MESH_H
