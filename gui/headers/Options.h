#ifndef OPTIONS_H
#define OPTIONS_H

#include "Constant.h"

class Options{
public:
    Options();
    void setTriangleSelection(int index);
    Constant::TriangleSelection triangleSelection();
    void setTriangleSelectionValue(double value);
    double triangleSelectionValue();

    void setNewPointMethod(int index);
    Constant::NewPoint newPointMethod();
    void setOutsideNewPointMethod(int index);
    Constant::OutsideNewPoint outsideNewPointMethod();
    void setInsideInsertion(int index);
    Constant::InsideInsertion insideInsertion();
    void setOneEdgeRestrictedInsertion(int index);
    void setParameter(double p);
    double parameter();

    void setLepp(bool active);
    bool lepp();
    void setEncroached(bool active);
    bool encroached();

    void setManual(bool manual);
    bool manual();
    void setAutomatic(bool automatic);
    bool automatic();
    void setOnlyFirstPreProcess(bool onlyFirst);
    bool onlyFirstPreProcess();

    void setUseLepp(bool use);
    bool useLepp();

    void setRepeatLastSelectedTriangle(bool repeat);
    bool repeatLastSelectedTriangle();
    void setPreProcess(int index);
    Constant::PreProcess preProcess();
    ~Options();

private:
    Constant::TriangleSelection tsp;
    double tsvp;
    Constant::NewPoint npp;
    Constant::OutsideNewPoint onpp;
    Constant::InsideInsertion inpp;
    bool repeatLastSelectedTrianglep;
    bool useLeppp;
    double pp;
    bool mp;
    bool ap;
    bool ofp;
    bool lp;
    bool ep;
    Constant::PreProcess ppp;
};

#endif // OPTIONS_H
