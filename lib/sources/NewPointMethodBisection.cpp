#include "lib/headers/NewPointMethodBisection.h"
#include "lib/headers/Util.h"


NewPointMethodBisection::NewPointMethodBisection(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodBisection::getConfiguration(){
    Configuration* ret;
    int i;
    Vertex* a;
    Vertex* b;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;

    i = this->tp->getLongestEdge();
    a = this->tp->getVertex((i+1)%3);
    b = this->tp->getVertex((i+2)%3);

    p = Util::midpoint(a, b);
    ps.insert(0, p);
    es.insert(0, i);

    ret = new Configuration(this->mp, this->tp, ps, es, Constant::BORDER_INCLUDED);

    return ret;
}

NewPointMethodBisection::~NewPointMethodBisection(){

}
