#ifndef QUEUEOFENCROACHEDEDGES_H
#define QUEUEOFENCROACHEDEDGES_H

#include "src/lib/geometric/headers/Edge.h"
#include "src/lib/geometric/headers/Mesh.h"
#include <queue>
#include <vector>

class QueueOfEncroachedEdges{

private:
    std::queue<Edge*> *q;

public:
    QueueOfEncroachedEdges(Mesh* mesh);
    ~QueueOfEncroachedEdges();
    void addEdgesToProcessToQueue(Mesh* mesh);

    Edge* getNextEdgeToProcess();
    void push(Edge* e);
    bool empty();

};

#endif // QUEUEOFENCROACHEDEDGES_H
