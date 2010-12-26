#ifndef INSIDEINSERTIONBASIC_H
#define INSIDEINSERTIONBASIC_H

#include "InsideInsertion.h"

class InsideInsertionBasic: public InsideInsertion
{
public:
    InsideInsertionBasic(Configuration* conf);
    void execute();
    ~InsideInsertionBasic();

};

#endif // INSIDEINSERTIONBASIC_H
