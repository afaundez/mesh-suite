#include "lib/headers/PreProcessFixEncroachedVertexs.h"
#include "lib/headers/Configuration.h"
#include "lib/headers/FactoryNewPointMethod.h"
#include "lib/headers/FactoryInsertionMethod.h"

PreProcessFixEncroachedVertexs::PreProcessFixEncroachedVertexs(Mesh* m, Options* o): PreProcess(){
    this->mp = m;
    this->op = o;
}

void PreProcessFixEncroachedVertexs::execute(){
    bool go = true;
    while(go){
        go = false;
        foreach(Triangle* t, this->mp->triangles()){
            foreach(Vertex* v, this->mp->vertexs()){
                for(int i = 0; i < 3; i++){
                    if(t->getIndex(v) == i && !t->hasNeighbour(i)){
                        Constant::IncludeCase ic = t->edgeInclude(i, v);
                        if(ic == Constant::INCLUDED || ic == Constant::BORDER_INCLUDED){
                            QVector<Point*> ps;
                            QVector<int>    es;
                            ps.insert(0, t->midpoint(i));
                            es.insert(0, i);
                            Configuration* conf = new Configuration(this->mp, t, ps, es, Constant::BORDER_INCLUDED);
                            InsertionMethod* im = FactoryInsertionMethod::create(conf, this->op);
                            im->execute();
                            go = true;
                            break;
                        }
                    }
                }
            if(go)
                break;
            }
            if(go)
                break;
        }
    }
}

PreProcessFixEncroachedVertexs::~PreProcessFixEncroachedVertexs(){

}
