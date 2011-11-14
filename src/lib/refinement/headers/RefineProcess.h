#ifndef REFINEPROCESS_H
#define REFINEPROCESS_H

#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/refinement/headers/TriangleSelection.h"
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
     int lts; //last triangle selection
     TriangleSelection* ts;

public:
    bool refine(Options* options);
    void loadMesh(QString filePath);
    void reloadMesh();
    static RefineProcess &getInstance();
    Mesh* mesh(){return this->meshp;};

};

#endif // REFINEPROCESS_H
