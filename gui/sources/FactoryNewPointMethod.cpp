#include "headers/FactoryNewPointMethod.h"
#include "headers/NewPointMethodRuppert.h"
#include "headers/NewPointMethodLeppBisection.h"
#include "headers/NewPointMethodLeppCentroid.h"
#include "headers/NewPointMethodLeppCircumcenter.h"
#include "headers/NewPointMethodBisection.h"

Configuration* FactoryNewPointMethod::create(Mesh *m, Triangle* t, Constant::NewPoint np){
    Configuration* ret;
    NewPointMethod* npm;
    switch(np){
    case Constant::LEPP_BISECTION:
        npm = new NewPointMethodLeppBisection(m, t);
        break;
    case Constant::RUPPERT:
        npm = new NewPointMethodRuppert(m, t);
        break;
    case Constant::LEPP_CENTROID:
        npm = new NewPointMethodLeppCentroid(m, t);
        break;
    case Constant::LEPP_CIRCUMCENTER:
        npm = new NewPointMethodLeppCircumcenter(m, t);
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
        break;
    }
    ret = npm->getConfiguration();
    return ret;
}
