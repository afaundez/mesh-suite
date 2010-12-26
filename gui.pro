# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = MeshSuite
TEMPLATE = app
HEADERS += \
    lib/headers/MainWindow.h \
    lib/headers/GLWidget.h \
    lib/headers/Mesh.h \
    lib/headers/Triangle.h \
    lib/headers/Vertex.h \
    lib/headers/LoadMeshDialog.h \
    lib/headers/Constant.h \
    lib/headers/TriangleSelection.h \
    lib/headers/PreProcess.h \
    lib/headers/InsideInsertion.h \
    lib/headers/Point.h \
    lib/headers/Configuration.h \
    lib/headers/Options.h \
    lib/headers/NewPointMethod.h \
    lib/headers/FactoryNewPointMethod.h \
    lib/headers/FactoryPreProcess.h \
    lib/headers/PreProcessNone.h \
    lib/headers/FactoryTriangleSelection.h \
    lib/headers/InsideInsertionCavity.h \
    lib/headers/InsideInsertionFlipDiagonal.h \
    lib/headers/InsertionMethod.h \
    lib/headers/NewPointMethodBisection.h \
    lib/headers/NewPointMethodLeppBisection.h \
    lib/headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h \
    lib/headers/TriangleSelectionSmallestEdge.h \
    lib/headers/TriangleSelectionSmallestInternalAngle.h \
    lib/headers/FactoryInsertionMethod.h \
    lib/headers/RefineProcess.h \
    lib/headers/InsideInsertionBasic.h \
    lib/headers/NewPointMethodRuppert.h \
    lib/headers/NewPointMethodLeppCentroid.h \
    lib/headers/NewPointMethodUngor.h \
    lib/headers/Util.h \
    lib/headers/PreProcessFixEncroachedVertexs.h \
    lib/headers/NewPointMethodLeppCircumcenter.h \
    lib/headers/TriangleSelectionSmallestCircumradius.h \
    lib/headers/NewPointMethodLeppDelaunay.h \
    lib/headers/TriangleSelectionLongEdgeOnlyBorder.h \
    lib/headers/TriangleSelectionNoPriority.h
FORMS += \
    forms/MainWindow.ui \
    forms/LoadMeshDialog.ui
SOURCES += \
    lib/sources/Vertex.cpp \
    lib/sources/Triangle.cpp \
    lib/sources/Mesh.cpp \
    lib/sources/MainWindow.cpp \
    lib/sources/main.cpp \
    lib/sources/LoadMeshDialog.cpp \
    lib/sources/GLWidget.cpp \
    lib/sources/Point.cpp \
    lib/sources/RefineProcess.cpp \
    lib/sources/FactoryPreProcess.cpp \
    lib/sources/FactoryTriangleSelection.cpp \
    lib/sources/Options.cpp \
    lib/sources/FactoryNewPointMethod.cpp \
    lib/sources/Configuration.cpp \
    lib/sources/FactoryInsertionMethod.cpp \
    lib/sources/PreProcessNone.cpp \
    lib/sources/TriangleSelectionSmallestInternalAngle.cpp \
    lib/sources/TriangleSelectionSmallestEdgeBorderTriangleFirst.cpp \
    lib/sources/TriangleSelectionSmallestEdge.cpp \
    lib/sources/NewPointMethodBisection.cpp \
    lib/sources/InsideInsertionBasic.cpp \
    lib/sources/InsideInsertion.cpp \
    lib/sources/InsideInsertionFlipDiagonal.cpp \
    lib/sources/NewPointMethodRuppert.cpp \
    lib/sources/PreProcessFixEncroachedVertexs.cpp \
    lib/sources/NewPointMethodLeppBisection.cpp \
    lib/sources/NewPointMethodLeppCircumcenter.cpp \
    lib/sources/NewPointMethodUngor.cpp \
    lib/sources/TriangleSelectionSmallestCircumradius.cpp \
    lib/sources/NewPointMethodLeppDelaunay.cpp \
    lib/sources/Constant.cpp \
    lib/sources/InsideInsertionCavity.cpp \
    lib/sources/TriangleSelectionLongEdgeOnlyBorder.cpp \
    lib/sources/NewPointMethodLeppCentroid.cpp \
    lib/sources/TriangleSelectionNoPriority.cpp
