#ifndef NEWPOINTMETHOD_H
#define NEWPOINTMETHOD_H

#include "Configuration.h"
#include "Mesh.h"

class NewPointMethod{
public:
    virtual Configuration* getConfiguration() = 0;
    virtual ~NewPointMethod() {};
};

#endif // NEWPOINTMETHOD_H
