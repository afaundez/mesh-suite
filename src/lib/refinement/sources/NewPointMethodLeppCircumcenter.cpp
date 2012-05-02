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
    QVector<Triangle*> lepp = this->tp->lepp();
    int n=0; qDebug("**LEPP**");
    foreach(Triangle *T, lepp){
        qDebug("Triangulo %d: id %d vertices %d(%f %f) %d(%f %f) %d(%f %f) maslargo %f [%d %d]",
              n, T->id(), T->vertex(0)->id(), T->vertex(0)->x(), T->vertex(0)->y()
               , T->vertex(1)->id(), T->vertex(1)->x(), T->vertex(1)->y()
               , T->vertex(2)->id(), T->vertex(2)->x(), T->vertex(2)->y()
               , T->getLongestEdgeValue(), T->vertex((T->getLongestEdge()+1)%3)->id(), T->vertex((T->getLongestEdge()+2)%3)->id()
               );
        n++;
    }
    t = this->tp->lepp().last();
    if(t->neighbour(t->getLongestEdge()) != 0)
        t = t->neighbour(t->getLongestEdge());

    p = t->circumcenter();
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

    t = this->mp->getTriangle(t, p);
    ps.insert(0, p);
    if(t == 0){
        ic = Constant::NOT_INCLUDED;
        es.insert(0, -1);
    }
    else{
        ic = (t->include(p));
        es.insert(0, t->wichBorder(p));
    }
    ret = new Configuration(this->mp, t, ps, es, ic);  qDebug("Lepp: punto a insertar (%f %f)", p->x(), p->y());

    return ret;
}

NewPointMethodLeppCircumcenter::~NewPointMethodLeppCircumcenter(){

}

