#ifndef FACTORYQUEUEOFTRIANGLESTOPROCESS_H
#define FACTORYQUEUEOFTRIANGLESTOPROCESS_H

#include "QueueOfTrianglesToProcess.h"
#include "Constant.h"

class FactoryQueueOfTrianglesToProcess
{
public:
    static QueueOfTrianglesToProcess* build(Constant::TriangleSelection type, double value);

};

#endif // FACTORYQUEUEOFTRIANGLESTOPROCESS_H
