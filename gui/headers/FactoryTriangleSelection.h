#ifndef FACTORYTRIANGLESELECTION_H
#define FACTORYTRIANGLESELECTION_H

#include "TriangleSelection.h"
#include "Constant.h"

class FactoryTriangleSelection
{
public:
    static TriangleSelection* build(Constant::TriangleSelection type);

};

#endif // FACTORYTRIANGLESELECTION_H
