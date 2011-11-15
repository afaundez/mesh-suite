#ifndef INSIDEINSERTIONCAVITY_H
#define INSIDEINSERTIONCAVITY_H

#include "InsideInsertion.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"

class InsideInsertionCavity: public InsideInsertion
{

public:
    InsideInsertionCavity(Configuration* conf, QueueOfTrianglesToProcess* qt);
    void execute();
    ~InsideInsertionCavity();
};

#endif // INSIDEINSERTIONCAVITY_H
