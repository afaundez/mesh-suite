#ifndef INSIDEINSERTIONFLIPDIAGONAL_H
#define INSIDEINSERTIONFLIPDIAGONAL_H

#include "InsideInsertion.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"

class InsideInsertionFlipDiagonal: public InsideInsertion
{
public:
    InsideInsertionFlipDiagonal(Configuration* conf, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe);
    void execute();
    void fixDelaunay(QVector<int> tv);
    ~InsideInsertionFlipDiagonal();
};

#endif // INSIDEINSERTIONFLIPDIAGONAL_H
