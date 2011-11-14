
#include "src/lib/refinement/headers/TriangleSelectionSmallestCircumradius.h"

TriangleSelectionSmallestCircumradius::TriangleSelectionSmallestCircumradius(Mesh* mesh, double value): TriangleSelection(){

}

Triangle* TriangleSelectionSmallestCircumradius::process(Mesh* mesh){
    /*Triangle* ret = 0;
    double minCircumradius = -1.0;
    foreach(Triangle* t, mesh->triangles()){
        if( t->getSmallestAngleValue() < value && minCircumradius == -1.0){
            minCircumradius = t->circumradius();
            ret = t;
        }
        else if( t->getSmallestAngleValue() < value && t->circumradius() <= minCircumradius){
            minCircumradius = t->circumradius();
            ret = t;
        }
    }
    return ret;
    */
}

TriangleSelectionSmallestCircumradius::~TriangleSelectionSmallestCircumradius(){

}
