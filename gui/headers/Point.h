#ifndef POINT_H
#define POINT_H

class Point{

public:
    Point(double x, double y);
    double x();
    double y();
    void setX(double x);
    void setY(double y);
    void glDraw();

protected:
    double xp, yp;
};

#endif // POINT_H
