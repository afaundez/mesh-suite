#include "src/lib/refinement/headers/RefineProcess.h"
#include "src/lib/refinement/headers/FactoryPreProcess.h"
#include "src/lib/refinement/headers/FactoryTriangleSelection.h"
#include "src/lib/refinement/headers/Configuration.h"
#include "src/lib/refinement/headers/FactoryNewPointMethod.h"
#include "src/lib/refinement/headers/InsertionMethod.h"
#include "src/lib/refinement/headers/FactoryInsertionMethod.h"


RefineProcess RefineProcess::_instance;

RefineProcess::RefineProcess(){
    this->meshp = 0;
}

RefineProcess &RefineProcess::getInstance()
{
  return _instance;
}

void RefineProcess::loadMesh(QString filePath){ this->lts = -1; this->ts = 0;
    if(this->meshp != 0)
        delete meshp;
    this->currentLoadedMesh = filePath;
    this->meshp = new Mesh(filePath);
}

void RefineProcess::reloadMesh(){ this->lts = -1; this->ts = 0;
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


    qDebug("--> Refining Process");
    if( !options->onlyFirstPreProcess()|| (options->onlyFirstPreProcess() && this->meshp->isVirgin()) ){
        qDebug("----> Pre-processing mesh");
        FactoryPreProcess::build((Constant::PreProcess)(options->preProcess()), this->meshp, options)->execute();
    }
    qDebug("End of Pre Process");if(this->meshp != 0) qDebug("mesh"); else qDebug("null D:");
    if(this->meshp->isVirgin()){ qDebug("virgin");
        this->lts = -1;
        this->meshp->setVirgin(false);
    }
    qDebug("before selection");
    if(options->automatic()){
        if( options->repeatLastSelectedTriangle() && this->meshp->triangles().contains(this->meshp->lastSelectedTriangleID())){
            qDebug("----> Getting last bad triangle");
            selectedTriangle = this->meshp->triangle(this->meshp->lastSelectedTriangleID());
        }
        else {
            qDebug("----> Getting new bad triangle");
            //if(this->lts != options->triangleSelection()){ qDebug("last T selection: %d", this->lts); qDebug("opt selection %d", options->triangleSelection());
                this->ts = FactoryTriangleSelection::build(options->triangleSelection(), this->meshp, options->triangleSelectionValue());
            //}
            selectedTriangle = this->ts->process(this->meshp); if(selectedTriangle == 0) qDebug("selectedT == NULL");
            this->lts = options->triangleSelection(); qDebug("this->lts: %d", this->lts);
        }
    }
    else{
        qDebug("----> Getting selected triangle");
        selectedTriangle = this->meshp->getSelectedTriangle();
    }
    this->meshp->setLastSelectedTriangleID(selectedTriangle == 0 ? -1 : selectedTriangle->id());
    qDebug("selected triangle: %d", selectedTriangle == 0 ? 0 : selectedTriangle->id());
    if( selectedTriangle != 0){
        targetTriangle = selectedTriangle;

        qDebug("----> Getting configuration for new point...");
        conf = FactoryNewPointMethod::create(this->meshp, targetTriangle, options->newPointMethod(), options->triangleSelectionValue());
        qDebug("WTF");
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

    if(this->meshp->triangles().contains(this->meshp->lastSelectedTriangleID()))
        this->meshp->setSelectedTriangle(this->meshp->triangle(this->meshp->lastSelectedTriangleID()));
    else{
        this->meshp->setLastSelectedTriangleID(-1);
        this->meshp->setSelectedTriangle(0);
    }
    return insertion;
}
