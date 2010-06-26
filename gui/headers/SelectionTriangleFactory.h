#ifndef SELECTIONTRIANGLEFACTORY_H
#define SELECTIONTRIANGLEFACTORY_H

class SelectionTriangleFactory
{
public:
    static SelectionTriangle* build(Constant::InsertionCase type, int index);

};

#endif // SELECTIONTRIANGLEFACTORY_H
