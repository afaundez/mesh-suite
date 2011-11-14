#include "src/lib/refinement/headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h"

TriangleSelectionSmallestEdgeBorderTriangleFirst::TriangleSelectionSmallestEdgeBorderTriangleFirst(Mesh* mesh, double value): TriangleSelection(){

}

Triangle* TriangleSelectionSmallestEdgeBorderTriangleFirst::process(Mesh* mesh){
   /* Triangle* ret = 0;
    foreach(Triangle* t, mesh->triangles()){
        if( t->getSmallestAngleValue() < value ){
            if( t->isConstrained(t->getSmallestEdge()) )
                return t;
            if(ret == 0){
                ret = t;
            }
            else{

                if( t->isConstrained(t->getSmallestEdge()) && ret->isConstrained(ret->getSmallestEdge()) ){
                   if( t->getSmallestEdgeValue() < ret->getSmallestEdgeValue() )
                        ret = t;
                }
                else if (t->isConstrained(t->getSmallestEdge()) && !ret->isConstrained(ret->getSmallestEdge()) ){
                    ret = t;
                }
                else if (!t->isConstrained(t->getSmallestEdge()) && ret->isConstrained(ret->getSmallestEdge()) ){
                    continue;
                }
                else{
                    if( t->getSmallestEdgeValue() < ret->getSmallestEdgeValue() )
                         ret = t;
                }
            }
        }
    }
    return ret; */
}

TriangleSelectionSmallestEdgeBorderTriangleFirst::~TriangleSelectionSmallestEdgeBorderTriangleFirst(){

}

