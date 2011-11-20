# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = MeshSuite
TEMPLATE = app
HEADERS += \
    src/lib/gui/headers/MainWindow.h \
    src/lib/gui/headers/LoadMeshDialog.h \
    src/lib/gui/headers/GLWidget.h \
    src/lib/geometric/headers/Mesh.h \
    src/lib/geometric/headers/Triangle.h \
    src/lib/geometric/headers/Vertex.h \
    src/lib/geometric/headers/Point.h \
    src/lib/refinement/headers/Constant.h \
    src/lib/refinement/headers/TriangleSelection.h \
    src/lib/refinement/headers/PreProcess.h \
    src/lib/refinement/headers/InsideInsertion.h \
    src/lib/refinement/headers/Configuration.h \
    src/lib/refinement/headers/Options.h \
    src/lib/refinement/headers/NewPointMethod.h \
    src/lib/refinement/headers/FactoryNewPointMethod.h \
    src/lib/refinement/headers/FactoryPreProcess.h \
    src/lib/refinement/headers/PreProcessNone.h \
    src/lib/refinement/headers/FactoryTriangleSelection.h \
    src/lib/refinement/headers/InsideInsertionCavity.h \
    src/lib/refinement/headers/InsideInsertionFlipDiagonal.h \
    src/lib/refinement/headers/InsertionMethod.h \
    src/lib/refinement/headers/NewPointMethodBisection.h \
    src/lib/refinement/headers/NewPointMethodLeppBisection.h \
    src/lib/refinement/headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h \
    src/lib/refinement/headers/TriangleSelectionSmallestEdge.h \
    src/lib/refinement/headers/TriangleSelectionSmallestInternalAngle.h \
    src/lib/refinement/headers/FactoryInsertionMethod.h \
    src/lib/refinement/headers/RefineProcess.h \
    src/lib/refinement/headers/InsideInsertionBasic.h \
    src/lib/refinement/headers/NewPointMethodRuppert.h \
    src/lib/refinement/headers/NewPointMethodLeppCentroid.h \
    src/lib/refinement/headers/NewPointMethodUngor.h \
    src/lib/refinement/headers/Util.h \
    src/lib/refinement/headers/PreProcessFixEncroachedVertexs.h \
    src/lib/refinement/headers/NewPointMethodLeppCircumcenter.h \
    src/lib/refinement/headers/TriangleSelectionSmallestCircumradius.h \
    src/lib/refinement/headers/NewPointMethodLeppDelaunay.h \
    src/lib/refinement/headers/TriangleSelectionLongEdgeOnlyBorder.h \
    src/lib/refinement/headers/TriangleSelectionNoPriority.h \
    src/lib/refinement/headers/QueueOfTrianglesToProcess.h \
    src/lib/refinement/headers/Queue.h \
    src/lib/refinement/headers/FactoryQueueOfTrianglesToProcess.h \
    src/lib/geometric/headers/Edge.h \
    src/lib/refinement/headers/QueueOfEncroachedEdges.h \
    src/lib/refinement/headers/PriorityQueue.h \
    src/lib/refinement/headers/Comparator.h
FORMS += \
    src/forms/MainWindow.ui \
    src/forms/LoadMeshDialog.ui
SOURCES += \
    src/lib/gui/sources/main.cpp \
    src/lib/gui/sources/MainWindow.cpp \
    src/lib/gui/sources/LoadMeshDialog.cpp \
    src/lib/gui/sources/GLWidget.cpp \
    src/lib/geometric/sources/Mesh.cpp \
    src/lib/geometric/sources/Point.cpp \
    src/lib/geometric/sources/Triangle.cpp \
    src/lib/geometric/sources/Vertex.cpp \
    src/lib/refinement/sources/RefineProcess.cpp \
    src/lib/refinement/sources/FactoryPreProcess.cpp \
    src/lib/refinement/sources/FactoryTriangleSelection.cpp \
    src/lib/refinement/sources/Options.cpp \
    src/lib/refinement/sources/FactoryNewPointMethod.cpp \
    src/lib/refinement/sources/Configuration.cpp \
    src/lib/refinement/sources/FactoryInsertionMethod.cpp \
    src/lib/refinement/sources/PreProcessNone.cpp \
    src/lib/refinement/sources/TriangleSelectionSmallestInternalAngle.cpp \
    src/lib/refinement/sources/TriangleSelectionSmallestEdgeBorderTriangleFirst.cpp \
    src/lib/refinement/sources/TriangleSelectionSmallestEdge.cpp \
    src/lib/refinement/sources/NewPointMethodBisection.cpp \
    src/lib/refinement/sources/InsideInsertionBasic.cpp \
    src/lib/refinement/sources/InsideInsertion.cpp \
    src/lib/refinement/sources/InsideInsertionFlipDiagonal.cpp \
    src/lib/refinement/sources/NewPointMethodRuppert.cpp \
    src/lib/refinement/sources/PreProcessFixEncroachedVertexs.cpp \
    src/lib/refinement/sources/NewPointMethodLeppBisection.cpp \
    src/lib/refinement/sources/NewPointMethodLeppCircumcenter.cpp \
    src/lib/refinement/sources/NewPointMethodUngor.cpp \
    src/lib/refinement/sources/TriangleSelectionSmallestCircumradius.cpp \
    src/lib/refinement/sources/NewPointMethodLeppDelaunay.cpp \
    src/lib/refinement/sources/Constant.cpp \
    src/lib/refinement/sources/InsideInsertionCavity.cpp \
    src/lib/refinement/sources/TriangleSelectionLongEdgeOnlyBorder.cpp \
    src/lib/refinement/sources/NewPointMethodLeppCentroid.cpp \
    src/lib/refinement/sources/TriangleSelectionNoPriority.cpp \
    src/lib/refinement/sources/Queue.cpp \
    src/lib/refinement/sources/FactoryQueueOfTrianglesToProcess.cpp \
    src/lib/geometric/sources/Edge.cpp \
    src/lib/refinement/sources/QueueOfEncroachedEdges.cpp \
    src/lib/refinement/sources/PriorityQueue.cpp \
    src/lib/refinement/sources/Comparator.cpp
