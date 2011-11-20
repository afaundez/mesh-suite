#include "src/lib/refinement/headers/RefineProcess.h"
#include "src/lib/refinement/headers/FactoryPreProcess.h"
#include "src/lib/refinement/headers/FactoryTriangleSelection.h"
#include "src/lib/refinement/headers/Configuration.h"
#include "src/lib/refinement/headers/FactoryNewPointMethod.h"
#include "src/lib/refinement/headers/InsertionMethod.h"
#include "src/lib/refinement/headers/FactoryInsertionMethod.h"
#include "src/lib/refinement/headers/FactoryQueueOfTrianglesToProcess.h"


RefineProcess RefineProcess::_instance;

RefineProcess::RefineProcess(){
    this->meshp = 0;
}

RefineProcess &RefineProcess::getInstance()
{
  return _instance;
}

void RefineProcess::loadMesh(QString filePath){ this->lastTriangleSelection = -1; this->ts = 0;
    if(this->meshp != 0)
        delete meshp;
    this->currentLoadedMesh = filePath;
    this->meshp = new Mesh(filePath);
}

void RefineProcess::reloadMesh(){ this->lastTriangleSelection = -1; this->ts = 0;
    delete this->meshp;
    this->meshp = new Mesh(this->currentLoadedMesh);
}


bool RefineProcess::refine(Options *options){
    Triangle* targetTriangle;
    Triangle* selectedTriangle;
    Configuration* conf;
    InsertionMethod* im;
   // TriangleSelection* ts = this->tsp;
    bool insertion = false;

    /* Obtaining encroached edges */
    if(this->meshp->isVirgin() && options->preProcess() == Constant::FIX_ENCROACHED_VERTEXS ){ /* and lastPreProcess != options.preProcess*/
        this->encroachedEdges = new QueueOfEncroachedEdges(this->meshp);
    }

    /* Obtaining bad triangles */
    if(this->meshp->isVirgin() || this->lastTriangleSelection != options->triangleSelection()){
        this->trianglesToProcess = FactoryQueueOfTrianglesToProcess::build(options->triangleSelection(), this->meshp, options->triangleSelectionValue());
    }
    this->lastTriangleSelection = options->triangleSelection();

    // qDebug("--> Refining Process");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && this->meshp->isVirgin()) ){
        // qDebug("----> Pre-processing mesh");
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), this->meshp, this->trianglesToProcess, this->encroachedEdges, options)->execute();
    }

    if(this->meshp->isVirgin()){
        //this->lastTriangleSelection = -1;
        this->meshp->setVirgin(false);
    }

    if(options->automatic()){
        if( options->repeatLastSelectedTriangle() && this->meshp->triangles().contains(this->meshp->lastSelectedTriangleID())){
            // qDebug("----> Getting last bad triangle");
            selectedTriangle = this->meshp->triangle(this->meshp->lastSelectedTriangleID());
        }
        else {
            // qDebug("----> Getting new bad triangle");
            selectedTriangle = this->trianglesToProcess->getNextTriangleToProcess();
            this->lastTriangleSelection = options->triangleSelection();
        }
    }
    else{
        // qDebug("----> Getting selected triangle");
        selectedTriangle = this->meshp->getSelectedTriangle();
    }
    this->meshp->setLastSelectedTriangleID(selectedTriangle == 0 ? -1 : selectedTriangle->id());

    if( selectedTriangle != 0){
        targetTriangle = selectedTriangle;

        // qDebug("----> Getting configuration for new point...");
        conf = FactoryNewPointMethod::create(this->meshp, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());

        if(conf->triangle() != 0){
            im = FactoryInsertionMethod::create(conf, this->trianglesToProcess, this->encroachedEdges, options);
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
