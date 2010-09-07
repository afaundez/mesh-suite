#include "headers/RefineProcess.h"
#include "headers/FactoryPreProcess.h"
#include "headers/FactoryTriangleSelection.h"
#include "headers/Configuration.h"
#include "headers/FactoryNewPointMethod.h"
#include "headers/InsertionMethod.h"
#include "headers/FactoryInsertionMethod.h"


bool RefineProcess::refine(Mesh *mesh, Options *options){
    Triangle* targetTriangle;
    Configuration* conf;
    InsertionMethod* im;


    qDebug("-->\tPre-processing mesh...");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && mesh->isVirgin()) )
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), mesh, options)->execute();

    qDebug("-->\tSelecting triangle");
    if(options->manual()){
        qDebug("-->\tGetting triangle manually...");
        targetTriangle = mesh->getSelectedTriangle();
    }
    else{
        qDebug("-->\tGetting triangle automatically...");
        targetTriangle = FactoryTriangleSelection::build(options->triangleSelection())->process(mesh, options->triangleSelectionValue());
    }

    qDebug("-->\tProcessing...");
    if( targetTriangle != 0){
        qDebug("-->\tGetting configuration for new point...");
        conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());

        if(conf->triangle() == 0){ //OUTSIDE
            qDebug("-->\tNew Point is outside the mesh. Forcing outside configuration for new point...");
            conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->outsideNewPointMethod());
        }

        qDebug("-->\tCreating inserting method...");
        im = FactoryInsertionMethod::create(conf, options);

        qDebug("-->\tExecuting inserting method...");
        im->execute();
        return true;
    }
    qDebug("-->\tNo more triangle to process");
    return false;
}
