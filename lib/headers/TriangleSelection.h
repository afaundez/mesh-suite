#ifndef TRIANGLESELECTION_H
#define TRIANGLESELECTION_H

#include "Triangle.h"
#include "Mesh.h"

class TriangleSelection{
public:
    virtual ~TriangleSelection() {};
    virtual Triangle* process(Mesh* mesh, double value) = 0;
};

#endif // TRIANGLESELECTION_H
