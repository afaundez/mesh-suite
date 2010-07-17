#ifndef OPTIONS_H
#define OPTIONS_H

#include "Constant.h"

class Options{
public:
    Options();
    void setTriangleSelection(int index);
    Constant::TriangleSelection triangleSelection();
    void setTriangleSelectionValue(int value);
    int triangleSelectionValue();

    void setNewPointMethod(int index);
    Constant::NewPoint newPointMethod();
    void setOutsideNewPointMethod(int index);
    Constant::OutsideNewPoint outsideNewPointMethod();
    void setInsideInsertion(int index);
    Constant::InsideInsertion insideInsertion();
    void setOneEdgeRestrictedInsertion(int index);
    Constant::OneEdgeRestrictedInsertion oneEdgeRestrictedInsertion();
    void setTwoEdgeRestrictedInsertion(int index);
    Constant::TwoEdgeRestrictedInsertion twoEdgeRestrictedInsertion();
    void setThreeEdgeRestrictedInsertion(int index);
    Constant::ThreeEdgeRestrictedInsertion threeEdgeRestrictedInsertion();
    void setParameter(double p);
    double parameter();

    void setManual(bool manual);
    bool manual();
    void setOnlyFirstPreProcess(bool onlyFirst);
    bool onlyFirstPreProcess();
    void setPreProcess(int index);
    Constant::PreProcess preProcess();
    ~Options();

private:
    Constant::TriangleSelection tsp;
    int tsvp;
    Constant::NewPoint npp;
    Constant::OutsideNewPoint onpp;
    Constant::InsideInsertion inpp;
    Constant::OneEdgeRestrictedInsertion ornpp;
    Constant::TwoEdgeRestrictedInsertion trnpp;
    Constant::ThreeEdgeRestrictedInsertion ttrnpp;
    double pp;
    bool mp;
    bool ofp;
    Constant::PreProcess ppp;
};

#endif // OPTIONS_H
