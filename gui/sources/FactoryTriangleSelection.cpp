#include "headers/FactoryTriangleSelection.h"
#include "headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"
#include "headers/TriangleSelectionSmallestEdge.h"
#include "headers/TriangleSelectionSmallestInternalAngle.h"

TriangleSelection* FactoryTriangleSelection::build(Constant::TriangleSelection type){
    TriangleSelection* ret;
    switch(type){
    case Constant::SMALLEST_INTERNAL_ANGLE:
        qDebug("-->\tGetting triangle with smallest internal angle");
        ret =  new TriangleSelectionSmallestInternalAngle();
        break;
    case Constant::SMALLEST_EDGE:
        qDebug("-->\tGetting triangle with smallest edge");
        ret = new TriangleSelectionSmallestEdge();
        break;
    case Constant::SMALLEST_EDGE_BORDER_TRIANGLE_FIRST:
        qDebug("-->\tGetting triangle with smallest edge, preference for border triangles");
        ret =  new TriangleSelectionSmallestEdgeBorderTriangleFirst();
        break;
    }
    return ret;
}
