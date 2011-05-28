#ifndef TRIANGLESELECTIONSMALLESTINTERNALANGLE_H
#define TRIANGLESELECTIONSMALLESTINTERNALANGLE_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestInternalAngle: public TriangleSelection{
public:
    TriangleSelectionSmallestInternalAngle();
    Triangle* process(Mesh* mesh, double value);
    ~TriangleSelectionSmallestInternalAngle();
};

#endif // TRIANGLESELECTIONSMALLESTINTERNALANGLE_H
