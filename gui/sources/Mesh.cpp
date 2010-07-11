#include <QString>
#include <QStringList>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QHashIterator>
#include <QDebug>
#include <cassert>
#include <GL/gl.h>
#include "headers/Mesh.h"

//! [0]
Mesh::Mesh(QString fileName){
    cv = 0;
    ct = 0;
    lowerX = INT_MAX;
    lowerY = INT_MAX;
    higherX = INT_MIN;
    higherY = INT_MIN;
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
                if (newX < lowerX)
                    lowerX = newX;
                if (newY < lowerY)
                    lowerY = newY;
                if (higherX < newX)
                    higherX = newX;
                if (higherY < newY)
                    higherY = newY;
                this->createAndAddVertex(newX, newY);
            }
        }
        else if( line.toLower().startsWith('f') ){QStringList splitLine = line.split(' ');
            splitLine = line.split(' ');
            if( 3 < splitLine.length() ){
                this->createAndAddTriangle(this->vertexs[QString(splitLine.at(1).toLocal8Bit().constData()).toInt()],
                                           this->vertexs[QString(splitLine.at(2).toLocal8Bit().constData()).toInt()],
                                           this->vertexs[QString(splitLine.at(3).toLocal8Bit().constData()).toInt()]);
            }
        }
    }
    // TODO: add neighbours
    foreach(Triangle* t1, this->triangles){
        foreach(Triangle* t2, this->triangles){
            int pos = t1->isNeighbour(t2);
            if( 0 <= pos){
                t1->setNeighbour(pos, t2);
            }
        }
    }
    inputFile.close();
    this->scale = 1.0;
    this->selectedTriangle = 0;
    this->virginp = true;
}
//! [0]

Mesh::~Mesh(){
}

//! [1]
Triangle* Mesh::createAndAddTriangle(Vertex* v0, Vertex* v1, Vertex* v2){
    assert( v0 != 0);
    assert( v1 != 0);
    assert( v2 != 0);
    Triangle* aux = new Triangle(++ct, v0, v1, v2);
    this->triangles.insert(aux->id(), aux);
    return aux;
}
//! [1]

//! [2]
Vertex* Mesh::createAndAddVertex(double x, double y){
    Vertex* aux = new Vertex(++cv, x, y);
    this->vertexs.insert(aux->id(), aux);
    return aux;
}
//! [2]

void Mesh::drawMesh(Point* lastPos){
    glPushMatrix();
    glScalef(this->scale, this->scale, this->scale);
    foreach (Triangle* aux, this->triangles){
        if( lastPos == 0 )
            aux->glDraw(Constant::NOT_SELECTED);
        else{
            switch(aux->include(lastPos)){
            case Constant::INCLUDED:
            case Constant::BORDER_INCLUDED:
                this->selectedTriangle = aux;
                aux->glDraw(Constant::SELECTED);
                break;
            case Constant::NOT_INCLUDED:
                aux->glDraw(Constant::NOT_SELECTED);
            default:
                break;
            }
        }
    }
    glPopMatrix();
}

bool Mesh::hasTriangles(){
    return this->triangles.size() > 0 ? true : false;
}

Triangle* Mesh::getSelectedTriangle(){
    return this->selectedTriangle;
}

void Mesh::setSelectedTriangle(Triangle* T){
    this->selectedTriangle = T;
}

void Mesh::removeTriangle(Triangle* T){
    this->triangles.remove(T->id());
}

void Mesh::removeTriangle(int tid){
    this->triangles.remove(tid);
}

void Mesh::removeAndDeleteTriangle(Triangle* T){
    if(this->triangles.contains(T->id())){
        this->triangles.remove(T->id());
        delete T;
    }
}

void Mesh::removeAndDeleteTriangle(int tid){
    if(this->triangles.contains(tid)){
        Triangle* T = this->triangles.value(tid);
        this->triangles.remove(tid);
        delete T;
    }
}

bool Mesh::isVirgin(){
    return this->virginp;
}
void Mesh::setVirgin(bool virgin){
    this->virginp = virgin;
}
