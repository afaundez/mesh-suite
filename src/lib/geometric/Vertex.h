#ifndef VERTEX_H
#define VERTEX_H

#include "Point.h"

class Vertex: public Point{

public:
    Vertex(int id, double _x, double _y);
    int id();
    void glDraw();
    ~Vertex();

private:
    int idp;
};

#endif // VERTEX_H
