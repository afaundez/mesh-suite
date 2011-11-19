#include "src/lib/refinement/headers/FactoryInsertionMethod.h"
#include "src/lib/refinement/headers/InsideInsertionBasic.h"
#include "src/lib/refinement/headers/InsideInsertionFlipDiagonal.h"
#include "src/lib/refinement/headers/InsideInsertionCavity.h"

InsertionMethod* FactoryInsertionMethod::create(Configuration *c, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe, Options *o){
    InsertionMethod* ret;
    switch(c->includeCase()){
    case Constant::INCLUDED:
    case Constant::BORDER_INCLUDED:
        switch(o->insideInsertion()){
        case Constant::BASIC:
            qDebug("--> Using Basic Insertion");
            ret = new InsideInsertionBasic(c, qt);
            break;
        case Constant::FLIP_DIAGONAL:
            //qDebug("-->Using Recursive Diagonal Flip");
            ret = new InsideInsertionFlipDiagonal(c, qt, qe);
            break;
        case Constant::CAVITY:
            //qDebug("-->Using Cavity");
            ret = new InsideInsertionCavity(c, qt);
            break;
        }
        break;
    case Constant::CORNER_INCLUDED:
        throw QString("FlipDiagonal Perdida de presicion...");
        break;
    case Constant::NOT_INCLUDED:
        break;
    }
    return ret;
}
