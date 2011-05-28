#ifndef FACTORYTRIANGLESELECTION_H
#define FACTORYTRIANGLESELECTION_H

#include "lib/refinement/triangle_selection/TriangleSelection.h"
#include "lib/refinement/Constant.h"

class FactoryTriangleSelection
{
public:
    static TriangleSelection* build(Constant::TriangleSelection type);

};

#endif // FACTORYTRIANGLESELECTION_H
