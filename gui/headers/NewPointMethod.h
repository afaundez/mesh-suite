#ifndef NEWPOINTMETHOD_H
#define NEWPOINTMETHOD_H

#include "Configuration.h"

class NewPointMethod{
public:
    virtual Configuration* getConfiguration();
    ~NewPointMethod() {};
};

#endif // NEWPOINTMETHOD_H
