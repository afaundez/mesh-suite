#ifndef TRIANGLESELECTIONSMALLESTCIRCUMRADIUS_H
#define TRIANGLESELECTIONSMALLESTCIRCUMRADIUS_H

#include "TriangleSelection.h"

class TriangleSelectionSmallestCircumradius: public TriangleSelection{
public:
    TriangleSelectionSmallestCircumradius(Mesh* mesh, double value);
    Triangle* process(Mesh* mesh);
    ~TriangleSelectionSmallestCircumradius();
};
#endif // TRIANGLESELECTIONSMALLESTCIRCUMRADIUS_H
