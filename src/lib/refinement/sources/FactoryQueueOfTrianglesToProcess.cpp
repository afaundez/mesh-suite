#include "src/lib/refinement/headers/FactoryQueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/Queue.h"
#include "src/lib/refinement/headers/PriorityQueue.h"

QueueOfTrianglesToProcess* FactoryQueueOfTrianglesToProcess::build(Constant::TriangleSelection type, Mesh* m, double value)
{
    QueueOfTrianglesToProcess* ret;
    switch(type){
    case Constant::NO_PRIORITY:
        ret = new Queue(m, value);
        break;
    default:
        ret = new PriorityQueue(m, type, value);
    /*case Constant::SMALLEST_INTERNAL_ANGLE:
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
        break;*/
    }
    return ret;
}
