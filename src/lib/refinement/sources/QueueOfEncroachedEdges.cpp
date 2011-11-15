#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"

QueueOfEncroachedEdges::QueueOfEncroachedEdges(Mesh* mesh){
    this->q = new std::queue<Edge*>();
    this->addEdgesToProcessToQueue(mesh);
}

void QueueOfEncroachedEdges::addEdgesToProcessToQueue(Mesh* mesh){
    foreach(Edge* e, mesh->restrictions()){
        if(e->isEncroached()){
            this->push(e);
        }
    }
}

Edge* QueueOfEncroachedEdges::getNextEdgeToProcess(){
    Edge* edge = 0;

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

void QueueOfEncroachedEdges::push(Edge* e){

        e->setStatus(Constant::IN_DEATH_ROW);
        this->q->push(e);

    //return false;
}

bool QueueOfEncroachedEdges::empty(){
    return this->q->empty();
}

QueueOfEncroachedEdges::~QueueOfEncroachedEdges(){
    delete this->q;
}
