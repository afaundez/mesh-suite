#include "src/lib/refinement/headers/InsideInsertionFlipDiagonal.h"

InsideInsertionFlipDiagonal::InsideInsertionFlipDiagonal(Configuration* conf, QueueOfTrianglesToProcess* qt): InsideInsertion(conf, qt){

}

void InsideInsertionFlipDiagonal::fixDelaunay(QVector<int> ids){
    Triangle *T, *t0, *t1, *l1, *l2, *t2, *A, *B;
    Vertex *v0, *v1, *v2, *b0;
    int i0, i1, i2, j0, j1, j2;
    QVector<int> tv;
    foreach(int id, ids){
        if(this->confp->mesh()->triangles().contains(id)){
            T = this->confp->mesh()->triangle(id);

            //if(T->isAnnoying(this->confp->mesh()->value())) this->qtp->push(T);
            for(int i = 0; i < 3; i++){
                i0 = i;
                i1 = (i0+1)%3;
                i2 = (i1+1)%3;

                if( !T->isBoundary(i0) && !T->isRestricted(i0) ){
                    t0 = T->getNeighbour(i0);
                    t1 = T->getNeighbour(i1);
                    t2 = T->getNeighbour(i2);

                    v0 = T->getVertex(i0);
                    v1 = T->getVertex(i1);
                    v2 = T->getVertex(i2);

                    j2 = t0->getIndex(v1);
                    j0 = (j2+1)%3;
                    j1 = (j0+1)%3;

                    b0 = t0->getVertex(j0);

                    A = 0;
                    B = 0;

                    if( T->circumcircleInclude(b0) == Constant::INCLUDED){
                        l1 = t0->getNeighbour(j1);
                        l2 = t0->getNeighbour(j2);

                        A = this->confp->mesh()->createAndAddTriangle(v0, v1, b0);
                        B = this->confp->mesh()->createAndAddTriangle(v0, b0, v2);
                        //TODO: inherit restrictions

                        A->setNeighbours(l1, B, t2);
                        B->setNeighbours(l2, t1, A);

                        if(l1 != 0)
                            l1->replaceNeighbour(t0, A);
                        if(t2 != 0)
                            t2->replaceNeighbour(T, A);
                        if(l2 != 0)
                            l2->replaceNeighbour(t0, B);
                        if(t1 != 0)
                            t1->replaceNeighbour(T, B);

                        //qDebug("oldt1: %d oldt2: %d newt1: %d newt2: %d size", T->id(), t0->id(), A->id(), B->id(), this->confp->mesh()->trianglesSize());

                        this->confp->mesh()->removeAndDeleteTriangle(T);
                        this->confp->mesh()->removeAndDeleteTriangle(t0);

                        tv.append(A->id()); if(A->isAnnoying(this->confp->mesh()->value())) this->qtp->push(A);//this->confp->mesh()->queueOfTrianglesToProcess()->push(A);
                        tv.append(B->id()); if(B->isAnnoying(this->confp->mesh()->value())) this->qtp->push(B);//this->confp->mesh()->queueOfTrianglesToProcess()->push(B);

                        break;
                    }
                }
            }
        }
    }
    if(!tv.isEmpty())
        this->fixDelaunay(tv);
}

