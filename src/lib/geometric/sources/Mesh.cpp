#include <QString>
#include <QStringList>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QHashIterator>
#include <QDebug>
#include <GL/gl.h>
#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/refinement/headers/Util.h"

//! [0]
Mesh::Mesh(QString fileName){
    cv = 0;
    ct = 0;
    cr = 0;
    QFile inputFile(fileName);
    if( !inputFile.open(QIODevice::ReadOnly)){
        return;
    }

    QTextStream in(&inputFile);
    while ( !in.atEnd() ) {
        QString line = in.readLine();
        QStringList splitLine;
        if( line.isNull() || line.trimmed().isEmpty())
            continue;
        else if( line.toLower().startsWith('v') ){
            splitLine = line.split(' ');
            if( 2 < splitLine.length() ){
                double newX = QString(splitLine.at(1).toLocal8Bit().constData()).toFloat();
                double newY = QString(splitLine.at(2).toLocal8Bit().constData()).toFloat();
                this->createAndAddVertex(newX, newY);
            }
        }
        else if( line.toLower().startsWith('f') ){
            splitLine = line.split(' ');
            if( 3 < splitLine.length() ){
                this->createAndAddTriangle(this->vertexsp[QString(splitLine.at(1).toLocal8Bit().constData()).toInt()],
                                           this->vertexsp[QString(splitLine.at(2).toLocal8Bit().constData()).toInt()],
                                           this->vertexsp[QString(splitLine.at(3).toLocal8Bit().constData()).toInt()]);
            }
        }
        else if( line.toLower().startsWith('r') ){
            splitLine = line.split(' ');
            if( 2 < splitLine.length()){
                /*this->createAndAddRestrictionOld(this->vertexsp[QString(splitLine.at(1).toLocal8Bit().constData()).toInt()],
                                              this->vertexsp[QString(splitLine.at(2).toLocal8Bit().constData()).toInt()]);*/
                /*this->createAndAddRestriction(this->vertexsp[QString(splitLine.at(1).toLocal8Bit().constData()).toInt()],
                                              this->vertexsp[QString(splitLine.at(2).toLocal8Bit().constData()).toInt()]);*/
            }
        }
    }
    foreach(Triangle* t1, this->triangles()){
        foreach(Triangle* t2, this->triangles()){
            int pos = t1->isNeighbour(t2);
            if( 0 <= pos ){
                t1->setNeighbour(pos, t2);
            }
        }
        /*foreach(QVector<Vertex*> rest, this->inputRestrictionsp){
            for(int i = 0; i < 3; i++){
                if(t1->vertex((i+1)%3) == rest.at(0) && t1->vertex((i+2)%3) == rest.at(1)){
                    qDebug("Match");
                    t1->setRestricted(i);
                    break;
                }
            }
        }*/ //qDebug("restrictions: %d", this->restrictionsp.size());

        /* Solucion chanta mientras no tengo las restricciones en el archivo */

        for(int i = 0; i < 3; i++){
            if(!t1->hasNeighbour(i)){
                  RestrictedEdge *e = this->createAndAddRestriction(t1->vertex((i+1)%3), t1->vertex((i+2)%3));
                  t1->setRestricted(i, e->id());
                  e->setAdjacentTriangles(t1,0);
             }
        }
       /* foreach(Edge* edge, this->restrictionsp){
            for(int i = 0; i < 3; i++){
                if(t1->vertex((i+1)%3) == edge->getVertex(0) && t1->vertex((i+2)%3) == edge->getVertex(1)){
                    qDebug("Match");
                    t1->setRestricted(i);

                    edge->setAdjacentTriangles(t1, 0);
                    break;

                    // TODO: considerar aristas restringidas no de borde
                }
            }
        } */
    }

    this->lowerX = this->vertexsp[1]->x();
    this->lowerY = this->vertexsp[1]->y();
    this->higherX = this->vertexsp[1]->x();
    this->higherY = this->vertexsp[1]->y();

    foreach(Vertex* v, this->vertexs()){
        if(v->x() < this->lowerX)
            this->lowerX = v->x();
        if(v->y() < this->lowerY)
            this->lowerY = v->y();
        if(this->higherX < v->x())
            this->higherX = v->x();
        if(this->higherY < v->y())
            this->higherY = v->y();
    }

    inputFile.close();
    this->valuep = 0.0;
    this->scalep = 1.0;
    this->centerp = new Point((this->lowerX + this->higherX)/2.0, (this->lowerY + this->higherY)/2.0);
    this->selectedTriangle = 0;
    this->lastSelectedTriangleIDp = -1;
    this->virginp = true;
}
//! [0]

