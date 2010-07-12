#include "headers/NewPointMethodCircumcenter.h"

NewPointMethodCircumcenter::NewPointMethodCircumcenter(Mesh* m, Triangle* t){
    this->mp = m;
    this->tp = t;
}

Configuration* NewPointMethodCircumcenter::getConfiguration(){
    Configuration* ret;
    Vertex* v0;
    Vertex* v1;
    Vertex* v2;
    Point* p;
    QVector<Point*> ps;
    QVector<int>    es;
    double ax, ay, bx, by, cx, cy, d, x, y;
    Constant::IncludeCase ic;
    Triangle* t;

    v0 = this->tp->getVertex(0);
    v1 = this->tp->getVertex(1);
    v2 = this->tp->getVertex(2);

    ax = v0->x();
    ay = v0->y();
    bx = v1->x();
    by = v1->y();
    cx = v2->x();
    cy = v2->y();
    d = 2.0*(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
    x = ((ay*ay+ax*ax)*(by-cy) + (by*by+bx*bx)*(cy-ay) + (cy*cy+cx*cx)*(ay-by))/d;
    y = ((ay*ay+ax*ax)*(cx-bx) + (by*by+bx*bx)*(ax-cx) + (cy*cy+cx*cx)*(bx-ax))/d;

    p = new Point(x,y);
    qDebug("%f %f", x, y);
    ps.insert(0, p);

    t = this->mp->getTriangle(p);
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

NewPointMethodCircumcenter::~NewPointMethodCircumcenter(){

}
