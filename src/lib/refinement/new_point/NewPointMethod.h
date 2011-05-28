#ifndef NEWPOINTMETHOD_H
#define NEWPOINTMETHOD_H

#include "lib/refinement/Configuration.h"
#include "lib/geometric/Mesh.h"

class NewPointMethod{
public:
    virtual Configuration* getConfiguration() = 0;
    virtual ~NewPointMethod() {};
};

#endif // NEWPOINTMETHOD_H
