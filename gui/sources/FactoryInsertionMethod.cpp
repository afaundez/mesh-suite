#include "headers/FactoryInsertionMethod.h"
#include "headers/InsideInsertionBasic.h"
#include "headers/InsideInsertionFlipDiagonal.h"

InsertionMethod* FactoryInsertionMethod::create(Configuration *c, Options *o){
    InsertionMethod* ret;
    switch(c->includeCase()){
    case Constant::INCLUDED:
    case Constant::BORDER_INCLUDED:
        qDebug("-->\tNo Restricted Case");
        switch(o->insideInsertion()){
        case Constant::BASIC:
            qDebug("-->\tSelection InsideInsertionBasic");
            ret = new InsideInsertionBasic(c);
            break;
        case Constant::FLIP_DIAGONAL:
            qDebug("-->\tSelection InsideInsertionFlipDiagonal");
            ret = new InsideInsertionFlipDiagonal(c);
            break;
        case Constant::CAVITY:
            qDebug("-->\tSelection InsideInsertionCavity. Not Implemented");
            // TODO IMPLEMENT THIS CASE
            break;
        }
        break;
    case Constant::CORNER_INCLUDED:
        qDebug("Weird Case, it should not happen");
        break;
    case Constant::NOT_INCLUDED:
        break;
    }
    return ret;
}