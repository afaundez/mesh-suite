#ifndef TRIANGLESELECTIONFACTORY_H
#define TRIANGLESELECTIONFACTORY_H

#include "TriangleSelection.h"
#include "Constant.h"

class TriangleSelectionFactory
{
public:
    static TriangleSelection* build(Constant::TriangleSelectionType type);

};

#endif // TRIANGLESELECTIONFACTORY_H
