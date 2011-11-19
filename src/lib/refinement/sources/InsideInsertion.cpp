#include "src/lib/refinement/headers/InsideInsertion.h"

InsideInsertion::InsideInsertion(Configuration *conf, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe){
    this->confp = conf;
    this->qtp = qt;
    this->qep = qe;
}

InsideInsertion::~InsideInsertion(){

}
