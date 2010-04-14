#include "glwidget.h"
#include <QtGui>

//! [0]
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    elapsed = 0;
    setAutoFillBackground(false);
}
//! [0]

//! [1]
void GLWidget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
}
//! [1]

//! [2]
void GLWidget::initializeGL(){
    qDebug("initializeGL()");
    glClearColor(1.0, 0.0, 0.0, 0.0);
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
    glViewport(0, 0, (GLint)width, (GLint)heigth);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//! [3]

//! [4]
void GLWidget::paintGL(){
    qDebug("paintGL()");
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0 , 0.0 , 1.0);
    glVertex2d(10, 10);
    glColor4f(0.0, 1.0 , 0.0 , 1.0);
    glVertex2d(70, 10);
    glColor4f(0.0, 0.0 , 1.0 , 1.0);
    glVertex2d(40, 50);
    glEnd();
}
//! [4]

//! [5]
void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.end();
}
//! [5]
