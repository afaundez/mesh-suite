#include "lib/refinement/headers/TriangleSelectionLongEdgeOnlyBorder.h"

TriangleSelectionLongEdgeOnlyBorder::TriangleSelectionLongEdgeOnlyBorder(): TriangleSelection(){

}

Triangle* TriangleSelectionLongEdgeOnlyBorder::process(Mesh* mesh, double value){
    Triangle* ret = 0;
    foreach(Triangle* t, mesh->triangles()){
        if( (t->isConstrained(0) || t->isConstrained(1) || t->isConstrained(2) ) && value < t->getLongestEdgeValue()){
            return ret;
        }
    }
    return ret;
}

TriangleSelectionLongEdgeOnlyBorder::~TriangleSelectionLongEdgeOnlyBorder(){

}

