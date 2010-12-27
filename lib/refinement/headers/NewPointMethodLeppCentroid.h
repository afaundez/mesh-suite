#ifndef NEWPOINTMETHODLEPPCENTROID_H
#define NEWPOINTMETHODLEPPCENTROID_H

#include "NewPointMethod.h"

class NewPointMethodLeppCentroid: public NewPointMethod{
public:
    NewPointMethodLeppCentroid(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodLeppCentroid();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODLEPPCENTROID_H
