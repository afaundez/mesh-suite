#include "lib/refinement/headers/InsideInsertionBasic.h"

InsideInsertionBasic::InsideInsertionBasic(Configuration* conf): InsideInsertion(conf){

}

void InsideInsertionBasic::execute(){
    Triangle* T = this->confp->triangle();
    Point* p = this->confp->points().at(0);

    Vertex* P = this->confp->mesh()->createAndAddVertex(p->x(), p->y());

    Triangle *t0, *t1, *t2, *A, *B, *C;
    Vertex *v0, *v1, *v2;
    int i0, i1, i2;

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
        }
        else{
            int j2 = t0->getIndex(v1);
            int j0 = (j2+1)%3;
            int j1 = (j0+1)%3;
    
            Vertex* b0 = t0->getVertex(j0);
            Vertex* b1 = t0->getVertex(j1);
            Vertex* b2 = t0->getVertex(j2);
    
            //Triangle* l0 = t0->getNeighbour(j0);
            Triangle* l1 = t0->getNeighbour(j1);
            Triangle* l2 = t0->getNeighbour(j2);
    
            Triangle* C = this->confp->mesh()->createAndAddTriangle(b0, b1, P);
            Triangle* D = this->confp->mesh()->createAndAddTriangle(b0, P, b2);
    
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
        }
        break;
    case Constant::NOT_INCLUDED:
    case Constant::CORNER_INCLUDED:
    default:
        break;
    }
    this->confp->mesh()->setSelectedTriangle(0);
}


InsideInsertionBasic::~InsideInsertionBasic(){

}
