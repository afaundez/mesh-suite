#include "lib/headers/FactoryNewPointMethod.h"
#include "lib/headers/NewPointMethodRuppert.h"
#include "lib/headers/NewPointMethodLeppBisection.h"
#include "lib/headers/NewPointMethodLeppCentroid.h"
#include "lib/headers/NewPointMethodLeppCircumcenter.h"
#include "lib/headers/NewPointMethodLeppDelaunay.h"
#include "lib/headers/NewPointMethodBisection.h"
#include "lib/headers/NewPointMethodUngor.h"

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
