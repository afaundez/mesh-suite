#ifndef FACTORYPREPROCESS_H
#define FACTORYPREPROCESS_H

#include "PreProcess.h"
#include "Constant.h"
#include "Mesh.h"
#include "Options.h"

class FactoryPreProcess
{
public:
    static PreProcess* build(Constant::PreProcess type, Mesh* m, Options* options);

};

#endif // FACTORYPREPROCESS_H
