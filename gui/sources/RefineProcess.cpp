#include "headers/RefineProcess.h"
#include "headers/FactoryPreProcess.h"
#include "headers/FactoryTriangleSelection.h"
#include "headers/Configuration.h"
#include "headers/FactoryNewPointMethod.h"
#include "headers/InsertionMethod.h"
#include "headers/FactoryInsertionMethod.h"


void RefineProcess::refine(Mesh *mesh, Options *options){
    Triangle* targetTriangle;
    Configuration* conf;
    InsertionMethod* im;

    // SELECT TRIANGLE
    qDebug("Selecting triangle...");
    if(options->manual()){
        targetTriangle = mesh->getSelectedTriangle();
    }
    else{
        // TODO: implement triangle selection methods
        targetTriangle = FactoryTriangleSelection::build(options->triangleSelection())->process(mesh, options->triangleSelectionValue());
    }

    // PRE PROCESS
    qDebug("Pre-processing mesh...");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && mesh->isVirgin()) )
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()))->execute();

    // PROCESS
    qDebug("Processing...");
    if( targetTriangle != 0){
        // NEW POINT METHOD
        qDebug("Getting configuration for new point...");
        conf = FactoryNewPointMethod::create(mesh, options->newPointMethod());

        // CHECK INSERTION WHETER INSIDE OR OUTSIDE INSERTION
        if(conf->triangle() == 0){ //OUTSIDE
            // FORCE NEW CONFIGURATION
            qDebug("New Point is outside the mesh. Forcing outside configuration for new point...");
            conf = FactoryNewPointMethod::create(mesh, options->outsideNewPointMethod());
        }

        // TODO: DOUBLE CHECK NEW POINT INCLUDE. ASSUMING THA NEW POINT IS INSIDE THE MESH... FOR NOW

        // GET INSERTION METHOD
        im = FactoryInsertionMethod::create(conf, options);

        // EXECUTE
        im->execute();
    }
}
