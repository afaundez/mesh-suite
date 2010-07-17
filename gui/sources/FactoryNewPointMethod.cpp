#include "headers/FactoryNewPointMethod.h"
#include "headers/NewPointMethodBisection.h"
#include "headers/NewPointMethodCircumcenter.h"
#include "headers/NewPointMethodCentroid.h"
#include "headers/NewPointMethodRuppert.h"

Configuration* FactoryNewPointMethod::create(Mesh *m, Triangle* t, Constant::NewPoint np){
    Configuration* ret;
    NewPointMethod* npm;
    switch(np){
    case Constant::MIDPOINT_LONGEST_EDGE:
        npm = new NewPointMethodBisection(m, t);
        break;
    case Constant::CENTROID:
        npm = new NewPointMethodCentroid(m, t);
        break;
    case Constant::CIRCUMCENTER:
        npm = new NewPointMethodCircumcenter(m, t);
        break;
    case Constant::OFF_CENTER:
        break;
    case Constant::RUPPERT:
        npm = new NewPointMethodRuppert(m, t);
        break;
    case Constant::LEPP_BISECTION:
        break;
    case Constant::LEPP_CENTROID:
        break;
    case Constant::LEPP_DELAUNAY:
        break;
    case Constant::UNGOR:
        break;
    }
    ret = npm->getConfiguration();
    return ret;
}


Configuration* FactoryNewPointMethod::create(Mesh *m, Triangle* t, Constant::OutsideNewPoint np){
    Configuration* ret;
    NewPointMethod* npm;
    switch(np){
    case Constant::OUTSIDE_MIDPOINT_LONGEST_EDGE:
        npm = new NewPointMethodBisection(m, t);
        break;
    case Constant::MIDPOINT_ENCROACHED_BORDER:
        npm = new NewPointMethodBisection(m, t);
        break;
    }
    ret = npm->getConfiguration();
    return ret;
}
