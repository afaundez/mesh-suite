#ifndef INSIDEINSERTIONFLIPDIAGONAL_H
#define INSIDEINSERTIONFLIPDIAGONAL_H

#include "InsideInsertion.h"
#include <QVector>

struct Comb{
    Triangle* T;
    int i;
};

class InsideInsertionFlipDiagonal: public InsideInsertion
{
public:
    InsideInsertionFlipDiagonal(Configuration* conf);
    void execute();
    QVector<Comb> flipDiagonal(Triangle* t, int i);
    void fixDelaunay(Triangle* t, int i);
    ~InsideInsertionFlipDiagonal();
};

#endif // INSIDEINSERTIONFLIPDIAGONAL_H
