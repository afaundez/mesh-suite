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


    // PRE PROCESS
    qDebug("-->\tPre-processing mesh...");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && mesh->isVirgin()) )
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), mesh, options)->execute();

    // SELECT TRIANGLE
    qDebug("-->\tSelecting triangle");
    if(options->manual()){
        qDebug("-->\tGetting triangle manually...");
        targetTriangle = mesh->getSelectedTriangle();
    }
    else{
        qDebug("-->\tGetting triangle automatically...");
        targetTriangle = FactoryTriangleSelection::build(options->triangleSelection())->process(mesh, options->triangleSelectionValue());
    }

    // PROCESS
    qDebug("-->\tProcessing...");
    if( targetTriangle != 0){
        // NEW POINT METHOD
        qDebug("-->\tGetting configuration for new point...");
        conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());

        // CHECK INSERTION WHETER INSIDE OR OUTSIDE INSERTION
        if(conf->triangle() == 0){ //OUTSIDE
            // FORCE NEW CONFIGURATION
            qDebug("-->\tNew Point is outside the mesh. Forcing outside configuration for new point...");
            conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->outsideNewPointMethod());
        }

        // TODO: DOUBLE CHECK NEW POINT INCLUDE. ASSUMING THA NEW POINT IS INSIDE THE MESH... FOR NOW

        // GET INSERTION METHOD
        qDebug("-->\tCreating inserting method...");
        im = FactoryInsertionMethod::create(conf, options);

        // EXECUTE
        qDebug("-->\tExecuting inserting method...");
        im->execute();
        return true;
    }
    qDebug("-->\tNo more triangle to process");
    return false;
}
