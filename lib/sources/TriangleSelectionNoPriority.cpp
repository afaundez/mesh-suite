#include "lib/headers/TriangleSelectionNoPriority.h"

TriangleSelectionNoPriority::TriangleSelectionNoPriority(): TriangleSelection(){

}

Triangle* TriangleSelectionNoPriority::process(Mesh* mesh, double value){
    Triangle* ret = 0;
    double minCircumradius = -1.0;
    foreach(Triangle* t, mesh->triangles())
        if( t->getSmallestAngleValue() < value)
            return t;
    return ret;
}

TriangleSelectionNoPriority::~TriangleSelectionNoPriority(){

}