Mesh::~Mesh(){
}

//! [1]
Triangle* Mesh::createAndAddTriangle(Vertex* v0, Vertex* v1, Vertex* v2){
    Triangle* aux = new Triangle(++ct, v0, v1, v2, Constant::ALIVE);
    this->trianglesp.insert(aux->id(), aux);
    return aux;
}
//! [1]

QVector<Vertex*> Mesh::createAndAddRestrictionOld(Vertex* A, Vertex* B){
    QVector<Vertex*> aux;
    aux.insert(0, A);
    aux.insert(1, B);
    this->inputRestrictionsp.insert(++cr, aux);
    return aux;
}

RestrictedEdge* Mesh::createAndAddRestriction(Vertex *A, Vertex *B){
    RestrictedEdge* aux = new RestrictedEdge(++cr, A, B, Constant::ALIVE);
    this->restrictionsp.insert(aux->id(), aux);
    return aux;
}

//! [2]
Vertex* Mesh::createAndAddVertex(double x, double y){
    Vertex* aux = new Vertex(++cv, x, y);
    this->vertexsp.insert(aux->id(), aux);
    return aux;
}
//! [2]

void Mesh::drawMesh(){
    glPushMatrix();
    glScalef(this->scalep, this->scalep, this->scalep);
    glTranslatef(-this->centerp->x(), -this->centerp->y(), 0.0);
    foreach (Triangle* aux, this->triangles()){
        if( aux != this->selectedTriangle)
            aux->glDraw(Constant::NOT_SELECTED, this->value());
        else{
            aux->glDraw(Constant::SELECTED, this->value());
        }
    }
    glPopMatrix();
}

bool Mesh::hasTriangles(){
    return this->triangles().size() > 0 ? true : false;
}

Triangle* Mesh::getSelectedTriangle(){
    return this->selectedTriangle;
}

void Mesh::setSelectedTriangle(Triangle* T){
    this->selectedTriangle = T;
}

Triangle* Mesh::getTriangle(Point *p){
    foreach (Triangle* aux, this->triangles()){
        if(aux->include(p))
            return aux;
    }
    return 0;
}

void Mesh::removeTriangle(Triangle* T){
    if(T != 0){
        if(this->trianglesp.contains(T->id())){
            T->setStatus(Constant::DEAD);
            this->trianglesp.remove(T->id());
        }
    }
}

void Mesh::removeTriangle(int tid){
    if(this->trianglesp.contains(tid)){
        this->trianglesp.value(tid)->setStatus(Constant::DEAD);
        this->trianglesp.remove(tid);
    }
}

void Mesh::removeAndDeleteTriangle(Triangle* T){
    if(T != 0){
        if(this->trianglesp.contains(T->id())){
            this->trianglesp.remove(T->id());
            if(T->getStatus() == Constant::IN_DEATH_ROW || T->getStatus() == Constant::DEAD){
                T->setStatus(Constant::DEAD);
            } else { // ALIVE
                delete T;
            }
        }
    }
}

void Mesh::removeAndDeleteTriangle(int tid){
    if(this->trianglesp.contains(tid)){
        Triangle* t = this->trianglesp.take(tid);
        if(t->getStatus() == Constant::IN_DEATH_ROW || t->getStatus() == Constant::DEAD){
            t->setStatus(Constant::DEAD);
        } else { // ALIVE
            delete t;
        }
    }
}


void Mesh::removeRestriction(RestrictedEdge* E){
    if(E != 0){
        if(this->restrictionsp.contains(E->id())){
            E->setStatus(Constant::DEAD);
            this->restrictionsp.remove(E->id());
        }
    }
}

void Mesh::removeRestriction(int eid){
    if(this->restrictionsp.contains(eid)){
        this->restrictionsp.value(eid)->setStatus(Constant::DEAD);
        this->restrictionsp.remove(eid);
    }
}

