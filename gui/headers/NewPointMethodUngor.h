#ifndef NEWPOINTMETHODUNGOR_H
#define NEWPOINTMETHODUNGOR_H

#include "NewPointMethod.h"

class NewPointMethodUngor: public NewPointMethod{
public:
    NewPointMethodUngor(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodUngor();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODUNGOR_H
