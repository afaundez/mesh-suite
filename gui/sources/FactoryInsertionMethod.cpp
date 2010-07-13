#include "headers/FactoryInsertionMethod.h"
#include "headers/InsideInsertionBasic.h"
#include "headers/InsideInsertionFlipDiagonal.h"

InsertionMethod* FactoryInsertionMethod::create(Configuration *c, Options *o){
    InsertionMethod* ret;
    switch(c->includeCase()){
    case Constant::INCLUDED:
    case Constant::CORNER_INCLUDED:
    case Constant::BORDER_INCLUDED:
        switch(c->triangle()->getRestrictedType()){
        case Constant::NOT_RESTRICTED:
            qDebug("-->\tNo Restricted Case");
            switch(o->insideInsertion()){
            case Constant::BASIC:
                qDebug("-->\tSelection InsideInsertionBasic");
                ret = new InsideInsertionBasic(c);
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
        case Constant::ONE_RESTRICTED:
            qDebug("-->\tOne Restricted Case");
            // TODO IMPLEMENT THIS CASE
            break;
        case Constant::TWO_RESTRICTED:
            qDebug("-->\tTwo Restricted Case");
            // TODO IMPLEMENT THIS CASE
            break;
        case Constant::THREE_RESTRICTED:
            qDebug("-->\tThree Restricted Case");
            // TODO IMPLEMENT THIS CASE
            break;
        }

        break;
    case Constant::NOT_INCLUDED:
        break;
    }
    return ret;
}
