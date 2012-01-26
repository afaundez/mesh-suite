#include "src/lib/refinement/headers/NewPointMethodUngor.h"

NewPointMethodUngor::NewPointMethodUngor(Mesh* m, Triangle* t, double a){
    this->mp = m;
    this->tp = t;
    this->ap = a;
}

Configuration* NewPointMethodUngor::getConfiguration(){
    Configuration* ret;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Constant::IncludeCase ic;
    Triangle* t;

    p = this->tp->offCenter(this->ap);
    /* *************************************************************
       Si p produce una arista encroached en algun lugar de la malla
       entonces se inserta el punto medio de dicha arista
    ************************************************************* */

    /* TODO: Considerar que el punto podria generar varias aristas encroached */

    foreach(RestrictedEdge* e, this->mp->restrictions()){
        if(e->diametralCircleInclude(p) == Constant::INCLUDED){
            ps.append(e->midpoint());
            foreach(Triangle* ta, e->getAdjacentTriangles()){

                if( ta != 0){
                    es.append(ta->getIndexOfEdge(e->id()));
                    t = ta;
                    ret = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);
                    return ret;
                }
            }
        }
    }

    t = this->mp->getTriangle(this->tp, p);

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

NewPointMethodUngor::~NewPointMethodUngor(){

}
