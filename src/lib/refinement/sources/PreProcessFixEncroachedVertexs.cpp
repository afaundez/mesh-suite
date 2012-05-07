#include "src/lib/refinement/headers/PreProcessFixEncroachedVertexs.h"
#include "src/lib/refinement/headers/Configuration.h"
#include "src/lib/refinement/headers/FactoryNewPointMethod.h"
#include "src/lib/refinement/headers/FactoryInsertionMethod.h"

PreProcessFixEncroachedVertexs::PreProcessFixEncroachedVertexs(Mesh* m, QueueOfTrianglesToProcess* qt, QueueOfEncroachedEdges* qe, Options* o): PreProcess(){
    this->mp = m;
    this->qtp = qt;
    this->qep = qe;
    this->op = o;
}

void PreProcessFixEncroachedVertexs::execute(){

    bool go = true;
        while(go){
            go = false;

            while(!this->qep->empty()){
                Triangle* triangle;
                QVector<Point*> ps;
                QVector<int>    es;
                RestrictedEdge* e = this->qep->getNextEdgeToProcess();

                ps.insert(0, e->midpoint());

                foreach(Triangle* t, e->getAdjacentTriangles()){

                    if( t != 0){
                        int i = t->getIndexOfEdge(e->id());
                        if( i != -1 && (e->diametralCircleInclude(t->getVertex(i))) == Constant::INCLUDED){
                            triangle = t;
                            es.insert(0, i); //es.insert(1,e->id());
                            Configuration* conf = new Configuration(this->mp, triangle, ps, es, Constant::BORDER_INCLUDED);
                            InsertionMethod* im = FactoryInsertionMethod::create(conf, this->qtp, this->qep, this->op);
                            im->execute();
                            go = true;
                            break;
                       }
                    }
                }
                if(go){
                    //this->mp->removeAndDeleteRestriction(e);
                    break;
                }
            }
        }
}

PreProcessFixEncroachedVertexs::~PreProcessFixEncroachedVertexs(){

}
