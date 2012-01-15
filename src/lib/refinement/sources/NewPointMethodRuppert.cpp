#include "src/lib/refinement/headers/NewPointMethodRuppert.h"

NewPointMethodRuppert::NewPointMethodRuppert(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodRuppert::getConfiguration(){
    Configuration* ret;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Constant::IncludeCase ic;
    Triangle* t;

    p = this->tp->circumcenter();
    /* *************************************************************
       Si p produce una arista encroached en algun lugar de la malla
       entonces se inserta el punto medio de dicha arista
    ************************************************************* */

    /*foreach(Triangle* T, this->mp->triangles()){
        for(int  i  = 0; i < 3; i++){
            if(!T->hasNeighbour(i) && T->edgeInclude(i, p)){
                ps.append(T->midpoint(i));
                es.append(i);
                t = T;
                ret = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);
                return ret;
            }
        }
    }*/

    foreach(RestrictedEdge* e, this->mp->restrictions()){
        if(e->diametralCircleInclude(p) == Constant::INCLUDED){
            ps.append(e->midpoint());
            foreach(Triangle* ta, e->getAdjacentTriangles()){
                //Corregir para considerar aristas restringidas que NO esten en el borde
                if( ta != 0){
                    es.append(ta->getIndex(e->id()));
                    t = ta;
                    ret = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);
                    return ret;
                }
            }
        }
    }


    //t = this->mp->getTriangle(p);
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

NewPointMethodRuppert::~NewPointMethodRuppert(){

}
