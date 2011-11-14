#include "src/lib/refinement/headers/Queue.h"
#include "src/lib/refinement/headers/Constant.h"
int triangles = 0;
Queue::Queue(double value): QueueOfTrianglesToProcess(){
    this->q = new std::queue<Triangle*>();
    this->tsvp = value;
}

void Queue::addTrianglesToProcessToQueue(Mesh* mesh){
    foreach(Triangle* t, mesh->triangles()){
        if( t->getSmallestAngleValue() < this->tsvp){
            this->push(t);
        }
    }
    qDebug("M size: %d", mesh->triangles().size());
    qDebug("Q size: %d", this->q->size());
}

Triangle* Queue::pop(){
    Triangle* t = 0;
    /*while( !this->q->empty() && (t = this->q->front())->getStatus() == Constant::DEAD ){
        this->q->pop();
        delete t;
    }*/
    while(!this->q->empty()){
        t = this->q->front();qDebug("%d status: %d", t->id(), t->getStatus());
        if(t->getStatus() == Constant::DEAD){ qDebug("%d is dead", t->id());
            this->q->pop();
            delete t;
            t = 0;
        } else {
            return t;
        }
    }
    return t;
}

bool Queue::push(Triangle *t){
    qDebug("pushing method :D");
    if(t == 0) qDebug("triangle NULL"); else qDebug("pushing %d", t->id());
    //if(t->getSmallestAngleValue() < this->tsvp){
        //qDebug("pushed %d", t->id());
        t->setStatus(Constant::IN_DEATH_ROW);
        this->q->push(t);
        return true;
    //}
    return false;
}

bool Queue::empty(){
    return this->q->empty();
}

Queue::~Queue(){
    delete q;
}

