#ifndef INSIDEINSERTIONBASIC_H
#define INSIDEINSERTIONBASIC_H

#include "InsideInsertion.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"

class InsideInsertionBasic: public InsideInsertion
{
public:
    InsideInsertionBasic(Configuration* conf, QueueOfTrianglesToProcess* qt);
    void execute();
    ~InsideInsertionBasic();

};

#endif // INSIDEINSERTIONBASIC_H
