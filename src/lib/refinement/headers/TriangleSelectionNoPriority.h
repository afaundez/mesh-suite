#ifndef TRIANGLESELECTIONNOPRIORITY_H
#define TRIANGLESELECTIONNOPRIORITY_H

#include "TriangleSelection.h"
#include "src/lib/geometric/headers/Mesh.h"

class TriangleSelectionNoPriority: public TriangleSelection{
public:
    TriangleSelectionNoPriority(Mesh* mesh, double value);
    Triangle* process(Mesh* mesh);
    ~TriangleSelectionNoPriority();
};

#endif // TRIANGLESELECTIONNOPRIORITY_H
