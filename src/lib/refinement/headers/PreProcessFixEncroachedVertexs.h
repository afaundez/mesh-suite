#ifndef PREPROCESSFIXENCROACHEDVERTEXS_H
#define PREPROCESSFIXENCROACHEDVERTEXS_H

#include "PreProcess.h"
#include "src/lib/geometric/headers/Mesh.h"
#include "Options.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"

class PreProcessFixEncroachedVertexs: public PreProcess{
public:
    PreProcessFixEncroachedVertexs(Mesh* m, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe, Options* o);
    void execute();
    ~PreProcessFixEncroachedVertexs();
private:
    Mesh* mp;
    QueueOfTrianglesToProcess* qtp;
    QueueOfEncroachedEdges* qep;
    Options* op;
};

#endif // PREPROCESSFIXENCROACHEDVERTEXS_H
