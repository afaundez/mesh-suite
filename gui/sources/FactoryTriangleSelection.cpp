#include "headers/FactoryTriangleSelection.h"
#include "headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"
#include "headers/TriangleSelectionSmallestEdge.h"
#include "headers/TriangleSelectionSmallestInternalAngle.h"

TriangleSelection* FactoryTriangleSelection::build(Constant::TriangleSelection type){
    TriangleSelection* ret;
    switch(type){
    case Constant::SMALLEST_INTERNAL_ANGLE:
        ret =  new TriangleSelectionSmallestInternalAngle();
        break;
    case Constant::SMALLEST_EDGE:
        ret = new TriangleSelectionSmallestEdge();
        break;
    case Constant::SMALLEST_EDGE_BORDER_TRIANGLE_FIRST:
        ret =  new TriangleSelectionSmallestEdgeBorderTriangleFirst();
        break;
    default:
        break;
    }
    return ret;
}
