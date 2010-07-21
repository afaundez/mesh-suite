#include "headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"

TriangleSelectionSmallestEdgeBorderTriangleFirst::TriangleSelectionSmallestEdgeBorderTriangleFirst(): TriangleSelection(){

}

Triangle* TriangleSelectionSmallestEdgeBorderTriangleFirst::process(Mesh* mesh, double value){
    Triangle* ret = 0;
    foreach(Triangle* t, mesh->triangles()){
        if( t->getSmallestAngleValue() < value && ret == 0){;
            ret = t;
        }
        else if( t->getSmallestAngleValue() < value) {
            if(ret->isConstrained(ret->getSmallestEdge())){
                if(t->isConstrained(t->getSmallestEdge()))
                    if(t->getSmallestEdgeValue() < ret->getSmallestEdgeValue())
                        ret = t;
            }
            else{
                if(t->isConstrained(ret->getSmallestEdge())){
                    ret = t;
                }
                else{
                    if(t->getSmallestAngleValue() < ret->getSmallestAngleValue())
                        ret = t;
                }
            }
        }
    }
    return ret;
}

TriangleSelectionSmallestEdgeBorderTriangleFirst::~TriangleSelectionSmallestEdgeBorderTriangleFirst(){

}

