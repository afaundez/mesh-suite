#include "headers/FactoryInsertionMethod.h"
#include "headers/InsideInsertionBasic.h"
#include "headers/InsideInsertionFlipDiagonal.h"

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
            qDebug("-->Using Recursive Diagonal Flip");
            ret = new InsideInsertionFlipDiagonal(c);
            break;
        case Constant::CAVITY:
            qDebug("-->Using Cavity");
            ret = new InsideInsertionFlipDiagonal(c);
            break;
        }
        break;
    case Constant::CORNER_INCLUDED:
        qCritical("FactoryInsertionMethid::create() CORNER_INCLUDED case, it should not happen.");
        break;
    case Constant::NOT_INCLUDED:
        break;
    }
    return ret;
}
