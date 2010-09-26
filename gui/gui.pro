# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = MeshSuite
TEMPLATE = app
HEADERS += headers/MainWindow.h \
    headers/GLWidget.h \
    headers/Mesh.h \
    headers/Triangle.h \
    headers/Vertex.h \
    headers/LoadMeshDialog.h \
    headers/Constant.h \
    headers/TriangleSelection.h \
    headers/PreProcess.h \
    headers/InsideInsertion.h \
    headers/Point.h \
    headers/Configuration.h \
    headers/Options.h \
    headers/NewPointMethod.h \
    headers/FactoryNewPointMethod.h \
    headers/FactoryPreProcess.h \
    headers/PreProcessNone.h \
    headers/FactoryTriangleSelection.h \
    headers/InsideInsertionCavity.h \
    headers/InsideInsertionFlipDiagonal.h \
    headers/InsertionMethod.h \
    headers/NewPointMethodBisection.h \
    headers/NewPointMethodLeppBisection.h \
    headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h \
    headers/TriangleSelectionSmallestEdge.h \
    headers/TriangleSelectionSmallestInternalAngle.h \
    headers/FactoryInsertionMethod.h \
    headers/RefineProcess.h \
    headers/InsideInsertionBasic.h \
    headers/NewPointMethodRuppert.h \
    headers/NewPointMethodLeppCentroid.h \
    headers/NewPointMethodUngor.h \
    headers/Util.h \
    headers/PreProcessFixEncroachedVertexs.h \
    headers/NewPointMethodLeppCircumcenter.h \
    headers/TriangleSelectionSmallestCircumradius.h \
    headers/NewPointMethodLeppDelaunay.h \
    headers/TriangleSelectionLongEdgeOnlyBorder.h \
    headers/TriangleSelectionNoPriority.h
FORMS += forms/MainWindow.ui \
    forms/LoadMeshDialog.ui
SOURCES += sources/Vertex.cpp \
    sources/Triangle.cpp \
    sources/Mesh.cpp \
    sources/MainWindow.cpp \
    sources/main.cpp \
    sources/LoadMeshDialog.cpp \
    sources/GLWidget.cpp \
    sources/Point.cpp \
    sources/RefineProcess.cpp \
    sources/FactoryPreProcess.cpp \
    sources/FactoryTriangleSelection.cpp \
    sources/Options.cpp \
    sources/FactoryNewPointMethod.cpp \
    sources/Configuration.cpp \
    sources/FactoryInsertionMethod.cpp \
    sources/PreProcessNone.cpp \
    sources/TriangleSelectionSmallestInternalAngle.cpp \
    sources/TriangleSelectionSmallestEdgeBorderTriangleFirst.cpp \
    sources/TriangleSelectionSmallestEdge.cpp \
    sources/NewPointMethodBisection.cpp \
    sources/InsideInsertionBasic.cpp \
    sources/InsideInsertion.cpp \
    sources/InsideInsertionFlipDiagonal.cpp \
    sources/NewPointMethodRuppert.cpp \
    sources/PreProcessFixEncroachedVertexs.cpp \
    sources/NewPointMethodLeppBisection.cpp \
    sources/NewPointMethodLeppCircumcenter.cpp \
    sources/NewPointMethodUngor.cpp \
    sources/TriangleSelectionSmallestCircumradius.cpp \
    sources/NewPointMethodLeppDelaunay.cpp \
    sources/Constant.cpp \
    sources/InsideInsertionCavity.cpp \
    sources/TriangleSelectionLongEdgeOnlyBorder.cpp \
    sources/NewPointMethodLeppCentroid.cpp \
    sources/TriangleSelectionNoPriority.cpp
