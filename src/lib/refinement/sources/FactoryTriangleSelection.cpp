#include "src/lib/refinement/headers/FactoryTriangleSelection.h"
#include "src/lib/refinement/headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"
#include "src/lib/refinement/headers/TriangleSelectionSmallestEdge.h"
#include "src/lib/refinement/headers/TriangleSelectionSmallestInternalAngle.h"
#include "src/lib/refinement/headers/TriangleSelectionSmallestCircumradius.h"
#include "src/lib/refinement/headers/TriangleSelectionLongEdgeOnlyBorder.h"
#include "src/lib/refinement/headers/TriangleSelectionNoPriority.h"

TriangleSelection* FactoryTriangleSelection::build(Constant::TriangleSelection type, Mesh* mesh, double value){
    TriangleSelection* ret;
    switch(type){
    case Constant::NO_PRIORITY:
        ret = new TriangleSelectionNoPriority(mesh, value);
        break;
    case Constant::SMALLEST_INTERNAL_ANGLE:
        //qDebug("-->\tGetting triangle with smallest internal angle");
        ret =  new TriangleSelectionSmallestInternalAngle(mesh, value);
        break;
    case Constant::SMALLEST_EDGE:
        //qDebug("-->\tGetting triangle with smallest edge");
        ret = new TriangleSelectionSmallestEdge(mesh, value);
        break;
    case Constant::SMALLEST_ANGLE_CONSTRAINED_EDGE_FIRST:
        //qDebug("-->\tGetting triangle with smallest angle, preference for border triangles");
        ret =  new TriangleSelectionSmallestEdgeBorderTriangleFirst(mesh, value);
        break;
    case Constant::SMALLEST_CIRCUMCIRCLE:
        //qDebug("-->\tGetting triangle with smallest circumcenter");
        ret =  new TriangleSelectionSmallestCircumradius(mesh, value);
        break;
    /*case Constant::LONG_EDGE_ONLY_BORDER:
        ret = new TriangleSelectionLongEdgeOnlyBorder(mesh, value);
        break;*/
    }
    return ret;
}
