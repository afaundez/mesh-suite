#ifndef INSIDEINSERTION_H
#define INSIDEINSERTION_H

#include <QPoint>
#include "InsertionMethod.h"
#include "Configuration.h"
#include "Triangle.h"

class InsideInsertion: public InsertionMethod{

public:
    InsideInsertion(Configuration* conf);
    virtual void execute();
    ~InsideInsertion() {};
};

#endif // INSIDEINSERTION_H
