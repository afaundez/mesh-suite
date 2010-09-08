#include "headers/RefineProcess.h"
#include "headers/FactoryPreProcess.h"
#include "headers/FactoryTriangleSelection.h"
#include "headers/Configuration.h"
#include "headers/FactoryNewPointMethod.h"
#include "headers/InsertionMethod.h"
#include "headers/FactoryInsertionMethod.h"


bool RefineProcess::refine(Mesh *mesh, Options *options){
    Triangle* targetTriangle;
    Triangle* selectedTriangle;
    Configuration* conf;
    InsertionMethod* im;
    bool insertion = false;


    qDebug("-->\tPre-processing mesh...");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && mesh->isVirgin()) )
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), mesh, options)->execute();


    qDebug("-->\tGetting triangle");
    if(options->repeatLastSelectedTriangle() && mesh->triangles().contains(mesh->lastSelectedTriangleID())){
        selectedTriangle = mesh->triangle(mesh->lastSelectedTriangleID());
    }
    else{
        selectedTriangle = mesh->getSelectedTriangle();
        if(selectedTriangle == 0)
            selectedTriangle = FactoryTriangleSelection::build(options->triangleSelection())->process(mesh, options->triangleSelectionValue());
    }
    mesh->setLastSelectedTriangleID(selectedTriangle == 0 ? -1 : selectedTriangle->id());

    qDebug("-->\tProcessing...");
    if( selectedTriangle != 0){

        /*if(options->useLepp()){
            qDebug("-->\tUsing Lepp");
            targetTriangle = selectedTriangle->lepp().last();
        }
        else{*/
            targetTriangle = selectedTriangle;
        //}

        qDebug("-->\tGetting configuration for new point...");
        conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());

        if(conf->triangle() != 0){
            qDebug("-->\tCreating inserting method...");
            im = FactoryInsertionMethod::create(conf, options);

            qDebug("-->\tExecuting inserting method...");
            im->execute();
            insertion = true;
        }
        qDebug("-->\tNew Point Ouside Mesh Domain");

    }

    if(mesh->triangles().contains(mesh->lastSelectedTriangleID()))
        mesh->setSelectedTriangle(mesh->triangle(mesh->lastSelectedTriangleID()));
    else{
        mesh->setLastSelectedTriangleID(-1);
        mesh->setSelectedTriangle(0);
    }
    return insertion;
}
