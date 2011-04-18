#include "src/lib/refinement/headers/FactoryInsertionMethod.h"
#include "src/lib/refinement/headers/InsideInsertionBasic.h"
#include "src/lib/refinement/headers/InsideInsertionFlipDiagonal.h"
#include "src/lib/refinement/headers/InsideInsertionCavity.h"

InsertionMethod* FactoryInsertionMethod::create(Configuration *c, Options *o){
    InsertionMethod* ret;
    switch(c->includeCase()){
    case Constant::INCLUDED:
    case Constant::BORDER_INCLUDED:
        switch(o->insideInsertion()){
        case Constant::BASIC:
            qDebug("--> Using Basic Insertion");
            ret = new InsideInsertionBasic(c);
            break;
        case Constant::FLIP_DIAGONAL:
            //qDebug("-->Using Recursive Diagonal Flip");
            ret = new InsideInsertionFlipDiagonal(c);
            break;
        case Constant::CAVITY:
            //qDebug("-->Using Cavity");
            ret = new InsideInsertionCavity(c);
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
