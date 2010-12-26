#ifndef TRIANGLESELECTIONNOPRIORITY_H
#define TRIANGLESELECTIONNOPRIORITY_H

#include "TriangleSelection.h"

class TriangleSelectionNoPriority: public TriangleSelection{
public:
    TriangleSelectionNoPriority();
    Triangle* process(Mesh* mesh, double value);
    ~TriangleSelectionNoPriority();
};

#endif // TRIANGLESELECTIONNOPRIORITY_H
