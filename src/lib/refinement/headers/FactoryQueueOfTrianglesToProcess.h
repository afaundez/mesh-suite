#ifndef FACTORYQUEUEOFTRIANGLESTOPROCESS_H
#define FACTORYQUEUEOFTRIANGLESTOPROCESS_H

#include "QueueOfTrianglesToProcess.h"
#include "Constant.h"
#include "src/lib/geometric/headers/Mesh.h"

class FactoryQueueOfTrianglesToProcess
{
public:
    static QueueOfTrianglesToProcess* build(Constant::TriangleSelection type, Mesh* m, double value);

};

#endif // FACTORYQUEUEOFTRIANGLESTOPROCESS_H
