#ifndef NEWPOINTMETHODLEPPMIDPOINT_H
#define NEWPOINTMETHODLEPPMIDPOINT_H

#include "NewPointMethod.h"

class NewPointMethodLeppMidpoint : public NewPointMethod
{
public:
    NewPointMethodLeppMidpoint(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodLeppMidpoint();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODLEPPMIDPOINT_H
