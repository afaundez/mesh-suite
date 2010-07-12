#include "headers/FactoryInsertionMethod.h"
#include "headers/InsideInsertionBasic.h"

InsertionMethod* FactoryInsertionMethod::create(Configuration *c, Options *o){
    InsertionMethod* ret;
    switch(c->includeCase()){
    case Constant::INCLUDED:
    case Constant::CORNER_INCLUDED:
    case Constant::BORDER_INCLUDED:
        switch(c->triangle()->getRestrictedType()){
        case 0:
            switch(o->insideInsertion()){
            case Constant::BASIC:
                ret = new InsideInsertionBasic(c);
            default:
                ret = new InsideInsertionBasic(c);
                break;
            }
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }

        break;
    case Constant::NOT_INCLUDED:
        break;
    default:
        break;
    }
    return ret;
}
