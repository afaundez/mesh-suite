#ifndef INSIDEINSERTION_H
#define INSIDEINSERTION_H

#include <QPoint>
#include "lib/refinement/insertion/InsertionMethod.h"
#include "lib/refinement/Configuration.h"
#include "lib/geometric/Triangle.h"

class InsideInsertion: public InsertionMethod{
public:
    InsideInsertion(Configuration* conf);
    virtual void execute() = 0;
    ~InsideInsertion();
protected:
    Configuration* confp;
};

#endif // INSIDEINSERTION_H
