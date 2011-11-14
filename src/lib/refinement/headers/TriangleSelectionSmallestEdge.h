#ifndef TRIANGLESELECTIONSMALLESTEDGE_H
#define TRIANGLESELECTIONSMALLESTEDGE_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestEdge: public TriangleSelection{
public:
    TriangleSelectionSmallestEdge(Mesh* mesh, double value);
    Triangle* process(Mesh* mesh);
    ~TriangleSelectionSmallestEdge();
};

#endif // TRIANGLESELECTIONSMALLESTEDGE_H
