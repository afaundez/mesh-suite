#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{

public:
    Vertex(int id, double _x, double _y);
    ~Vertex();
    int getId();
    double getX();
    double getY();
    double distance(Vertex* Q);

private:
    int id;
    double x;
    double y;
};

#endif // VERTEX_H
