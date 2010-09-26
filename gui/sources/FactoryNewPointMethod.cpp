#include "headers/FactoryNewPointMethod.h"
#include "headers/NewPointMethodRuppert.h"
#include "headers/NewPointMethodLeppBisection.h"
#include "headers/NewPointMethodLeppCentroid.h"
#include "headers/NewPointMethodLeppCircumcenter.h"
#include "headers/NewPointMethodLeppDelaunay.h"
#include "headers/NewPointMethodBisection.h"
#include "headers/NewPointMethodUngor.h"

Configuration* FactoryNewPointMethod::create(Mesh *m, Triangle* t, Constant::NewPoint np, double value){
    Configuration* ret;
    NewPointMethod* npm;
    switch(np){
    case Constant::LEPP_BISECTION:
        npm = new NewPointMethodLeppBisection(m, t);
        break;
    case Constant::RUPPERT:
        npm = new NewPointMethodRuppert(m, t);
        break;
    case Constant::LEPP_DELAUNAY:
        npm = new NewPointMethodLeppDelaunay(m, t);
        break;
    case Constant::LEPP_CENTROID:
        npm = new NewPointMethodLeppCentroid(m, t);
        break;
    case Constant::UNGOR:
        npm = new NewPointMethodUngor(m, t, value);
        break;
    case Constant::LEPP_CIRCUMCENTER:
        npm = new NewPointMethodLeppCircumcenter(m, t);
        break;
    }
    ret = npm->getConfiguration();
    return ret;
}
