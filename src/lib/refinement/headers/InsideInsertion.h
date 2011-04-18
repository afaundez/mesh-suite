#ifndef INSIDEINSERTION_H
#define INSIDEINSERTION_H

#include <QPoint>
#include "InsertionMethod.h"
#include "Configuration.h"
#include "src/lib/geometric/headers/Triangle.h"

class InsideInsertion: public InsertionMethod{
public:
    InsideInsertion(Configuration* conf);
    virtual void execute() = 0;
    ~InsideInsertion();
protected:
    Configuration* confp;
};

#endif // INSIDEINSERTION_H
