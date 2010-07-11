#include "headers/Configuration.h"

Configuration::Configuration(Triangle *t, QVector<Point *>p, QVector<int>e){
    this->tp = t;
    this->pp = p;
    this->ep = e;
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

Configuration::~Configuration(){

}