void Mesh::removeAndDeleteRestriction(RestrictedEdge* E){
    if(E != 0){
        if(this->restrictionsp.contains(E->id())){
            this->restrictionsp.remove(E->id());
            if(E->getStatus() == Constant::IN_DEATH_ROW || E->getStatus() == Constant::DEAD){
                E->setStatus(Constant::DEAD);
            } else { // ALIVE
                delete E;
            }
        }
    }
}

void Mesh::removeAndDeleteRestriction(int eid){
    if(this->restrictionsp.contains(eid)){
        RestrictedEdge* e = this->restrictionsp.take(eid);
        if(e->getStatus() == Constant::IN_DEATH_ROW || e->getStatus() == Constant::DEAD){
            e->setStatus(Constant::DEAD);
        } else { // ALIVE
            delete e;
        }
    }
}


bool Mesh::isVirgin(){
    return this->virginp;
}
void Mesh::setVirgin(bool virgin){
    this->virginp = virgin;
}

int Mesh::vertexsSize(){
    return this->vertexsp.size();
}

int Mesh::trianglesSize(){
    return this->triangles().size();
}

void Mesh::setScale(double scale){
    this->scalep = scale;
}

void Mesh::scale(double w, double h){
    double cw = (higherX - lowerX);
    double cy = (higherY - lowerY);
    if(cw < cy){
        this->scalep = w/cw*0.99;
    }
    else{
        this->scalep = h/cy*0.99;
    }
}

double Mesh::scale(){
    return this->scalep;
}

void Mesh::setXCenter(double x){
    this->centerp->setX(x);
    qDebug("%f %f", x, this->centerp->x());
}

void Mesh::setYCenter(double y){
    this->centerp->setY(y);
}

Point* Mesh::center(){
    return this->centerp;
}

double Mesh::minAngle(){
    if(this->triangles().isEmpty())
        return 0.0;
    double ret = this->triangle(this->triangles().keys().first())->getSmallestAngleValue();
    foreach(Triangle*t, this->triangles())
        if(t->getSmallestAngleValue() < ret)
            ret = t->getSmallestAngleValue();
    return ret;
}

void Mesh::setLastSelectedTriangleID(int id){
    this->lastSelectedTriangleIDp = id;
}

int Mesh::lastSelectedTriangleID(){
    return this->lastSelectedTriangleIDp;
}


void Mesh::setValue(double v){
    this->valuep = v;
}

double Mesh::value(){
    return this->valuep;
}

Triangle* Mesh::triangle(int id){
    if(this->triangles().contains(id))
        return this->triangles().value(id);
    return 0;
}

RestrictedEdge* Mesh::restriction(int id){
    if(this->restrictions().contains(id))
        return this->restrictions().value(id);
    return 0;
}

QHash<int, Triangle*> Mesh::triangles(){
    return this->trianglesp;
}

QHash<int, Vertex*> Mesh::vertexs(){
    return this->vertexsp;
}

QHash<int, RestrictedEdge*> Mesh::restrictions(){
    return this->restrictionsp;
}

QueueOfTrianglesToProcess* Mesh::queueOfTrianglesToProcess(){ qDebug("triangles to process: %s NULL", this->trianglesToProcessp == 0? "" : "NOT");
    return this->trianglesToProcessp;
}

void Mesh::setQueueOfTrianglesToProcess(QueueOfTrianglesToProcess* q){
    this->trianglesToProcessp = q;
}


Triangle* Mesh::locate(Point *p){
    if(this->triangles().isEmpty())
        return 0;
    return this->locate(this->triangle(this->triangles().keys().last()), p);
}

Triangle* Mesh::locate(Triangle *t, Point *p){
    if(t == 0 || this->triangles().isEmpty())
        //TODO: what if internal border
        return 0;
    if(t->include(p))
        return t;
    Point* q = t->centroid();
    Point *a, *b;
    for(int i = 0; i < 3; i++){
        a = t->vertex((i+1)%3);
        b = t->vertex((i+2)%3);
        if(     0.0 <= Util::orientation(q, p, b)
            &&  Util::orientation(q, p, a) <= 0.0
            &&  0.0 <= Util::orientation(a, b, q)
            &&  Util::orientation(a, b, p) <= 0.0 )
            return this->locate(t->neighbour(i), p);
    }
    qWarning("WARNING ON MESH::LOCATE(T, P)");
    return 0;
}
