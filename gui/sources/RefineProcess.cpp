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

    qDebug("--> Refining Process");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && mesh->isVirgin()) ){
        qDebug("----> Pre-processing mesh");
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), mesh, options)->execute();
    }

    if(options->automatic()){
        if( options->repeatLastSelectedTriangle() && mesh->triangles().contains(mesh->lastSelectedTriangleID())){
            qDebug("----> Getting last bad triangle");
            selectedTriangle = mesh->triangle(mesh->lastSelectedTriangleID());
        }
        else {
            qDebug("----> Getting new bad triangle");
            selectedTriangle = FactoryTriangleSelection::build(options->triangleSelection())->process(mesh, options->triangleSelectionValue());
        }
    }
    else{
        qDebug("----> Getting selected triangle");
        selectedTriangle = mesh->getSelectedTriangle();
    }
    mesh->setLastSelectedTriangleID(selectedTriangle == 0 ? -1 : selectedTriangle->id());



    if( selectedTriangle != 0){
        targetTriangle = selectedTriangle;

        qDebug("----> Getting configuration for new point...");
        conf = FactoryNewPointMethod::create(mesh, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());

        if(conf->triangle() != 0){
            qDebug("--> Inserting configuration");
            im = FactoryInsertionMethod::create(conf, options);
            im->execute();
            insertion = true;
        }
        else{
            qWarning("-->\tNew Point Ouside Mesh Domain");
        }

    }

    if(mesh->triangles().contains(mesh->lastSelectedTriangleID()))
        mesh->setSelectedTriangle(mesh->triangle(mesh->lastSelectedTriangleID()));
    else{
        mesh->setLastSelectedTriangleID(-1);
        mesh->setSelectedTriangle(0);
    }
    return insertion;
}
