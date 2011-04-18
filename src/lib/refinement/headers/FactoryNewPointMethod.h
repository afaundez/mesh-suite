#ifndef FACTORYNEWPOINTMETHOD_H
#define FACTORYNEWPOINTMETHOD_H

#include "Configuration.h"
#include "src/lib/geometric/headers/Mesh.h"

class FactoryNewPointMethod{
public:
    static Configuration* create(Mesh* m, Triangle* t, Constant::NewPoint np, double value);
    ~FactoryNewPointMethod();
};

#endif // FACTORYNEWPOINTMETHOD_H
