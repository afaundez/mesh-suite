#ifndef VERTEX_H
#define VERTEX_H

#include "Constant.h"

class Vertex
{

public:
    Vertex(int id, double _x, double _y);
    ~Vertex();
    int id();
    double x();
    double y();
    double distance(Vertex* Q);
    void glDraw();

private:
    int idp;
    double xp;
    double yp;
};

#endif // VERTEX_H
