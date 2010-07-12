#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include "Point.h"

//! [0]
class Helper;
QT_BEGIN_NAMESPACE
class QPaintEvent;
class QWidget;
QT_END_NAMESPACE

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent);
    bool isEmpty();
    void setEmpty(bool _empty);
    void setLastPos(QPoint _lastPos);
    QPoint getLastPos();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);

private:
    QWidget* parent;
    GLuint axis;
    bool empty;
};
//! [0]

#endif // GLWIDGET_H
