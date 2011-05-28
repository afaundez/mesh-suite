#ifndef TRIANGLESELECTIONLONGEDGEONLYBORDER_H
#define TRIANGLESELECTIONLONGEDGEONLYBORDER_H

#include "TriangleSelection.h"

class TriangleSelectionLongEdgeOnlyBorder: public TriangleSelection{
public:
    TriangleSelectionLongEdgeOnlyBorder();
    Triangle* process(Mesh* mesh, double value);
    ~TriangleSelectionLongEdgeOnlyBorder();
};

#endif // TRIANGLESELECTIONLONGEDGEONLYBORDER_H
