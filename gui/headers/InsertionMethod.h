#ifndef INSERTIONMETHOD_H
#define INSERTIONMETHOD_H

#include "Mesh.h"
#include "Triangle.h"

class InsertionMethod{
public:
    virtual void execute() = 0;
    virtual ~InsertionMethod() {};
};

#endif // INSERTIONMETHOD_H
