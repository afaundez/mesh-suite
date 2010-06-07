#include <QtGui>

#include "headers/GLWidget.h"
#include "headers/Mesh.h"
#include "headers/MainWindow.h"

//! [0]
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->parent = parent;
    setAutoFillBackground(false);

}
//! [0]

//! [1]
void GLWidget::animate()
{
    //paintGL();
}
//! [1]

//! [2]
void GLWidget::initializeGL(){
    qDebug("initializeGL()");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClearDepth(1.0);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
}
//! [2]

//! [3]
void GLWidget::resizeGL(int width, int heigth){
    qDebug("resizeGL(%d, %d)", width, heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0.0, 0.0, (GLint)width, (GLint)heigth);
    gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)heigth);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//! [3]

//! [4]
void GLWidget::paintGL(){
    qDebug("paintGL(%d, %d)",this->width(), this->height());
    glClear(GL_COLOR_BUFFER_BIT);
    Mesh* mesh = ((MainWindow*)(this->parent))->getMesh();
    if( mesh != 0 )
        mesh->drawMesh(this->width(), this->height());
}
//! [4]
