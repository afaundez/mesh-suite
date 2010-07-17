#ifndef NEWPOINTMETHODMIDPOINTENCROACHEDBORDER_H
#define NEWPOINTMETHODMIDPOINTENCROACHEDBORDER_H

#include "NewPointMethod.h"

class NewPointMethodMidpointEncroachedBorder: public NewPointMethod{
public:
    NewPointMethodMidpointEncroachedBorder(Mesh* m, Triangle* t);
    Configuration* getConfiguration(Point* p);
    ~NewPointMethodMidpointEncroachedBorder();
private:
    Mesh* mp;
    Triangle* tp;
};

#endif // NEWPOINTMETHODMIDPOINTENCROACHEDBORDER_H
