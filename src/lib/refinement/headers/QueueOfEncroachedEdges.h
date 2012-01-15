#ifndef QUEUEOFENCROACHEDEDGES_H
#define QUEUEOFENCROACHEDEDGES_H

#include "src/lib/geometric/headers/Edge.h"
#include "src/lib/geometric/headers/Mesh.h"
#include <queue>
#include <vector>

class QueueOfEncroachedEdges{

private:
    std::queue<RestrictedEdge*> *q;

public:
    QueueOfEncroachedEdges();
    //QueueOfEncroachedEdges(Mesh* mesh);
    ~QueueOfEncroachedEdges();
    void addEdgesToProcessToQueue(Mesh* mesh);

    RestrictedEdge* getNextEdgeToProcess();
    void push(RestrictedEdge* e);
    bool empty();
    int size();
};

#endif // QUEUEOFENCROACHEDEDGES_H
