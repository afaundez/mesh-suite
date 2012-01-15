#include "src/lib/refinement/headers/NewPointMethodLeppMidpoint.h"
#include "src/lib/refinement/headers/Util.h"

NewPointMethodLeppMidpoint::NewPointMethodLeppMidpoint(Mesh *m, Triangle *t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodLeppMidpoint::getConfiguration(){
    Configuration* ret;
    int i;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Triangle *t, *t1, *t2;

    t = this->tp;

    QVector<Triangle*> lepp = t->lepp();
    t1 = lepp.last();
    t2 = t1->neighbour(t1->getLongestEdge());

    if(t1->isConstrained(t1->getLongestEdge()) ||
            (!t1->isConstrained(t1->getSecondLongestEdge()) && !t2->isConstrained(t2->getSecondLongestEdge()))){
        i = t1->getLongestEdge();
        p = Util::midpoint(t1->vertex((i+1)%3), t1->vertex((i+2)%3));
        ps.insert(0, p);
        es.insert(0, i);
        ret = new Configuration(this->mp, t1, ps, es, Constant::BORDER_INCLUDED);
    } else {
        if(t1->isConstrained(t1->getSecondLongestEdge())){
            i = t1->getSecondLongestEdge();
            p = Util::midpoint(t1->vertex((i+1)%3), t1->vertex((i+2)%3));
            ps.insert(0, p);
            es.insert(0, i);
            ret = new Configuration(this->mp, t1, ps, es, Constant::BORDER_INCLUDED);
        } else if(t2->isConstrained(t2->getSecondLongestEdge())){
            i = t2->getSecondLongestEdge();
            p = Util::midpoint(t2->vertex((i+1)%3), t2->vertex((i+2)%3));
            ps.insert(0, p);
            es.insert(0, i);
            ret = new Configuration(this->mp, t2, ps, es, Constant::BORDER_INCLUDED);
        } //else {qDebug("otra opcion no considerada");}
    }

    return ret;
}

NewPointMethodLeppMidpoint::~NewPointMethodLeppMidpoint(){

}
