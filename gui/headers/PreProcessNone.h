#ifndef PREPROCESSNONE_H
#define PREPROCESSNONE_H

#include "PreProcess.h"

class PreProcessNone: public PreProcess{
public:
    PreProcessNone();
    void execute();
    ~PreProcessNone();
};

#endif // PREPROCESSNONE_H
