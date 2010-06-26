#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPoint>

class Circle{
public:
    Circle();
    int include(QPoint P);
    ~Circle();

private:
    QPoint center;
    int radius;
};

#endif // CIRCLE_H
