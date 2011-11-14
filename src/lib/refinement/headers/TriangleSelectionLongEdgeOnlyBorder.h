#ifndef TRIANGLESELECTIONLONGEDGEONLYBORDER_H
#define TRIANGLESELECTIONLONGEDGEONLYBORDER_H

#include "TriangleSelection.h"

class TriangleSelectionLongEdgeOnlyBorder: public TriangleSelection{
public:
    TriangleSelectionLongEdgeOnlyBorder(Mesh* mesh, double value);
    Triangle* process(Mesh* mesh);
    ~TriangleSelectionLongEdgeOnlyBorder();
};

#endif // TRIANGLESELECTIONLONGEDGEONLYBORDER_H
