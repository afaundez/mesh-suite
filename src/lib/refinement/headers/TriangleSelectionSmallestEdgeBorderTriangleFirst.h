#ifndef TRIANGLESELECTIONSMALLESTEDGEBORDERTRIANGLEFIRST_H
#define TRIANGLESELECTIONSMALLESTEDGEBORDERTRIANGLEFIRST_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestEdgeBorderTriangleFirst: public TriangleSelection{
public:
    TriangleSelectionSmallestEdgeBorderTriangleFirst(Mesh* mesh, double value);
    Triangle* process(Mesh* mesh);
    ~TriangleSelectionSmallestEdgeBorderTriangleFirst();
};

#endif // TRIANGLESELECTIONSMALLESTEDGEBORDERTRIANGLEFIRST_H
