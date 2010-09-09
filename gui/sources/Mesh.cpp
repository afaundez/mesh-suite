#include <QString>
#include <QStringList>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QHashIterator>
#include <QDebug>
#include <GL/gl.h>
#include "headers/Mesh.h"

//! [0]
Mesh::Mesh(QString fileName){
    cv = 0;
    ct = 0;
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
        else if( line.toLower().startsWith('f') ){QStringList splitLine = line.split(' ');
            splitLine = line.split(' ');
            if( 3 < splitLine.length() ){
                this->createAndAddTriangle(this->vertexsp[QString(splitLine.at(1).toLocal8Bit().constData()).toInt()],
                                           this->vertexsp[QString(splitLine.at(2).toLocal8Bit().constData()).toInt()],
                                           this->vertexsp[QString(splitLine.at(3).toLocal8Bit().constData()).toInt()]);
            }
        }
    }
    foreach(Triangle* t1, this->trianglesp){
        foreach(Triangle* t2, this->trianglesp){
            int pos = t1->isNeighbour(t2);
            if( 0 <= pos ){
                t1->setNeighbour(pos, t2);
            }
        }
    }
//    int ti = 1;
//    foreach(Triangle* taux, this->trianglesp){
//        for(int pos = 0; pos < 3; pos++ )
//            if(taux->getNeighbour(pos) == 0)
//                qDebug("%d %d %d", ti++,taux->vertex((pos+1)%3)->id(), taux->vertex((pos+2)%3)->id());
//    }

    inputFile.close();
    this->valuep = 0.0;
    this->scalep = 1.0;
    this->centerp = new Point(0.0, 0.0);
    this->selectedTriangle = 0;
    this->lastSelectedTriangleIDp = -1;
    this->virginp = true;
}
//! [0]

Mesh::~Mesh(){
}

//! [1]
Triangle* Mesh::createAndAddTriangle(Vertex* v0, Vertex* v1, Vertex* v2){
    Triangle* aux = new Triangle(++ct, v0, v1, v2);
    this->trianglesp.insert(aux->id(), aux);
    return aux;
}
//! [1]

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
    foreach (Triangle* aux, this->trianglesp){
        if( aux != this->selectedTriangle)
            aux->glDraw(Constant::NOT_SELECTED, this->value());
        else{
            aux->glDraw(Constant::SELECTED, this->value());
        }
    }
    glPopMatrix();
}

bool Mesh::hasTriangles(){
    return this->trianglesp.size() > 0 ? true : false;
}

Triangle* Mesh::getSelectedTriangle(){
    return this->selectedTriangle;
}

void Mesh::setSelectedTriangle(Triangle* T){
    this->selectedTriangle = T;
}

Triangle* Mesh::getTriangle(Point *p){
    foreach (Triangle* aux, this->trianglesp){
        if(aux->include(p))
            return aux;
    }
    return 0;
}

void Mesh::removeTriangle(Triangle* T){
    this->trianglesp.remove(T->id());
}

void Mesh::removeTriangle(int tid){
    this->trianglesp.remove(tid);
}

void Mesh::removeAndDeleteTriangle(Triangle* T){
    if(this->trianglesp.contains(T->id())){
        this->trianglesp.remove(T->id());
        delete T;
    }
}

void Mesh::removeAndDeleteTriangle(int tid){
    if(this->trianglesp.contains(tid)){
        Triangle* t = this->trianglesp.take(tid);
        delete t;
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
    return this->trianglesp.size();
}

void Mesh::setScale(double scale){
    this->scalep = scale;
}

double Mesh::scale(){
    return this->scalep;
}

void Mesh::setXCenter(int x){
    this->centerp->setX(x);
}

void Mesh::setYCenter(int y){
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
    if(this->trianglesp.contains(id))
        return this->trianglesp.value(id);
    return 0;
}

QHash<int, Triangle*> Mesh::triangles(){
    return this->trianglesp;
}

QHash<int, Vertex*> Mesh::vertexs(){
    return this->vertexsp;
}
