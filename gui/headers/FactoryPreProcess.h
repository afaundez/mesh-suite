#ifndef FACTORYPREPROCESS_H
#define FACTORYPREPROCESS_H

#include "PreProcess.h"
#include "Constant.h"

class FactoryPreProcess
{
public:
    static PreProcess* build(Constant::PreProcess type);

};

#endif // FACTORYPREPROCESS_H
