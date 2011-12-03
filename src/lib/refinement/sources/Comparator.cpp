#include "src/lib/refinement/headers/Comparator.h"

Comparator::Comparator(Constant::TriangleSelection type, Mesh* mesh){
    this->selectionType = type;
    this->mp = mesh;
}

bool Comparator::operator()(Triangle *t1, Triangle *t2){
    switch(this->selectionType){
    case Constant::SMALLEST_EDGE:
        //qDebug("-->\tTriangles ordered by smallest edge");
        return t1->getSmallestEdgeValue() > t2->getSmallestEdgeValue();
    case Constant::SMALLEST_ANGLE_CONSTRAINED_EDGE_FIRST: //implementar
    case Constant::SMALLEST_INTERNAL_ANGLE:
        //qDebug("-->\tTriangles ordered by smallest internal angle");
        return t1->getSmallestAngleValue() > t2->getSmallestAngleValue();
    case Constant::SMALLEST_CIRCUMCIRCLE:
        //qDebug("-->\tTriangles ordered by smallest circumcenter");
        return t1->circumradius() > t2->circumradius();
    /* case Constant::LONG_EDGE_ONLY_BORDER:
        return t1->getLongestEdgeValue() > t2->getLongestEdgeValue(); */
    }
}

Comparator::~Comparator(){
}
