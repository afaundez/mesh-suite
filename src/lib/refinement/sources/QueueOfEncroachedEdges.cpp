#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"

QueueOfEncroachedEdges::QueueOfEncroachedEdges(Mesh* mesh){
    this->q = new std::queue<RestrictedEdge*>();
    this->addEdgesToProcessToQueue(mesh);
}

void QueueOfEncroachedEdges::addEdgesToProcessToQueue(Mesh* mesh){
    foreach(RestrictedEdge* e, mesh->restrictions()){
        if(e->isEncroached()){
            this->push(e);
        }
    }
}

RestrictedEdge* QueueOfEncroachedEdges::getNextEdgeToProcess(){
    //qDebug("cant: %d", this->q->size());
    RestrictedEdge* edge = 0;

    while(!this->q->empty()){
        edge = this->q->front(); this->q->pop();
        if(edge->getStatus() == Constant::DEAD){
            delete edge;
            edge = 0;
        } else {
            return edge;
        }
    }
    return edge;
}

void QueueOfEncroachedEdges::push(RestrictedEdge* e){

        e->setStatus(Constant::IN_DEATH_ROW);
        this->q->push(e);

    //return false;
}

bool QueueOfEncroachedEdges::empty(){
    return this->q->empty();
}

int QueueOfEncroachedEdges::size(){
    return this->q->size();
}

QueueOfEncroachedEdges::~QueueOfEncroachedEdges(){
    delete this->q;
}
