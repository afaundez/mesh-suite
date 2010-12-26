#include "lib/headers/Configuration.h"

Configuration::Configuration(Mesh* m, Triangle *t, QVector<Point *>p, QVector<int>e, Constant::IncludeCase ic){
    this->mp = m;
    this->tp = t;
    this->pp = p;
    this->ep = e;
    this->icp = ic;
}

QVector<Point*> Configuration::points(){
    return this->pp;
}

QVector<int> Configuration::edges(){
    return this->ep;
}

Triangle* Configuration::triangle(){
    return this->tp;
}

Mesh* Configuration::mesh(){
    return this->mp;
}

Constant::IncludeCase Configuration::includeCase(){
    return this->icp;
}

Configuration::~Configuration(){

}
