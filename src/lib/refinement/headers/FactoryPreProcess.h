#ifndef FACTORYPREPROCESS_H
#define FACTORYPREPROCESS_H

#include "PreProcess.h"
#include "Constant.h"
#include "src/lib/geometric/headers/Mesh.h"
#include "Options.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"

class FactoryPreProcess
{
public:
    static PreProcess* build(Constant::PreProcess type, Mesh* m, QueueOfTrianglesToProcess* qt, Options* options);

};

#endif // FACTORYPREPROCESS_H
