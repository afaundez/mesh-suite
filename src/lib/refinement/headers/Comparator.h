#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "src/lib/refinement/headers/Constant.h"
#include "src/lib/geometric/headers/Triangle.h"
#include "src/lib/geometric/headers/Mesh.h"

class Comparator{

private:
    Constant::TriangleSelection selectionType;
    Mesh* mp;

public:
    Comparator(Constant::TriangleSelection type, Mesh* mesh);
    bool operator()(Triangle *t1, Triangle *t2);
    ~Comparator();


};

#endif // COMPARATOR_H