void InsideInsertionFlipDiagonal::execute(){

    Triangle *T, *t0, *t1, *t2, *A, *B, *C, *D;
    Vertex *v0, *v1, *v2;
    int i0, i1, i2, j0, j1, j2;

    QVector<int> tv;

    T = this->confp->triangle();

    Point* p = this->confp->points().at(0);

    Vertex* P = this->confp->mesh()->createAndAddVertex(p->x(), p->y());

    A = 0;
    B = 0;
    C = 0;
    D = 0;
    switch(this->confp->includeCase()){
    case Constant::INCLUDED:
        t0 = T->getNeighbour(0);
        t1 = T->getNeighbour(1);
        t2 = T->getNeighbour(2);

        v0 = T->getVertex(0);
        v1 = T->getVertex(1);
        v2 = T->getVertex(2);

        A = this->confp->mesh()->createAndAddTriangle(v0, v1, P);
        B = this->confp->mesh()->createAndAddTriangle(P, v1, v2);
        C = this->confp->mesh()->createAndAddTriangle(v0, P, v2);

        A->setNeighbours(B, C, t2);
        B->setNeighbours(t0, C, A);
        C->setNeighbours(B, t1, A);

        if(t0 != 0)
            t0->replaceNeighbour(T, B);
        if(t1 != 0)
            t1->replaceNeighbour(T, C);
        if(t2 != 0)
            t2->replaceNeighbour(T, A);

        this->confp->mesh()->removeAndDeleteTriangle(T);
        if( A != 0) tv.append(A->id());
        if( B != 0) tv.append(B->id());
        if( C != 0) tv.append(C->id());
        break;
    case Constant::BORDER_INCLUDED:
        i0 = this->confp->edges().at(0);
        i1 = (i0+1)%3;
        i2 = (i1+1)%3;

        t0 = T->getNeighbour(i0);
        t1 = T->getNeighbour(i1);
        t2 = T->getNeighbour(i2);

        v0 = T->getVertex(i0);
        v1 = T->getVertex(i1);
        v2 = T->getVertex(i2);

        A = this->confp->mesh()->createAndAddTriangle(v0, v1, P);
        B = this->confp->mesh()->createAndAddTriangle(v0, P, v2);

        if(t0 == 0){
            A->setNeighbours(0, B, t2);
            B->setNeighbours(0, t1, A);

            if(t1 != 0)
                t1->replaceNeighbour(T, B);
            if(t2 != 0)
                t2->replaceNeighbour(T, A);

            this->confp->mesh()->removeAndDeleteTriangle(T);
            if( A != 0) tv.append(A->id());
            if( B != 0) tv.append(B->id());
        }
        else{
            j2 = t0->getIndex(v1);
            j0 = (j2+1)%3;
            j1 = (j0+1)%3;

            Vertex* b0 = t0->getVertex(j0);
            Vertex* b1 = t0->getVertex(j1);
            Vertex* b2 = t0->getVertex(j2);

            Triangle* l1 = t0->getNeighbour(j1);
            Triangle* l2 = t0->getNeighbour(j2);

            C = this->confp->mesh()->createAndAddTriangle(b0, b1, P);
            D = this->confp->mesh()->createAndAddTriangle(b0, P, b2);

            A->setNeighbours(D, B, t2);
            B->setNeighbours(C, t1, A);
            C->setNeighbours(B, D, l2);
            D->setNeighbours(A, l1, C);

            if(t1 != 0)
                t1->replaceNeighbour(T, B);
            if(t2 != 0)
                t2->replaceNeighbour(T, A);
            if(l1 != 0)
                l1->replaceNeighbour(t0, D);
            if(l2 != 0)
                l2->replaceNeighbour(t0, C);

            this->confp->mesh()->removeAndDeleteTriangle(T);
            this->confp->mesh()->removeAndDeleteTriangle(t0);
            if( A != 0) tv.append(A->id());
            if( B != 0) tv.append(B->id());
            if( C != 0) tv.append(C->id());
            if( D != 0) tv.append(D->id());

        }
        break;
    case Constant::NOT_INCLUDED:
        throw QString("FlipDiagonal Perdida de presicion... NOT INCLUDED");
        break;
    case Constant::CORNER_INCLUDED:
        throw QString("FlipDiagonal Perdida de presicion... CORNER INCLUDED");
        break;
    }
    if(!tv.isEmpty()){
        foreach(int id, tv){
            Triangle* triangle = this->confp->mesh()->triangle(id);
            if(triangle->isAnnoying(this->confp->mesh()->value())) this->qtp->push(triangle);
        }

        this->fixDelaunay(tv);
    }
}

InsideInsertionFlipDiagonal::~InsideInsertionFlipDiagonal(){

}
