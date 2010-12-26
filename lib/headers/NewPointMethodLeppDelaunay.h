#ifndef NEWPOINTMETHODLEPPDELAUNAY_H
#define NEWPOINTMETHODLEPPDELAUNAY_H

#include "NewPointMethod.h"

class NewPointMethodLeppDelaunay: public NewPointMethod{
public:
    NewPointMethodLeppDelaunay(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodLeppDelaunay();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODLEPPDELAUNAY_H
