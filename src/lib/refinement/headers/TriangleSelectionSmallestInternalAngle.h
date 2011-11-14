#ifndef TRIANGLESELECTIONSMALLESTINTERNALANGLE_H
#define TRIANGLESELECTIONSMALLESTINTERNALANGLE_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestInternalAngle: public TriangleSelection{
public:
    TriangleSelectionSmallestInternalAngle(Mesh* mesh, double value);
    Triangle* process(Mesh* mesh);
    ~TriangleSelectionSmallestInternalAngle();
};

#endif // TRIANGLESELECTIONSMALLESTINTERNALANGLE_H
