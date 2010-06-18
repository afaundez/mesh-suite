#include "headers/InsertionTypeFactory.h"
#include "headers/FlipDiagonalInsertionType.h"
#include "headers/CavityInsertionType.h"

InsertionType* InsertionTypeFactory::build(int index){
    InsertionType* ret;
    switch(index){
    case 0:
        ret = new FlipDiagonalInsertionType();
        break;
    case 1:
    default:
        ret = new FlipDiagonalInsertionType();
        break;
    }
    return ret;
}
