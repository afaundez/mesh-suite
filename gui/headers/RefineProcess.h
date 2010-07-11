#ifndef REFINEPROCESS_H
#define REFINEPROCESS_H

#include "Mesh.h"
#include "Options.h"

class RefineProcess{
public:
    static void refine(Mesh* mesh, Options* options);
};

#endif // REFINEPROCESS_H
