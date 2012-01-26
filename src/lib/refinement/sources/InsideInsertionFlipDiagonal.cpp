#include "src/lib/refinement/headers/InsideInsertionFlipDiagonal.h"

InsideInsertionFlipDiagonal::InsideInsertionFlipDiagonal(Configuration* conf, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe): InsideInsertion(conf, qt, qe){

}

void InsideInsertionFlipDiagonal::fixDelaunay(QVector<int> ids){
    Triangle *T, *t0, *t1, *l1, *l2, *t2, *A, *B;
    Vertex *v0, *v1, *v2, *b0;
    RestrictedEdge *eA, *eB;
    int i0, i1, i2, j0, j1, j2;
    QVector<int> tv;

    foreach(int id, ids){
        if(this->confp->mesh()->triangles().contains(id)){
            T = this->confp->mesh()->triangle(id);

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

                        /* Begin: update restricted edges */

                        // update T restricted edges to point the new created triangles
                        if(T->isRestricted(i1)){
                            eB = this->confp->mesh()->restriction(T->getRestricted(i1));
                            B->setRestricted(B->getIndex(b0), eB->id());
                            eB->setAdjacentTriangle(eB->whichSide(T),B);//eB->setAdjacentTriangle(0,B);
                            if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                                this->qep->push(eB);
                            }
                        }

                        if(T->isRestricted(i2)){
                            eA = this->confp->mesh()->restriction(T->getRestricted(i2));
                            A->setRestricted(A->getIndex(b0), eA->id());
                            eA->setAdjacentTriangle(eA->whichSide(T),A);//eA->setAdjacentTriangle(0,A);
                            if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                                this->qep->push(eA);
                            }
                        }

                        if(t0->isRestricted(j1)){
                            eA = this->confp->mesh()->restriction(t0->getRestricted(j1));
                            A->setRestricted(A->getIndex(v0), eA->id());
                            eA->setAdjacentTriangle(eA->whichSide(t0),A);//eA->setAdjacentTriangle(0,A);
                            if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                                this->qep->push(eA);
                            }
                        }

                        if(t0->isRestricted(j2)){
                            eB = this->confp->mesh()->restriction(t0->getRestricted(j2));
                            B->setRestricted(B->getIndex(v0), eB->id());
                            eB->setAdjacentTriangle(eB->whichSide(t0),B);//eB->setAdjacentTriangle(0,B);
                            if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                                this->qep->push(eB);
                            }
                        }
                        /* End: update restricted edges */


                        this->confp->mesh()->removeAndDeleteTriangle(T);
                        this->confp->mesh()->removeAndDeleteTriangle(t0);

                        tv.append(A->id()); if(A->isAnnoying(this->confp->mesh()->value())) this->qtp->push(A);
                        tv.append(B->id()); if(B->isAnnoying(this->confp->mesh()->value())) this->qtp->push(B);

                        break;
                    }
                }
            }
        }
    }
    if(!tv.isEmpty()){
        this->fixDelaunay(tv);}
}

