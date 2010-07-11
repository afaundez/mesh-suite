#ifndef TRIANGLESELECTIONSMALLESTEDGE_H
#define TRIANGLESELECTIONSMALLESTEDGE_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestEdge: public TriangleSelection{
public:
    TriangleSelectionSmallestEdge();
    Triangle* process(Mesh* mesh, int value);
    ~TriangleSelectionSmallestEdge();
};

#endif // TRIANGLESELECTIONSMALLESTEDGE_H
