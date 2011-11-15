#ifndef REFINEPROCESS_H
#define REFINEPROCESS_H

#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/refinement/headers/TriangleSelection.h"
#include "src/lib/refinement/headers/QueueOfEncroachedEdges.h"
#include "src/lib/refinement/headers/QueueOfTrianglesToProcess.h"
#include "Options.h"

class RefineProcess{
private:
    static RefineProcess _instance;
    RefineProcess();
    ~RefineProcess() {}
     RefineProcess(const RefineProcess &);             // intentionally undefined
     RefineProcess & operator=(const RefineProcess &); // intentionally undefined
     Mesh* meshp;
     QString currentLoadedMesh;
     int lastTriangleSelection; //last triangle selection
     TriangleSelection* ts;

     QueueOfTrianglesToProcess* trianglesToProcess;
     QueueOfEncroachedEdges* encroachedEdges;

public:
    bool refine(Options* options);
    void loadMesh(QString filePath);
    void reloadMesh();
    static RefineProcess &getInstance();
    Mesh* mesh(){return this->meshp;};

};

#endif // REFINEPROCESS_H