void InsideInsertionFlipDiagonal::execute(){

    Triangle *T, *t0, *t1, *t2, *A, *B, *C, *D;
    Vertex *v0, *v1, *v2;
    RestrictedEdge *eA, *eB, *eC, *eD;
    int i0, i1, i2, j0, j1, j2;

    QVector<int> tv;
    QHash<int, QVector<int> >  tre;
    QVector<int> rev;

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

        /* Begin: update restricted edges. */

        // update T restricted edges to point the new created triangles
        if(T->isRestricted(T->getIndex(v0))){
            eB = this->confp->mesh()->restriction(T->getRestricted(T->getIndex(v0)));
            B->setRestricted(B->getIndex(P), eB->id());
            eB->setAdjacentTriangle(eB->whichSide(T),B);//eB->setAdjacentTriangle(0,B);
            if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                this->qep->push(eB);
            }
        }

        if(T->isRestricted(T->getIndex(v1))){
            eC = this->confp->mesh()->restriction(T->getRestricted(T->getIndex(v1)));
            C->setRestricted(C->getIndex(P), eC->id());
            eC->setAdjacentTriangle(eC->whichSide(T),C);//eC->setAdjacentTriangle(0,C);
            if(eC->isEncroached() && eC->getStatus() == Constant::ALIVE){
                this->qep->push(eC);
            }
        }

        if(T->isRestricted(T->getIndex(v2))){
            eA = this->confp->mesh()->restriction(T->getRestricted(T->getIndex(v2)));
            A->setRestricted(A->getIndex(P), eA->id());
            eA->setAdjacentTriangle(eA->whichSide(T),A);// eA->setAdjacentTriangle(0,A);
            if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                this->qep->push(eA);
            }
        }
        /* End: update restricted edges */

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

        if(t0 == 0){ /* Caso insercion en arista de borde */
            A->setNeighbours(0, B, t2);
            B->setNeighbours(0, t1, A);

            if(t1 != 0)
                t1->replaceNeighbour(T, B);
            if(t2 != 0)
                t2->replaceNeighbour(T, A);

            /* Begin: update restricted edges. */

            // split T restricted edge where point has been inserted
            eA = this->confp->mesh()->createAndAddRestriction(v1,P);
            eB = this->confp->mesh()->createAndAddRestriction(P,v2);

            A->setRestricted(A->getIndex(v0), eA->id());
            B->setRestricted(B->getIndex(v0), eB->id());

            eA->setAdjacentTriangle(0,A);
            eB->setAdjacentTriangle(0,B);

            if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                this->qep->push(eA);
            }
            if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                this->qep->push(eB);
            }

            // update T restricted edges to point the new created triangles
            if(T->isRestricted(i1)){
                eB = this->confp->mesh()->restriction(T->getRestricted(i1));
                B->setRestricted(B->getIndex(P), eB->id());
                eB->setAdjacentTriangle(eB->whichSide(T),B);//eB->setAdjacentTriangle(0,B);
                if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                    this->qep->push(eB);
                }
            }

            if(T->isRestricted(i2)){
                eA = this->confp->mesh()->restriction(T->getRestricted(i2));
                A->setRestricted(A->getIndex(P), eA->id());
                eA->setAdjacentTriangle(eA->whichSide(T),A);//eA->setAdjacentTriangle(0,A);
                if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                    this->qep->push(eA);
                }
            }
            /* End: update restricted edges */

            this->confp->mesh()->removeAndDeleteRestriction(T->getRestricted(i0));
            this->confp->mesh()->removeAndDeleteTriangle(T);

            if( A != 0) tv.append(A->id());
            if( B != 0) tv.append(B->id());
        }
        else{ /* Caso insercion en arista restringida */
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

            /* Begin: update restricted edges. */
            if(T->isRestricted(i0)){
                // split T restricted edge where point has been inserted
                eA = this->confp->mesh()->createAndAddRestriction(v1,P);
                eB = this->confp->mesh()->createAndAddRestriction(P,v2);

                A->setRestricted(A->getIndex(v0), eA->id());
                B->setRestricted(B->getIndex(v0), eB->id());
                C->setRestricted(C->getIndex(b0), eB->id());
                D->setRestricted(D->getIndex(b0), eA->id());

                eA->setAdjacentTriangle(0,A); eA->setAdjacentTriangle(1,D);
                eB->setAdjacentTriangle(0,B); eB->setAdjacentTriangle(1,C);

                if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                    this->qep->push(eA);
                }
                if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                    this->qep->push(eB);
                }
            }

            // update T restricted edges to point the new created triangles
            if(T->isRestricted(i1)){
                eB = this->confp->mesh()->restriction(T->getRestricted(i1));
                B->setRestricted(B->getIndex(P), eB->id());
                eB->setAdjacentTriangle(eB->whichSide(T),B);//eB->setAdjacentTriangle(0,B);
                if(eB->isEncroached() && eB->getStatus() == Constant::ALIVE){
                    this->qep->push(eB);
                }
            }

            if(T->isRestricted(i2)){
                eA = this->confp->mesh()->restriction(T->getRestricted(i2));
                A->setRestricted(A->getIndex(P), eA->id());
                eA->setAdjacentTriangle(eA->whichSide(T),A);//eA->setAdjacentTriangle(0,A);
                if(eA->isEncroached() && eA->getStatus() == Constant::ALIVE){
                    this->qep->push(eA);
                }
            }

            // update t0 restricted edges to point the new created triangles
            if(t0->isRestricted(j1)){
                eD = this->confp->mesh()->restriction(t0->getRestricted(j1));
                D->setRestricted(D->getIndex(P), eD->id());
                eD->setAdjacentTriangle(eD->whichSide(t0),D);//eD->setAdjacentTriangle(0,D);
                if(eD->isEncroached() && eD->getStatus() == Constant::ALIVE){
                    this->qep->push(eD);
                }
            }


            if(t0->isRestricted(j2)){
                eC = this->confp->mesh()->restriction(t0->getRestricted(j2));
                C->setRestricted(C->getIndex(P), eC->id());
                eC->setAdjacentTriangle(eC->whichSide(t0),C);//eC->setAdjacentTriangle(0,C);
                if(eC->isEncroached() && eC->getStatus() == Constant::ALIVE){
                    this->qep->push(eC);
                }
            }
            /* End: update restricted edges */
            this->confp->mesh()->removeAndDeleteRestriction(T->getRestricted(i0));
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
