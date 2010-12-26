#ifndef NEWPOINTMETHODLEPPBISECTION_H
#define NEWPOINTMETHODLEPPBISECTION_H

#include "NewPointMethod.h"

class NewPointMethodLeppBisection: public NewPointMethod{
public:
    NewPointMethodLeppBisection(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodLeppBisection();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODLEPPBISECTION_H
