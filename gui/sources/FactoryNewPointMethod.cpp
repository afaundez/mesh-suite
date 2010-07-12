#include "headers/FactoryNewPointMethod.h"
#include "headers/NewPointMethodBisection.h"
#include "headers/NewPointMethodCircumcenter.h"

Configuration* FactoryNewPointMethod::create(Mesh *m, Triangle* t, Constant::NewPoint np){
    Configuration* ret;
    NewPointMethod* npm;
    switch(np){
    case Constant::BISECT_LONGEST_EDGE:
        npm = new NewPointMethodBisection(m, t);
        break;
    case Constant::CIRCUMCENTER:
        npm = new NewPointMethodCircumcenter(m, t);
        break;
    default:
        npm = new NewPointMethodBisection(m,t);
        break;
    }
    ret = npm->getConfiguration();
    return ret;
}


Configuration* FactoryNewPointMethod::create(Mesh *m, Triangle* t, Constant::OutsideNewPoint np){
    Configuration* ret;
    NewPointMethod* npm;
    switch(np){
    case Constant::OUTSIDE_BISECT_LONGEST_EDGE:
        npm = new NewPointMethodBisection(m, t);
        break;
    default:
        npm = new NewPointMethodBisection(m,t);
        break;
    }
    ret = npm->getConfiguration();
    return ret;
}
