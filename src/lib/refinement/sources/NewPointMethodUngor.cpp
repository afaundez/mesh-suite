#include "src/lib/refinement/headers/NewPointMethodUngor.h"

NewPointMethodUngor::NewPointMethodUngor(Mesh* m, Triangle* t, double a){
    this->mp = m;
    this->tp = t;
    this->ap = a;
}

Configuration* NewPointMethodUngor::getConfiguration(){
    qDebug("Triangulo a procesar: id %d vertices %d(%f %f) %d(%f %f) %d(%f %f) maslargo %f [%d %d] circuns centro (%f %f) radio %f",
           tp->id(), tp->vertex(0)->id(), tp->vertex(0)->x(), tp->vertex(0)->y()
           , tp->vertex(1)->id(), tp->vertex(1)->x(), tp->vertex(1)->y()
           , tp->vertex(2)->id(), tp->vertex(2)->x(), tp->vertex(2)->y()
           , tp->getLongestEdgeValue(), tp->vertex((tp->getLongestEdge()+1)%3)->id(), tp->vertex((tp->getLongestEdge()+2)%3)->id()
           , tp->circumcenter()->x(), tp->circumcenter()->y(), tp->circumradius());
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
            qDebug("--- Procesando encroached [%d %d] (%f %f) (%f %f)", e->getVertex(0)->id(), e->getVertex(1)->id()
                   , e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(1)->x(), e->getVertex(1)->y());
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
