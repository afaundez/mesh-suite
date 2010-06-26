#ifndef PREPROCESSFACTORY_H
#define PREPROCESSFACTORY_H

#include "PreProcess.h"
#include "Constant.h"

class PreProcessFactory
{
public:
    static PreProcess* build(Constant::PreProcessType type);

};
#endif // PREPROCESSFACTORY_H
