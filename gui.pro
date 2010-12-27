# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = MeshSuite
TEMPLATE = app
HEADERS += \
    lib/gui/headers/MainWindow.h \
    lib/gui/headers/LoadMeshDialog.h \
    lib/gui/headers/GLWidget.h \
    lib/geometric/headers/Mesh.h \
    lib/geometric/headers/Triangle.h \
    lib/geometric/headers/Vertex.h \
    lib/geometric/headers/Point.h \
    lib/refinement/headers/Constant.h \
    lib/refinement/headers/TriangleSelection.h \
    lib/refinement/headers/PreProcess.h \
    lib/refinement/headers/InsideInsertion.h \
    lib/refinement/headers/Configuration.h \
    lib/refinement/headers/Options.h \
    lib/refinement/headers/NewPointMethod.h \
    lib/refinement/headers/FactoryNewPointMethod.h \
    lib/refinement/headers/FactoryPreProcess.h \
    lib/refinement/headers/PreProcessNone.h \
    lib/refinement/headers/FactoryTriangleSelection.h \
    lib/refinement/headers/InsideInsertionCavity.h \
    lib/refinement/headers/InsideInsertionFlipDiagonal.h \
    lib/refinement/headers/InsertionMethod.h \
    lib/refinement/headers/NewPointMethodBisection.h \
    lib/refinement/headers/NewPointMethodLeppBisection.h \
    lib/refinement/headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h \
    lib/refinement/headers/TriangleSelectionSmallestEdge.h \
    lib/refinement/headers/TriangleSelectionSmallestInternalAngle.h \
    lib/refinement/headers/FactoryInsertionMethod.h \
    lib/refinement/headers/RefineProcess.h \
    lib/refinement/headers/InsideInsertionBasic.h \
    lib/refinement/headers/NewPointMethodRuppert.h \
    lib/refinement/headers/NewPointMethodLeppCentroid.h \
    lib/refinement/headers/NewPointMethodUngor.h \
    lib/refinement/headers/Util.h \
    lib/refinement/headers/PreProcessFixEncroachedVertexs.h \
    lib/refinement/headers/NewPointMethodLeppCircumcenter.h \
    lib/refinement/headers/TriangleSelectionSmallestCircumradius.h \
    lib/refinement/headers/NewPointMethodLeppDelaunay.h \
    lib/refinement/headers/TriangleSelectionLongEdgeOnlyBorder.h \
    lib/refinement/headers/TriangleSelectionNoPriority.h
FORMS += \
    forms/MainWindow.ui \
    forms/LoadMeshDialog.ui
SOURCES += \
    lib/gui/sources/main.cpp \
    lib/gui/sources/MainWindow.cpp \
    lib/gui/sources/LoadMeshDialog.cpp \
    lib/gui/sources/GLWidget.cpp \
    lib/geometric/sources/Mesh.cpp \
    lib/geometric/sources/Point.cpp \
    lib/geometric/sources/Triangle.cpp \
    lib/geometric/sources/Vertex.cpp \
    lib/refinement/sources/RefineProcess.cpp \
    lib/refinement/sources/FactoryPreProcess.cpp \
    lib/refinement/sources/FactoryTriangleSelection.cpp \
    lib/refinement/sources/Options.cpp \
    lib/refinement/sources/FactoryNewPointMethod.cpp \
    lib/refinement/sources/Configuration.cpp \
    lib/refinement/sources/FactoryInsertionMethod.cpp \
    lib/refinement/sources/PreProcessNone.cpp \
    lib/refinement/sources/TriangleSelectionSmallestInternalAngle.cpp \
    lib/refinement/sources/TriangleSelectionSmallestEdgeBorderTriangleFirst.cpp \
    lib/refinement/sources/TriangleSelectionSmallestEdge.cpp \
    lib/refinement/sources/NewPointMethodBisection.cpp \
    lib/refinement/sources/InsideInsertionBasic.cpp \
    lib/refinement/sources/InsideInsertion.cpp \
    lib/refinement/sources/InsideInsertionFlipDiagonal.cpp \
    lib/refinement/sources/NewPointMethodRuppert.cpp \
    lib/refinement/sources/PreProcessFixEncroachedVertexs.cpp \
    lib/refinement/sources/NewPointMethodLeppBisection.cpp \
    lib/refinement/sources/NewPointMethodLeppCircumcenter.cpp \
    lib/refinement/sources/NewPointMethodUngor.cpp \
    lib/refinement/sources/TriangleSelectionSmallestCircumradius.cpp \
    lib/refinement/sources/NewPointMethodLeppDelaunay.cpp \
    lib/refinement/sources/Constant.cpp \
    lib/refinement/sources/InsideInsertionCavity.cpp \
    lib/refinement/sources/TriangleSelectionLongEdgeOnlyBorder.cpp \
    lib/refinement/sources/NewPointMethodLeppCentroid.cpp \
    lib/refinement/sources/TriangleSelectionNoPriority.cpp
