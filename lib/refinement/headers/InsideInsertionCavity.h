#ifndef INSIDEINSERTIONCAVITY_H
#define INSIDEINSERTIONCAVITY_H

#include "InsideInsertion.h"

class InsideInsertionCavity: public InsideInsertion
{

public:
    InsideInsertionCavity(Configuration* conf);
    void execute();
    ~InsideInsertionCavity();
};

#endif // INSIDEINSERTIONCAVITY_H
