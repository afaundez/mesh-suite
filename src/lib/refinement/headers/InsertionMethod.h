#ifndef INSERTIONMETHOD_H
#define INSERTIONMETHOD_H

#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/geometric/headers/Triangle.h"

class InsertionMethod{
public:
    virtual void execute() = 0;
    virtual ~InsertionMethod() {};
};

#endif // INSERTIONMETHOD_H
