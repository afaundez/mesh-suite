#ifndef NEWPOINTMETHODUNGOR_H
#define NEWPOINTMETHODUNGOR_H

#include "NewPointMethod.h"

class NewPointMethodUngor: public NewPointMethod{
public:
    NewPointMethodUngor(Mesh* m, Triangle* t, double angle);
    Configuration* getConfiguration();
    ~NewPointMethodUngor();
private:
    Mesh* mp;
    Triangle* tp;
    double ap;
};

#endif // NEWPOINTMETHODUNGOR_H
