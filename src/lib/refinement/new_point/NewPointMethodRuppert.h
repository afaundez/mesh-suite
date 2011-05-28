#ifndef NEWPOINTMETHODRUPPERT_H
#define NEWPOINTMETHODRUPPERT_H

#include "NewPointMethod.h"

class NewPointMethodRuppert: public NewPointMethod{
public:
    NewPointMethodRuppert(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodRuppert();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODRUPPERT_H
