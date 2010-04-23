#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "Vertex.h"


class Triangle
{

public:
    Triangle(int id, Vertex* A, Vertex* B, Vertex* C);
    ~Triangle();
    int getId();
    void setTriangles(Triangle* A, Triangle* B, Triangle* C);
    Triangle* getOppositeTriangle(Vertex* P);
    Triangle* getOppositeTriangle(int p);
    Vertex* getVertex(int p);

private:
    int id;
    std::vector<int> angles;
    std::vector<Vertex*> vertexs;
    std::vector<Triangle*> triangles;
};
#endif // TRIANGLE_H
