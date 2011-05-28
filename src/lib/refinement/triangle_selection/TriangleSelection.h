#ifndef TRIANGLESELECTION_H
#define TRIANGLESELECTION_H

#include "lib/geometric/Triangle.h"
#include "lib/geometric/Mesh.h"

class TriangleSelection{
public:
    virtual ~TriangleSelection() {};
    virtual Triangle* process(Mesh* mesh, double value) = 0;
};

#endif // TRIANGLESELECTION_H
