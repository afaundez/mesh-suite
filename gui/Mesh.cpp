#include <QString>
#include <QStringList>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QHashIterator>
#include <QDebug>
#include <QGLWidget>
#include <cassert>
#include "Mesh.h"

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
                qDebug() << QString(splitLine.at(1).toLocal8Bit().constData()).toInt()
                         << QString(splitLine.at(2).toLocal8Bit().constData()).toInt()
                         << QString(splitLine.at(3).toLocal8Bit().constData()).toInt();
                this->createAndAddTriangle(this->vertexs[QString(splitLine.at(1).toLocal8Bit().constData()).toInt()],
                                           this->vertexs[QString(splitLine.at(2).toLocal8Bit().constData()).toInt()],
                                           this->vertexs[QString(splitLine.at(3).toLocal8Bit().constData()).toInt()]);
            }
        }
    }
    inputFile.close();
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
    this->triangles.insert(aux->getId(), aux);
    return aux;
}
//! [1]

//! [2]
Vertex* Mesh::createAndAddVertex(double x, double y){
    Vertex* aux = new Vertex(++cv, x, y);
    this->vertexs.insert(aux->getId(), aux);
    return aux;
}
//! [2]

void Mesh::drawMesh(int w, int h){
    glPushMatrix();
    glTranslated(-lowerX +5, -lowerY+5, 0.0);
    if( w/higherX < h/higherY)
        glScalef((w-10)/higherX, (w-10)/higherX, (w-10)/higherX);
    else
        glScalef((h-10)/higherY, (h-10)/higherY, (h-10)/higherY);
    glBegin(GL_LINES);
    foreach (Triangle* aux, this->triangles){
        Vertex* v0 = aux->getVertex(0);
        Vertex* v1 = aux->getVertex(1);
        Vertex* v2 = aux->getVertex(2);
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex2f(v0->getX(), v0->getY());
        glVertex2f(v1->getX(), v1->getY());
        glVertex2f(v1->getX(), v1->getY());
        glVertex2f(v2->getX(), v2->getY());
        glVertex2f(v2->getX(), v2->getY());
        glVertex2f(v0->getX(), v0->getY());
    }
    glEnd();
    glPointSize(3.0);
    glBegin(GL_POINTS);
    foreach (Vertex* aux, this->vertexs){
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(aux->getX(), aux->getY());
    }
    glEnd();
    glPointSize(1.0);
    glPopMatrix();
}
