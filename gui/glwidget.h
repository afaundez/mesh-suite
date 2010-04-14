#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>

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

public slots:
    void animate();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void paintEvent(QPaintEvent *event);

private:
    int elapsed;
};
//! [0]

#endif // GLWIDGET_H
