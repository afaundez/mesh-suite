
#include "headers/NewPointMethodLeppCentroid.h"
#include "headers/Util.h"

NewPointMethodLeppCentroid::NewPointMethodLeppCentroid(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodLeppCentroid::getConfiguration(){
    Configuration* ret;
    int i, j;
    Vertex* a;
    Vertex* b;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Triangle *t1, *t2, *t;
    Constant::IncludeCase ic;

    QVector<Triangle*> lepp = this->tp->lepp();
    t1 = lepp.last();
    t2 = t1->neighbour(t1->getLongestEdge());

    if(t1->isConstrained(t1->getLongestEdge())){
        i = t1->getLongestEdge();
        a = t1->vertex((i+1)%3);
        b = t1->vertex((i+2)%3);
        t = t1;
        p = Util::midpoint(a, b);
        ic = Constant::BORDER_INCLUDED;
    }
    else if( (!t1->isConstrained(t1->getSecondLongestEdge()) && !t2->isConstrained(t2->getSecondLongestEdge())) ){
        i = t1->getLongestEdge();
        j = t2->getLongestEdge();
        p = Util::centroid(t1->vertex(i), t1->vertex((i+1)%3), t2->vertex(j), t1->vertex((i+2)%3));
        if(t1->include(p) == Constant::INCLUDED || t1->include(p) == Constant::BORDER_INCLUDED){
            t = t1;
            ic = t1->include(p);
        }
        else if(t2->include(p) == Constant::INCLUDED || t2->include(p) == Constant::BORDER_INCLUDED){
            t = t2;
            ic = t2->include(p);
        }
        else{
            throw QString("Se ha perdido presicion en la obtencion de configuracion");
        }
    }
    else{
        if( t1->isConstrained(t1->getSecondLongestEdge())){
            qDebug("1");
            i = t1->getLongestEdge();
            j = t2->getLongestEdge();
            p = Util::centroid(t1->vertex(i), t1->vertex((i+1)%3), t2->vertex(j), t1->vertex((i+2)%3));
            if(t1->include(p) == Constant::NOT_INCLUDED){
                qDebug("2");
                i   = t1->getSecondLongestEdge();
                a   = t1->vertex((i+1)%3);
                b   = t1->vertex((i+2)%3);
                t   = t1;
                p   = Util::midpoint(a, b);
                ic  = Constant::BORDER_INCLUDED;
            }
            else{
                t   = t1;
                ic  = t1->include(p);
                i   = t1->wichBorder(p);
            }
        }
        else if(t2->isConstrained(t2->getSecondLongestEdge())){
            i = t1->getLongestEdge();
            j = t2->getLongestEdge();
            p = Util::centroid(t1->vertex(i), t1->vertex((i+1)%3), t2->vertex(j), t1->vertex((i+2)%3));

            if(t2->include(p) == Constant::NOT_INCLUDED){
                i   = t2->getSecondLongestEdge();
                a   = t2->vertex((i+1)%3);
                b   = t2->vertex((i+2)%3);
                t   = t2;
                p   = Util::midpoint(a, b);
                ic  = Constant::BORDER_INCLUDED;
            }
            else{
                t   = t2;
                ic  = t2->include(p);
                i   = t2->wichBorder(p);
            }
        }
    }

    ps.insert(0, p);
    es.insert(0, i);
    ret = new Configuration(this->mp, t, ps, es, ic);

    return ret;
}

NewPointMethodLeppCentroid::~NewPointMethodLeppCentroid(){

}

