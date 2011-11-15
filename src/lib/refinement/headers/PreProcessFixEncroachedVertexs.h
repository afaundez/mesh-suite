#ifndef PREPROCESSFIXENCROACHEDVERTEXS_H
#define PREPROCESSFIXENCROACHEDVERTEXS_H

#include "PreProcess.h"
#include "src/lib/geometric/headers/Mesh.h"
#include "Options.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"

class PreProcessFixEncroachedVertexs: public PreProcess{
public:
    PreProcessFixEncroachedVertexs(Mesh* m, QueueOfTrianglesToProcess* qt, Options* o);
    void execute();
    ~PreProcessFixEncroachedVertexs();
private:
    Mesh* mp;
    QueueOfTrianglesToProcess* qtp;
    Options* op;
};

#endif // PREPROCESSFIXENCROACHEDVERTEXS_H
