#include "headers/RefineProcess.h"
#include "headers/FactoryPreProcess.h"
#include "headers/FactoryTriangleSelection.h"
#include "headers/Configuration.h"
#include "headers/FactoryNewPointMethod.h"
#include "headers/InsertionMethod.h"
#include "headers/FactoryInsertionMethod.h"


void RefineProcess::refine(Mesh *mesh, Options *options){
    qDebug("RefineProcess::refine(mesh, options)");
    Triangle* targetTriangle;
    Configuration* conf;
    InsertionMethod* im;

    // INFO
    qDebug("Before Refining. Vertexs:%d Triangles:%d", mesh->vertexsSize(), mesh->trianglesSize());

    // SELECT TRIANGLE
    qDebug("Selecting triangle...");
    if(options->manual()){
        qDebug("hola");
        targetTriangle = mesh->getSelectedTriangle();
        qDebug("chao");
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
        conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->newPointMethod());

        // CHECK INSERTION WHETER INSIDE OR OUTSIDE INSERTION
        if(conf->triangle() == 0){ //OUTSIDE
            // FORCE NEW CONFIGURATION
            qDebug("New Point is outside the mesh. Forcing outside configuration for new point...");
            conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->outsideNewPointMethod());
        }

        // TODO: DOUBLE CHECK NEW POINT INCLUDE. ASSUMING THA NEW POINT IS INSIDE THE MESH... FOR NOW

        // GET INSERTION METHOD
        qDebug("Creating inserting method...");
        im = FactoryInsertionMethod::create(conf, options);

        // EXECUTE
        qDebug("Executing inserting method...");
        im->execute();
    }

    // INFO
    qDebug("After Refining. Vertexs:%d Triangles:%d", mesh->vertexsSize(), mesh->trianglesSize());
}
