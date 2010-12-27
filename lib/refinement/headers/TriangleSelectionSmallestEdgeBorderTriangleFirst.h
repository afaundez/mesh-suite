#ifndef TRIANGLESELECTIONSMALLESTEDGEBORDERTRIANGLEFIRST_H
#define TRIANGLESELECTIONSMALLESTEDGEBORDERTRIANGLEFIRST_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestEdgeBorderTriangleFirst: public TriangleSelection{
public:
    TriangleSelectionSmallestEdgeBorderTriangleFirst();
    Triangle* process(Mesh* mesh, double value);
    ~TriangleSelectionSmallestEdgeBorderTriangleFirst();
};

#endif // TRIANGLESELECTIONSMALLESTEDGEBORDERTRIANGLEFIRST_H
