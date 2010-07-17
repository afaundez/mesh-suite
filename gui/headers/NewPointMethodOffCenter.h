#ifndef NEWPOINTMETHODOFFCENTER_H
#define NEWPOINTMETHODOFFCENTER_H

#include "NewPointMethod.h"

class NewPointMethodOffCenter: public NewPointMethod{
public:
    NewPointMethodOffCenter(Mesh* m, Triangle* t, double a);
    Configuration* getConfiguration();
    ~NewPointMethodOffCenter();
private:
    Mesh* mp;
    Triangle* tp;
    double ap;
};

#endif // NEWPOINTMETHODOFFCENTER_H
