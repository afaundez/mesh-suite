#ifndef PREPROCESSFACTORY_H
#define PREPROCESSFACTORY_H

#include "PreProcess.h"
#include "Constant.h"

class PreProcessFactory
{
public:
    static PreProcess* build(Constant::PreProcess type);

};
#endif // PREPROCESSFACTORY_H
