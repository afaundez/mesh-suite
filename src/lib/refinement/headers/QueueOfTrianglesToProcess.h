#ifndef QUEUEOFTRIANGLESTOPROCESS_H
#define QUEUEOFTRIANGLESTOPROCESS_H

#include "src/lib/geometric/headers/Triangle.h"

class QueueOfTrianglesToProcess{
public:
    virtual ~QueueOfTrianglesToProcess() {}
    virtual void addTrianglesToProcessToQueue(class Mesh* mesh) = 0;
    virtual Triangle* pop() = 0;
    virtual bool push(Triangle* t) = 0;
    virtual bool empty() = 0;
protected:
    double tsvp;
};

#endif // QUEUEOFTRIANGLESTOPROCESS_H