#ifndef NEWPOINTMETHODCIRCUMCENTER_H
#define NEWPOINTMETHODCIRCUMCENTER_H

#include "NewPointMethod.h"

class NewPointMethodCircumcenter: public NewPointMethod{
public:
    NewPointMethodCircumcenter(Mesh* m, Triangle* t);
    Configuration* getConfiguration();
    ~NewPointMethodCircumcenter();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODCIRCUMCENTER_H
