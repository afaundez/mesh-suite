#include "lib/refinement/insertion/FactoryInsertionMethod.h"
#include "lib/refinement/insertion/InsideInsertionBasic.h"
#include "lib/refinement/insertion/InsideInsertionFlipDiagonal.h"
#include "lib/refinement/insertion/InsideInsertionCavity.h"

InsertionMethod* FactoryInsertionMethod::create(Configuration *c, Options *o){
    InsertionMethod* ret;
    switch(c->includeCase()){
    case Constant::INCLUDED:
    case Constant::BORDER_INCLUDED:
        switch(o->insideInsertion()){
        case Constant::FLIP_DIAGONAL:
            //qDebug("-->Using Recursive Diagonal Flip");
            ret = new InsideInsertionFlipDiagonal(c);
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
