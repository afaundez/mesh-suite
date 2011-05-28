#ifndef INSERTIONMETHOD_H
#define INSERTIONMETHOD_H

#include "lib/geometric/Mesh.h"
#include "lib/geometric/Triangle.h"

class InsertionMethod{
public:
    virtual void execute() = 0;
    virtual ~InsertionMethod() {};
};

#endif // INSERTIONMETHOD_H
