#ifndef PREPROCESSFIXENCROACHEDVERTEXS_H
#define PREPROCESSFIXENCROACHEDVERTEXS_H

#include "PreProcess.h"
#include "Mesh.h"
#include "Options.h"

class PreProcessFixEncroachedVertexs: public PreProcess{
public:
    PreProcessFixEncroachedVertexs(Mesh* m, Options* o);
    void execute();
    ~PreProcessFixEncroachedVertexs();
private:
    Mesh* mp;
    Options* op;
};

#endif // PREPROCESSFIXENCROACHEDVERTEXS_H
