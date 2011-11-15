#ifndef MESH_H
#define MESH_H

#include <QHash>
#include <QPoint>
#include <queue>
#include "Triangle.h"
#include "Edge.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"

class Mesh
{

public:
    Mesh(QString fileName);
    void addTriangle(Triangle* T);
    Triangle* createAndAddTriangle(Vertex* A, Vertex* B, Vertex *C);
    QVector<Vertex*> createAndAddRestrictionOld(Vertex* A, Vertex* B);
    Edge* createAndAddRestriction(Vertex* A, Vertex* B);
    void addVertex(Vertex* A);
    Vertex* createAndAddVertex(double x, double y);
    void drawMesh();
    bool hasTriangles();
    Triangle* getSelectedTriangle();
    void setSelectedTriangle(Triangle* T);
    Triangle* getTriangle(Point* p);
    void removeTriangle(Triangle* T);
    void removeTriangle(int tid);
    void removeAndDeleteTriangle(Triangle* T);
    void removeAndDeleteTriangle(int tid);
    bool isVirgin();
    void setVirgin(bool virgin);
    int vertexsSize();
    int trianglesSize();
    void setScale(double scale);
    void scale(double w, double h);
    double scale();
    void setXCenter(double x);
    void setYCenter(double y);
    Point* center();


    double minAngle();

    void setLastSelectedTriangleID(int id);
    int lastSelectedTriangleID();

    void setValue(double v);
    double value();
    Triangle* triangle(int id);
    //QHash<int, Triangle*>   restrictedTriangles();
    QHash<int, Triangle*>   triangles();
    QHash<int, Vertex*>     vertexs();
    QHash<int, Edge*>       restrictions();
    QueueOfTrianglesToProcess* queueOfTrianglesToProcess();
    void setQueueOfTrianglesToProcess(QueueOfTrianglesToProcess* q);
    Triangle* locate(Point* p);
    Triangle* locate(Triangle* t, Point* p);
    ~Mesh();

private:
    QHash<int, Triangle*>   trianglesp;
    QHash<int, Vertex*>     vertexsp;
    QHash<int, Edge*>   restrictionsp;
    QHash<int, QVector<Vertex*> > inputRestrictionsp;
    QHash<int, QVector<Vertex*> > stitchedRstrictionsp; //utilizado para recuperacion de aristas
    QueueOfTrianglesToProcess *trianglesToProcessp;
    int cv, ct, cr;
    int lowerX, higherX, lowerY, higherY;
    double scalep;
    Point* centerp;
    Triangle* selectedTriangle;
    int lastSelectedTriangleIDp;
    bool virginp;
    double valuep;
};

#endif // MESH_H
