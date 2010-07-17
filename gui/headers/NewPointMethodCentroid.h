#ifndef NEWPOINTMETHODCENTROID_H
#define NEWPOINTMETHODCENTROID_H

#include "NewPointMethod.h"

class NewPointMethodCentroid: public NewPointMethod{
public:
    NewPointMethodCentroid(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodCentroid();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODCENTROID_H
