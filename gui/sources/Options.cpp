#include "headers/Options.h"

Options::Options(){
}

void Options::setTriangleSelection(int index){
    this->tsp = (Constant::TriangleSelection)index;
}

Constant::TriangleSelection Options::triangleSelection(){
    return this->tsp;
}

void Options::setTriangleSelectionValue(int value){
    this->tsvp = value;
}

int Options::triangleSelectionValue(){
    return this->tsvp;
}

void Options::setNewPointMethod(int value){
    this->npp = (Constant::NewPoint)value;
}

Constant::NewPoint Options::newPointMethod(){
    return this->npp;
}

void Options::setOutsideNewPointMethod(int value){
    this->onpp = (Constant::NewPoint)value;
}

Constant::NewPoint Options::outsideNewPointMethod(){
    return this->onpp;
}

void Options::setManual(bool manual){
    this->mp = manual;
}

bool Options::manual(){
    return this->mp;
}

void Options::setOnlyFirstPreProcess(bool onlyFirst){
    this->ofp = onlyFirst;
}
bool Options::onlyFirstPreProcess(){
    return this->ofp;
}

void Options::setPreProcess(int pp){
    this->ppp = (Constant::PreProcess)pp;
}

Constant::PreProcess Options::preProcess(){
    return this->ppp;
}

Options::~Options(){

}
