#include "headers/RefineProcess.h"
#include "headers/FactoryPreProcess.h"
#include "headers/FactoryTriangleSelection.h"
#include "headers/Configuration.h"
#include "headers/FactoryNewPointMethod.h"
#include "headers/InsertionMethod.h"
#include "headers/FactoryInsertionMethod.h"


RefineProcess RefineProcess::_instance;

RefineProcess::RefineProcess(){
    this->meshp = 0;
}

RefineProcess &RefineProcess::getInstance()
{
  return _instance;
}

void RefineProcess::loadMesh(QString filePath){
    if(this->meshp != 0)
        delete meshp;
    this->currentLoadedMesh = filePath;
    this->meshp = new Mesh(filePath);
}

void RefineProcess::reloadMesh(){
    delete this->meshp;
    this->meshp = new Mesh(this->currentLoadedMesh);
}


bool RefineProcess::refine(Options *options){
    Triangle* targetTriangle;
    Triangle* selectedTriangle;
    Configuration* conf;
    InsertionMethod* im;
    bool insertion = false;

//    qDebug("--> Refining Process");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && this->meshp->isVirgin()) ){
//        qDebug("----> Pre-processing mesh");
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), this->meshp, options)->execute();
    }

    if(options->automatic()){
        if( options->repeatLastSelectedTriangle() && this->meshp->triangles().contains(this->meshp->lastSelectedTriangleID())){
//            qDebug("----> Getting last bad triangle");
            selectedTriangle = this->meshp->triangle(this->meshp->lastSelectedTriangleID());
        }
        else {
//            qDebug("----> Getting new bad triangle");
            selectedTriangle = FactoryTriangleSelection::build(options->triangleSelection())->process(this->meshp, options->triangleSelectionValue());
        }
    }
    else{
//        qDebug("----> Getting selected triangle");
        selectedTriangle = this->meshp->getSelectedTriangle();
    }
    this->meshp->setLastSelectedTriangleID(selectedTriangle == 0 ? -1 : selectedTriangle->id());

    if( selectedTriangle != 0){
        targetTriangle = selectedTriangle;

//        qDebug("----> Getting configuration for new point...");
        conf = FactoryNewPointMethod::create(this->meshp, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());

        if(conf->triangle() != 0){
//            qDebug("--> Inserting configuration");
            im = FactoryInsertionMethod::create(conf, options);
            im->execute();
            insertion = true;
        }
        else{
            qWarning("-->\tNew Point Ouside Mesh Domain");
        }

    }

    if(this->meshp->triangles().contains(this->meshp->lastSelectedTriangleID()))
        this->meshp->setSelectedTriangle(this->meshp->triangle(this->meshp->lastSelectedTriangleID()));
    else{
        this->meshp->setLastSelectedTriangleID(-1);
        this->meshp->setSelectedTriangle(0);
    }
    return insertion;
}
