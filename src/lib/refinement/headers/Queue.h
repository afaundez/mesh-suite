#ifndef QUEUE_H
#define QUEUE_H

#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/geometric/headers/Mesh.h"
#include <queue>
#include <vector>

class Queue: public QueueOfTrianglesToProcess{
private:
    std::queue<Triangle*> *q;

public:
    Queue(double value);
    void addTrianglesToProcessToQueue(Mesh* mesh);
    Triangle* pop();
    bool push(Triangle* t);
    bool empty();
    ~Queue();
};

#endif // QUEUE_H