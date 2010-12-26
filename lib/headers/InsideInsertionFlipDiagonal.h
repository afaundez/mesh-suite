#ifndef INSIDEINSERTIONFLIPDIAGONAL_H
#define INSIDEINSERTIONFLIPDIAGONAL_H

#include "InsideInsertion.h"

class InsideInsertionFlipDiagonal: public InsideInsertion
{
public:
    InsideInsertionFlipDiagonal(Configuration* conf);
    void execute();
    void fixDelaunay(QVector<int> tv);
    ~InsideInsertionFlipDiagonal();
};

#endif // INSIDEINSERTIONFLIPDIAGONAL_H
