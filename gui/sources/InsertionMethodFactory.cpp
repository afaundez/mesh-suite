#include "headers/InsertionMethodFactory.h"

InsertionMethod* InsertionMethodFactory::build(Constant::InsertionCase type, int index){
    InsertionMethod* ret;
    switch(type){
    case Constant::INSIDE:
        break;
    case Constant::ON_BORDER:
        break;
    case Constant::RESTRICTED:
        break;
    default:
        break;
    }
    return ret;
}
