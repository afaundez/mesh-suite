#ifndef FACTORYTRIANGLESELECTION_H
#define FACTORYTRIANGLESELECTION_H

#include "TriangleSelection.h"
#include "Constant.h"
#include "src/lib/geometric/headers/Mesh.h"

class FactoryTriangleSelection
{
public:
    static TriangleSelection* build(Constant::TriangleSelection type, Mesh* mesh, double value);

};

#endif // FACTORYTRIANGLESELECTION_H
