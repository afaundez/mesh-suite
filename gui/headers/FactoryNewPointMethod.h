#ifndef FACTORYNEWPOINTMETHOD_H
#define FACTORYNEWPOINTMETHOD_H

#include "Configuration.h"
#include "Mesh.h"

class FactoryNewPointMethod{
public:
    static Configuration* create(Mesh* mesh, Constant::NewPoint npm);
    ~FactoryNewPointMethod();
};

#endif // FACTORYNEWPOINTMETHOD_H
