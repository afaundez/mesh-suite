#include "src/lib/refinement/headers/PriorityQueue.h"

PriorityQueue::PriorityQueue(Mesh* mesh, Constant::TriangleSelection type, double value){
    this->q = new std::priority_queue<Triangle*, std::vector<Triangle*>, Comparator>(Comparator(type, mesh));
    this->addTrianglesToProcessToQueue(mesh, value);
}

void PriorityQueue::addTrianglesToProcessToQueue(Mesh* mesh, double value){
    foreach(Triangle* t, mesh->triangles()){
        if( t->isAnnoying(value)){
            this->push(t);
        }
    }
}

Triangle* PriorityQueue::getNextTriangleToProcess(){
    Triangle* t = 0;

    while(!this->q->empty()){
        t = this->q->top();
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

void PriorityQueue::push(Triangle* t){

    t->setStatus(Constant::IN_DEATH_ROW);
    this->q->push(t);
}

Triangle* PriorityQueue::pop(){
    Triangle *aux = this->q->top();
    this->q->pop();
    return aux;
}

bool PriorityQueue::empty(){
    return this->q->empty();
}

int PriorityQueue::size(){
    return this->q->size();
}

PriorityQueue::~PriorityQueue(){
    delete q;
}
