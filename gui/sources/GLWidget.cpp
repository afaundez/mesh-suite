#include <QtGui>

#include "headers/GLWidget.h"
#include "headers/Mesh.h"
#include "headers/MainWindow.h"

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
    qDebug("initializeGL()");

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
    glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
}
//! [1]

//! [2]
void GLWidget::resizeGL(int width, int heigth){
    qDebug("resizeGL(%d, %d)", width, heigth);
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
    qDebug("paintGL(%d, %d)",this->width(), this->height());
    glClear(GL_COLOR_BUFFER_BIT);

    // drawing the axis
    glColor4f(0.0, 0.0, 0.0, 0.2);
    glCallList(this->axis);

    // drawing the mesh
    Mesh* mesh = ((MainWindow*)(this->parent))->getMesh();
    if( mesh != 0 )
        mesh->drawMesh(this->lastPos);
}
//! [3]


bool GLWidget::isEmpty(){
    return this->empty;
}

void GLWidget::setEmpty(bool _empty){
    this->empty = _empty;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
 {
    Mesh* mesh = ((MainWindow*)(this->parent))->getMesh();
    if(mesh != 0 && mesh->hasTriangles()){
        int x = event->x();
        int y = event->y();
        this->lastPos = new Point(x - this->width()/2, this->height()/2 - y);
        this->updateGL();
    }
 }
