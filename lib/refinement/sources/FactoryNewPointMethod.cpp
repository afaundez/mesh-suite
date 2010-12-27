#include "lib/refinement/headers/FactoryNewPointMethod.h"
#include "lib/refinement/headers/NewPointMethodRuppert.h"
#include "lib/refinement/headers/NewPointMethodLeppBisection.h"
#include "lib/refinement/headers/NewPointMethodLeppCentroid.h"
#include "lib/refinement/headers/NewPointMethodLeppCircumcenter.h"
#include "lib/refinement/headers/NewPointMethodLeppDelaunay.h"
#include "lib/refinement/headers/NewPointMethodBisection.h"
#include "lib/refinement/headers/NewPointMethodUngor.h"

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
