#include "lib/refinement/headers/NewPointMethodLeppBisection.h"
#include "lib/refinement/headers/Util.h"


NewPointMethodLeppBisection::NewPointMethodLeppBisection(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodLeppBisection::getConfiguration(){
    Configuration* ret;
    int i;
    Vertex* a;
    Vertex* b;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Triangle *t, *t1, *t2;

    QVector<Triangle*> lepp = this->tp->lepp();
    t1 = lepp.last();
    t2 = t1->neighbour(t1->getLongestEdge());

    if( t1->isConstrained(t1->getLongestEdge()) || (!t1->isConstrained(t1->getSecondLongestEdge()) && t2 != 0 && !t2->isConstrained(t2->getSecondLongestEdge())) ){
        i = t1->getLongestEdge();
        a = t1->vertex((i+1)%3);
        b = t1->vertex((i+2)%3);
        t = t1;
    }
    else{
        if( t1->isConstrained(t1->getSecondLongestEdge()) ){
            i = t1->getSecondLongestEdge();
            a = t1->vertex((i+1)%3);
            b = t1->vertex((i+2)%3);
            t = t1;
        }
        else if(t2 != 0 && t2->isConstrained(t2->getSecondLongestEdge())){
            i = t2->getSecondLongestEdge();
            a = t2->vertex((i+1)%3);
            b = t2->vertex((i+2)%3);
            t = t2;
        }
        else
            throw QString("aaaaaaaaaa");
    }

    p = Util::midpoint(a, b);
    ps.insert(0, p);
    es.insert(0, i);

    ret = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);

    return ret;
}

NewPointMethodLeppBisection::~NewPointMethodLeppBisection(){

}

