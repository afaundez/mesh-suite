#ifndef NEWPOINTMETHODLEPPCIRCUMCENTER_H
#define NEWPOINTMETHODLEPPCIRCUMCENTER_H

#include "NewPointMethod.h"

class NewPointMethodLeppCircumcenter: public NewPointMethod{
public:
    NewPointMethodLeppCircumcenter(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodLeppCircumcenter();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODLEPPCIRCUMCENTER_H
