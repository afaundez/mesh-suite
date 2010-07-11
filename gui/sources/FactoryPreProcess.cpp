#include <QtGlobal>
#include "headers/FactoryPreProcess.h"
#include "headers/PreProcessNone.h"
#include "headers/PreProcessEdgeDiameterCircle.h"

PreProcess* FactoryPreProcess::build(Constant::PreProcess type){
    PreProcess* ret;
    switch(type){
    case Constant::NONE:
        ret = new PreProcessNone();
        break;
    case Constant::EDGE_DIAMETER_CIRCLE:
        ret =  new PreProcessEdgeDiameterCircle();
    default:
        qDebug("PreProcessFactory::build type not recongnized: %d", type);
        break;
    }
    return ret;
}
