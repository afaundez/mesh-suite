#include "headers/FactoryTriangleSelection.h"
#include "headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"
#include "headers/TriangleSelectionSmallestEdge.h"
#include "headers/TriangleSelectionSmallestInternalAngle.h"
#include "headers/TriangleSelectionSmallestCircumradius.h"
#include "headers/TriangleSelectionLongEdgeOnlyBorder.h"
#include "headers/TriangleSelectionNoPriority.h"

TriangleSelection* FactoryTriangleSelection::build(Constant::TriangleSelection type){
    TriangleSelection* ret;
    switch(type){
    case Constant::NO_PRIORITY:
        ret = new TriangleSelectionNoPriority();
        break;
    case Constant::SMALLEST_INTERNAL_ANGLE:
        //qDebug("-->\tGetting triangle with smallest internal angle");
        ret =  new TriangleSelectionSmallestInternalAngle();
        break;
    case Constant::SMALLEST_EDGE:
        //qDebug("-->\tGetting triangle with smallest edge");
        ret = new TriangleSelectionSmallestEdge();
        break;
    case Constant::SMALLEST_ANGLE_CONSTRAINED_EDGE_FIRST:
        //qDebug("-->\tGetting triangle with smallest angle, preference for border triangles");
        ret =  new TriangleSelectionSmallestEdgeBorderTriangleFirst();
        break;
    case Constant::SMALLEST_CIRCUMCIRCLE:
        //qDebug("-->\tGetting triangle with smallest circumcenter");
        ret =  new TriangleSelectionSmallestCircumradius();
        break;
    case Constant::LONG_EDGE_ONLY_BORDER:
        ret = new TriangleSelectionLongEdgeOnlyBorder();
        break;
    }
    return ret;
}
