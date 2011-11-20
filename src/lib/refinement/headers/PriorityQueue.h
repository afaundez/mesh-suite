#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/Comparator.h"
#include "src/lib/refinement/headers/Constant.h"
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/geometric/headers/Mesh.h"
#include <queue>
#include <vector>

class PriorityQueue: public QueueOfTrianglesToProcess{
private:
    std::priority_queue<Triangle*, std::vector<Triangle*>, Comparator> *q;

public:
    PriorityQueue(Mesh* mesh, Constant::TriangleSelection type, double value);
    void addTrianglesToProcessToQueue(Mesh* mesh, double value);
    Triangle* getNextTriangleToProcess();
    void push(Triangle* t);
    bool empty();
    ~PriorityQueue();
};


#endif // PRIORITYQUEUE_H
