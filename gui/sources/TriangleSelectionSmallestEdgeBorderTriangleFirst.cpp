#include "headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"

TriangleSelectionSmallestEdgeBorderTriangleFirst::TriangleSelectionSmallestEdgeBorderTriangleFirst(): TriangleSelection(){

}

Triangle* TriangleSelectionSmallestEdgeBorderTriangleFirst::process(Mesh* mesh, double value){
    Triangle* ret = 0;
    double minEdge = -1.0;
    foreach(Triangle* t, mesh->triangles()){
        if( t->getSmallestAngleValue() < value && minEdge == -1.0){
            minEdge = t->getSmallestEdgeValue();
            ret = t;
        }
        else if( t->getSmallestAngleValue() < value && t->getSmallestEdgeValue() <= minEdge){
            minEdge = t->getSmallestEdgeValue();
            ret = t;
        }
    }
    return ret;
}

TriangleSelectionSmallestEdgeBorderTriangleFirst::~TriangleSelectionSmallestEdgeBorderTriangleFirst(){

}

