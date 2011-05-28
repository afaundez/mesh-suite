#ifndef NEWPOINTMETHODBISECTION_H
#define NEWPOINTMETHODBISECTION_H

#include "NewPointMethod.h"

class NewPointMethodBisection: public NewPointMethod{
public:
    NewPointMethodBisection(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodBisection();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODBISECTION_H
