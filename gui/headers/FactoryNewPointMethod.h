#ifndef FACTORYNEWPOINTMETHOD_H
#define FACTORYNEWPOINTMETHOD_H

#include "Configuration.h"
#include "Mesh.h"

class FactoryNewPointMethod{
public:
    static Configuration* create(Mesh* m, Triangle* t, Constant::NewPoint np, double value);
    static Configuration* create(Mesh *m, Triangle *t, Constant::OutsideNewPoint onp);
    ~FactoryNewPointMethod();
};

#endif // FACTORYNEWPOINTMETHOD_H
