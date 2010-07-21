#ifndef TRIANGLESELECTIONSMALLESTCIRCUMRADIUS_H
#define TRIANGLESELECTIONSMALLESTCIRCUMRADIUS_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestCircumradius: public TriangleSelection{
public:
    TriangleSelectionSmallestCircumradius();
    Triangle* process(Mesh* mesh, double value);
    ~TriangleSelectionSmallestCircumradius();
};
#endif // TRIANGLESELECTIONSMALLESTCIRCUMRADIUS_H
