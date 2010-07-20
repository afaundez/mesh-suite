#include "headers/Options.h"

Options::Options(){
}

void Options::setTriangleSelection(int index){
    this->tsp = (Constant::TriangleSelection)index;
}

Constant::TriangleSelection Options::triangleSelection(){
    return this->tsp;
}

void Options::setTriangleSelectionValue(double value){
    this->tsvp = value;
}

double Options::triangleSelectionValue(){
    return this->tsvp;
}

void Options::setNewPointMethod(int value){
    this->npp = (Constant::NewPoint)value;
}

Constant::NewPoint Options::newPointMethod(){
    return this->npp;
}

void Options::setOutsideNewPointMethod(int value){
    this->onpp = (Constant::OutsideNewPoint)value;
}

Constant::OutsideNewPoint Options::outsideNewPointMethod(){
    return this->onpp;
}

void Options::setInsideInsertion(int value){
    this->inpp = (Constant::InsideInsertion)value;
}

Constant::InsideInsertion Options::insideInsertion(){
    return this->inpp;
}

void Options::setOneEdgeRestrictedInsertion(int value){
    this->ornpp = (Constant::OneEdgeRestrictedInsertion)value;
}

Constant::OneEdgeRestrictedInsertion Options::oneEdgeRestrictedInsertion(){
    return this->ornpp;
}

void Options::setTwoEdgeRestrictedInsertion(int value){
    this->trnpp = (Constant::TwoEdgeRestrictedInsertion)value;
}

Constant::TwoEdgeRestrictedInsertion Options::twoEdgeRestrictedInsertion(){
    return this->trnpp;
}

void Options::setThreeEdgeRestrictedInsertion(int value){
    this->ttrnpp = (Constant::ThreeEdgeRestrictedInsertion)value;
}

Constant::ThreeEdgeRestrictedInsertion Options::threeEdgeRestrictedInsertion(){
    return this->ttrnpp;
}

void Options::setManual(bool manual){
    this->mp = manual;
}

bool Options::manual(){
    return this->mp;
}

void Options::setAutomatic(bool automatic){
    this->ap = automatic;
}

bool Options::automatic(){
    return this->ap;
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

void Options::setParameter(double p){
    this->pp = p;
}

double Options::parameter(){
    return this->parameter();
}

void Options::setLepp(bool active){
    this->lp = active;
}

bool Options::lepp(){
    return this->lp;
}

void Options::setEncroached(bool active){
    this->ep = active;
}

bool Options::encroached(){
    return this->ep;
}

bool Options::encroached();

Options::~Options(){

}
