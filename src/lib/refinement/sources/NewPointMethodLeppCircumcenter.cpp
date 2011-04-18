#include "src/lib/refinement/headers/NewPointMethodLeppCircumcenter.h"

NewPointMethodLeppCircumcenter::NewPointMethodLeppCircumcenter(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodLeppCircumcenter::getConfiguration(){
    Configuration* ret;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Constant::IncludeCase ic;
    Triangle* t;
    t = this->tp->lepp().last();
    if(t->neighbour(t->getLongestEdge()) != 0)
        t = t->neighbour(t->getLongestEdge());

    p = t->circumcenter();
    foreach(Triangle* T, this->mp->triangles()){
        for(int  i  = 0; i < 3; i++){
            if(!T->hasNeighbour(i) && T->edgeInclude(i, p)){
                ps.append(T->midpoint(i));
                es.append(i);
                t = T;
                ret = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);
                return ret;
            }
        }
    }

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

NewPointMethodLeppCircumcenter::~NewPointMethodLeppCircumcenter(){

}

