#include "lib/headers/NewPointMethodLeppDelaunay.h"
#include "lib/headers/Util.h"


NewPointMethodLeppDelaunay::NewPointMethodLeppDelaunay(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodLeppDelaunay::getConfiguration(){
    Configuration* ret;
    int i;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    Triangle *t, *tstar, *t1;

    t = this->tp;

    if( t->isBoundary() && !t->isBoundary(t->getSmallestEdge())){
        i = (t->isBoundary(t->getLongestEdge())) ? t->getLongestEdge() : t->getSecondLongestEdge();
        p = Util::midpoint(t->vertex((i+1)%3), t->vertex((i+2)%3));
        ps.insert(0, p);
        es.insert(0, i);
        ret = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);
    }
    else{
        QVector<Triangle*> lepp = t->lepp();
        tstar = 0;
        for(int j = 0; j < lepp.size(); j++){
            if(j == 0){
                continue;
            }
            else{
                Triangle* taux = lepp.at(j);
                if(t->isBoundary() && !t->isBoundary(t->getSmallestEdge())){
                    tstar = taux;
                    break;
                }
            }
        }
        if(tstar != 0){
            i = (tstar->isBoundary(tstar->getLongestEdge())) ? tstar->getLongestEdge() : tstar->getSecondLongestEdge();
            p = Util::midpoint(tstar->vertex((i+1)%3), tstar->vertex((i+2)%3));
            ps.insert(0, p);
            es.insert(0, i);
            ret = new Configuration(this->mp, tstar, ps, es, Constant::BORDER_INCLUDED);
        }
        else{
            t1 = lepp.last();
            i = t1->getLongestEdge();
            p = Util::midpoint(t1->vertex((i+1)%3), t1->vertex((i+2)%3));
            ps.insert(0, p);
            es.insert(0, i);
            ret = new Configuration(this->mp, t1, ps, es, Constant::BORDER_INCLUDED);
        }
    }
    return ret;
}

NewPointMethodLeppDelaunay::~NewPointMethodLeppDelaunay(){

}


