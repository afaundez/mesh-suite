#include "headers/NewPointMethodCentroid.h"

NewPointMethodCentroid::NewPointMethodCentroid(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodCentroid::getConfiguration(){
    Configuration* ret;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Constant::IncludeCase ic;
    Triangle *t;

    p = this->tp->centroid();
    t = this->mp->getTriangle(p);
    ps.insert(0, p);
    if(t == 0){
        ic = Constant::NOT_INCLUDED;
        es.insert(0, -1);
    }
    else{
        ic = (t->include(p));
        es.insert(0, t->wichBorder(p));
    }
    ret = new Configuration(this->mp, t, ps, es, ic);

    return ret;
}

NewPointMethodCentroid::~NewPointMethodCentroid(){

}

