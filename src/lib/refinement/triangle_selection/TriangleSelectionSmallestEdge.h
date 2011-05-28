#ifndef TRIANGLESELECTIONSMALLESTEDGE_H
#define TRIANGLESELECTIONSMALLESTEDGE_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestEdge: public TriangleSelection{
public:
    TriangleSelectionSmallestEdge();
    Triangle* process(Mesh* mesh, double value);
    ~TriangleSelectionSmallestEdge();
};

#endif // TRIANGLESELECTIONSMALLESTEDGE_H
