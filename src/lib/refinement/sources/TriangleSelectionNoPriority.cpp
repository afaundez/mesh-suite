#include "src/lib/refinement/headers/TriangleSelectionNoPriority.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/Queue.h"

TriangleSelectionNoPriority::TriangleSelectionNoPriority(Mesh* mesh, double value): TriangleSelection(){
    QueueOfTrianglesToProcess* q = new Queue(value);
    q->addTrianglesToProcessToQueue(mesh);
    mesh->setQueueOfTrianglesToProcess(q);
}

Triangle* TriangleSelectionNoPriority::process(Mesh* mesh){
    Triangle* ret = 0;
    /* double minCircumradius = -1.0;
    foreach(Triangle* t, mesh->triangles())
        if( t->getSmallestAngleValue() < value)
            return t; */
    if(!mesh->queueOfTrianglesToProcess()->empty()){
        qDebug("return T from queue");
        return mesh->queueOfTrianglesToProcess()->pop();
    }
    qDebug("T");
    return ret;
}

TriangleSelectionNoPriority::~TriangleSelectionNoPriority(){

}

