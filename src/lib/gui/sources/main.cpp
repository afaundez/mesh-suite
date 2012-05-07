#include <QtGui/QApplication>
#include <string>
#include "src/lib/gui/headers/MainWindow.h"

#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/refinement/headers/Options.h"
#include "src/lib/refinement/headers/RefineProcess.h"
#include "src/lib/refinement/headers/Time.h"


//! [0]
int main(int argc, char *argv[])
{
    if( argc != 1 && argc != 6){ printf("argc inside if %d\n", argc);
        printf("Ejecucion con gui: \n%s\n", argv[0]);
        printf("Ejecucion solo linea de comandos: \n%s ruta_archivo preproceso priorizacion_triangulos angulo algoritmo\n", argv[0]);
        exit(0);
    }

    //std::string firstArgument = std::string(argv[1]);
    //std::string gui = "-gui";
    //if(firstArgument.compare(gui) == 0){
    if(argc == 1){
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        Options* options =  new Options();
        options->setOnlyFirstPreProcess(0);
        options->setPreProcess(atoi(argv[2]));
        options->setTriangleSelection(atoi(argv[3]));
        options->setTriangleSelectionValue(atof(argv[4]));
        options->setNewPointMethod(atoi(argv[5]));
        options->setInsideInsertion(Constant::FLIP_DIAGONAL);
        options->setRepeatLastSelectedTriangle(1);
        options->setAutomatic(1);

        QString filePath = QString(argv[1]);
        QString configText;

        printf("Cargando archivo ..................\n\n");
        RefineProcess::getInstance().loadMesh(filePath);
        Mesh* mesh = RefineProcess::getInstance().mesh();
        mesh->setValue(options->triangleSelectionValue());

        if(!options->onlyFirstPreProcess() || ( options->onlyFirstPreProcess() && mesh->isVirgin() ))
            configText.append("Pre-proceso: " + QString(Constant::preProcessNames[options->preProcess()]) + "\n");
        if(options->automatic())
            configText.append("Seleccion Triangulo: " + QString(Constant::triangleSelectionNames[options->triangleSelection()]) + "\n");
        else
            configText.append("Seleccion Manual\n");
        configText.append("Angulo exigido: " + QString::number(options->triangleSelectionValue()) + " grados\n");
        configText.append("Nuevo Punto: " + QString(Constant::newPointNames[options->newPointMethod()]) + "\n");
        configText.append("Tipo Insercion: " + QString(Constant::insertionNames[options->insideInsertion()]) + "\n");
        printf("Configuracion:\n%s", configText.toStdString().c_str());
        printf("\nEjecutando algoritmo ..................\n\n");


        bool go = true;

        struct timeval earlier;
        struct timeval later;
        gettimeofday(&earlier,NULL);
        while(go){
            go = RefineProcess::getInstance().refine(options);
        }
        gettimeofday(&later,NULL);


        if(mesh != 0){
            QString t   = QString::number(mesh->trianglesSize());
            QString v   = QString::number(mesh->vertexsSize());
            QString a   = QString::number(mesh->minAngle());
            printf("Resultados:\nAngulo Minimo: %s ; Triangulos: %s ; Vertices: %s ; ", a.toStdString().c_str(), t.toStdString().c_str(), v.toStdString().c_str());
            printf("Tiempo: %lld ms\n\n", timeval_diff(NULL,&later,&earlier)/1000);
        }
        return 0;
    }

}
//! [0]
