#include "lib/refinement/triangle_selection/TriangleSelectionSmallestInternalAngle.h"

TriangleSelectionSmallestInternalAngle::TriangleSelectionSmallestInternalAngle(): TriangleSelection(){

}

Triangle* TriangleSelectionSmallestInternalAngle::process(Mesh* mesh, double value){
    Triangle* ret = 0;
    double minAngle = 180.0;
    foreach(Triangle* t, mesh->triangles()){
        if( t->getSmallestAngleValue() < value && t->getSmallestAngleValue() <= minAngle){
            minAngle = t->getSmallestAngleValue();
            ret = t;
        }
    }
    return ret;
}

TriangleSelectionSmallestInternalAngle::~TriangleSelectionSmallestInternalAngle(){

}
