#include "src/lib/refinement/headers/PreProcessFixEncroachedVertexs.h"
#include "src/lib/refinement/headers/Configuration.h"
#include "src/lib/refinement/headers/FactoryNewPointMethod.h"
#include "src/lib/refinement/headers/FactoryInsertionMethod.h"

PreProcessFixEncroachedVertexs::PreProcessFixEncroachedVertexs(Mesh* m, QueueOfTrianglesToProcess* qt, Options* o): PreProcess(){
    this->mp = m;
    this->qtp = qt;
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
                            InsertionMethod* im = FactoryInsertionMethod::create(conf, this->qtp, 0, this->op);
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
