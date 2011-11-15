#include <QtGlobal>
#include "src/lib/refinement/headers/FactoryPreProcess.h"
#include "src/lib/refinement/headers/PreProcessNone.h"
#include "src/lib/refinement/headers/PreProcessFixEncroachedVertexs.h"

PreProcess* FactoryPreProcess::build(Constant::PreProcess type, Mesh* mesh, QueueOfTrianglesToProcess* qt, Options* options){
    PreProcess* ret;
    switch(type){
    case Constant::NO_PREPROCESS:
        ret = new PreProcessNone();
        break;
    case Constant::FIX_ENCROACHED_VERTEXS:
        ret =  new PreProcessFixEncroachedVertexs(mesh, qt, options);
        break;
    }
    return ret;
}
