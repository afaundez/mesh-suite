#include "src/lib/refinement/headers/Queue.h"
#include "src/lib/refinement/headers/Constant.h"

Queue::Queue(Mesh* mesh, double value): QueueOfTrianglesToProcess(){
    this->q = new std::queue<Triangle*>();
    this->addTrianglesToProcessToQueue(mesh, value);
}

void Queue::addTrianglesToProcessToQueue(Mesh* mesh, double value){
    foreach(Triangle* t, mesh->triangles()){
        if( t->isAnnoying(value)){
            this->push(t);
        }
    }
}

Triangle* Queue::getNextTriangleToProcess(){
    Triangle* t = 0;

    while(!this->q->empty()){
        t = this->q->front(); //this->q->pop();
        if(t->getStatus() == Constant::DEAD){
            this->q->pop();
            delete t;
            t = 0;
        } else {
            return t;
        }
    }
    return t;
}

void Queue::push(Triangle *t){
        t->setStatus(Constant::IN_DEATH_ROW);
        this->q->push(t);
}

bool Queue::empty(){
    return this->q->empty();
}

Queue::~Queue(){
    delete this->q;
}

