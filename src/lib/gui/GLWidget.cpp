#include <QtGui>

#include "lib/gui/MainWindow.h"
#include "lib/gui/GLWidget.h"
#include "lib/geometric/Mesh.h"
#include "lib/refinement/RefineProcess.h"

//! [0]
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->axis      = 0;
    this->empty     = true;
    this->parent    = parent;
    setAutoFillBackground(false);
}
//! [0]


static void theAxis(){
    glBegin(GL_LINES);
    glVertex4f(0.0, 1.0, 0.0, 0.0);
    glVertex4f(0.0, 0.0, 0.0, 1.0);

    glVertex4f(0.0, -1.0, 0.0, 0.0);
    glVertex4f(0.0,  0.0, 0.0, 1.0);

    glVertex4f(1.0, 0.0, 0.0, 0.0);
    glVertex4f(0.0, 0.0, 0.0, 1.0);

    glVertex4f(-1.0, 0.0, 0.0, 0.0);
    glVertex4f( 0.0, 0.0, 0.0, 1.0);
    glEnd();
}

//! [1]
void GLWidget::initializeGL(){
    //qDebug("initializeGL()");

    this->axis      = glGenLists (1);
    glNewList(axis, GL_COMPILE);
    theAxis();
    glEndList();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClearDepth(1.0);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable (GL_LINE_SMOOTH);
    glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
    glLineWidth (1.5);
}
//! [1]

//! [2]
void GLWidget::resizeGL(int width, int heigth){
    //qDebug("resizeGL(%d, %d)", width, heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0.0, 0.0, (GLsizei)width, (GLsizei)heigth);
    gluOrtho2D((GLdouble)(-width/2.0), (GLdouble)(width/2.0), (GLdouble)(-heigth/2.0), (GLdouble)(heigth/2.0));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//! [2]

//! [3]
void GLWidget::paintGL(){
    //qDebug("paintGL(%d, %d)",this->width(), this->height());
    glClear(GL_COLOR_BUFFER_BIT);

    // drawing the axis
    glColor4f(0.0, 0.0, 0.0, 0.2);
    glCallList(this->axis);

    // drawing the mesh
    //Mesh* mesh = ((MainWindow*)(this->parent))->getMesh();
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if( mesh != 0 )
        mesh->drawMesh();

}
//! [3]


bool GLWidget::isEmpty(){
    return this->empty;
}

void GLWidget::setEmpty(bool _empty){
    this->empty = _empty;
}

void GLWidget::mousePressEvent(QMouseEvent *event){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    switch(event->button()){
    case Qt::LeftButton:
        if(mesh != 0 && mesh->hasTriangles()){
            int x = event->x();
            int y = event->y();
            Point* pos = new Point((x - this->width()/2)/mesh->scale() + mesh->center()->x(), (this->height()/2 - y)/mesh->scale() + mesh->center()->y());
            //mesh->setSelectedTriangle(mesh->getTriangle(pos));
            mesh->setSelectedTriangle(mesh->locate(pos));
            this->updateGL();
        }
        break;
    case Qt::RightButton:
        if(mesh != 0 && mesh->hasTriangles()){
            int x = event->x();
            int y = event->y();
            Point* pos = new Point((x - this->width()/2)/mesh->scale() + mesh->center()->x(), (this->height()/2 - y)/mesh->scale() + mesh->center()->y());
            mesh->setSelectedTriangle(mesh->getTriangle(pos));
            mesh->setXCenter(pos->x());
            mesh->setYCenter(pos->y());
            this->updateGL();
            ((MainWindow*)this->parent)->setCenter(pos);
        }
        break;
    default:
        break;

    }
}

void GLWidget::wheelEvent(QWheelEvent * event){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if(mesh != 0 && mesh->hasTriangles()){
        double numDegrees = event->delta() / 8;
        double numSteps = numDegrees / 15.0 / 10.0;
        double newScale = mesh->scale() + numSteps;
        mesh->setScale(newScale);
        this->updateGL();
        ((MainWindow*)this->parent)->setScale(newScale);
    }
}
