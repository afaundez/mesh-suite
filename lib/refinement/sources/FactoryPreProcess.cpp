#include <QtGlobal>
#include "lib/refinement/headers/FactoryPreProcess.h"
#include "lib/refinement/headers/PreProcessNone.h"
#include "lib/refinement/headers/PreProcessFixEncroachedVertexs.h"

PreProcess* FactoryPreProcess::build(Constant::PreProcess type, Mesh* mesh, Options* options){
    PreProcess* ret;
    switch(type){
    case Constant::NO_PREPROCESS:
        ret = new PreProcessNone();
        break;
    case Constant::FIX_ENCROACHED_VERTEXS:
        ret =  new PreProcessFixEncroachedVertexs(mesh, options);
        break;
    }
    return ret;
}
