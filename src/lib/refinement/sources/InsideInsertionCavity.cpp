
#include "src/lib/refinement/headers/InsideInsertionCavity.h"
#include "src/lib/refinement/headers/Util.h"

InsideInsertionCavity::InsideInsertionCavity(Configuration* conf, QueueOfTrianglesToProcess* qt): InsideInsertion(conf, qt, 0){

}

void InsideInsertionCavity::execute(){
    Triangle* T = this->confp->triangle();
    Point* p = this->confp->points().at(0);

    Vertex* P = this->confp->mesh()->createAndAddVertex(p->x(), p->y());

    Triangle *n0, *n1, *n2, *nn;
    QHash<int, Triangle*> oldTriangles;
    QHash<int, Triangle*> newTriangles;

    if(T->circumcircleInclude(P) == Constant::INCLUDED)
        qDebug("T no pasa el test con P %d", T->circumcircleInclude(P));
    else
        qCritical("T si pasa el test con P %d", T->circumcircleInclude(P));


    foreach(Triangle* t, this->confp->mesh()->triangles()){
        switch(t->circumcircleInclude(P)){
        case Constant::INCLUDED:
            oldTriangles.insert(t->id(), t);
            break;
        case Constant::BORDER_INCLUDED:
        case Constant::NOT_INCLUDED:
            break;
        case Constant::CORNER_INCLUDED:
            throw QString("Cavity Perdida de presicion... CORNER INCLUDED");
            break;
        default:
            break;
        }
    }

    foreach(Triangle* taux, oldTriangles){
        for(int i = 0; i < 3; i++){
            Triangle* naux = taux->neighbour(i);
            if(naux == 0){
                nn = this->confp->mesh()->createAndAddTriangle(taux->vertex((i+1)%3), taux->vertex((i+2)%3), P);
                newTriangles.insert(nn->id(), nn);
            }
            else{
                if(naux->circumcircleInclude(P) != Constant::INCLUDED){
                    nn = this->confp->mesh()->createAndAddTriangle(taux->vertex((i+1)%3), taux->vertex((i+2)%3), P);
                    qCritical("BEFORE %f,%f %f,%f %f,%f", taux->vertex((i+1)%3)->x(), taux->vertex((i+1)%3)->y(), taux->vertex((i+2)%3)->x(), taux->vertex((i+2)%3)->y(), P->x(), P->y());
                    if(Util::orientation(taux->vertex((i+1)%3), taux->vertex((i+2)%3), P) <= 0 ){
                        qCritical("WRONG %f,%f %f,%f %f,%f", taux->vertex((i+1)%3)->x(), taux->vertex((i+1)%3)->y(), taux->vertex((i+2)%3)->x(), taux->vertex((i+2)%3)->y(), P->x(), P->y());
                        return;
                    }
                    newTriangles.insert(nn->id(), nn);
                    naux->setNeighbour((naux->getIndex(taux->vertex((i+1)%3))+1)%3, nn);
                    nn->setNeighbour(2, naux);
                }
            }
        }
    }

    foreach(Triangle* taux, oldTriangles)
        this->confp->mesh()->removeAndDeleteTriangle(taux);


    foreach(Triangle* t1, newTriangles){
        foreach(Triangle* t2, newTriangles){
            int pos = t1->isNeighbour(t2);
            if( 0 <= pos ){
                t1->setNeighbour(pos, t2);
            }
        }
    }
    this->confp->mesh()->setSelectedTriangle(0);
}


InsideInsertionCavity::~InsideInsertionCavity(){

}
