#include <QtGlobal>
#include "lib/headers/FactoryPreProcess.h"
#include "lib/headers/PreProcessNone.h"
#include "lib/headers/PreProcessFixEncroachedVertexs.h"

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
