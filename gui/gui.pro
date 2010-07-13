# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = ../MeshSuite
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
    headers/PreProcessEdgeDiameterCircle.h \
    headers/InsideInsertionCavity.h \
    headers/InsideInsertionFlipDiagonal.h \
    headers/InsertionMethod.h \
    headers/NewPointMethodBisection.h \
    headers/NewPointMethodLeppBisection.h \
    headers/NewPointMethodCircumcenter.h \
    headers/TriangleSelectionSmallestEdgeBorderTriangleFirst.h \
    headers/TriangleSelectionSmallestEdge.h \
    headers/TriangleSelectionSmallestInternalAngle.h \
    headers/FactoryInsertionMethod.h \
    headers/RefineProcess.h \
    headers/InsideInsertionBasic.h
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
    sources/PreProcessEdgeDiameterCircle.cpp \
    sources/TriangleSelectionSmallestInternalAngle.cpp \
    sources/TriangleSelectionSmallestEdgeBorderTriangleFirst.cpp \
    sources/TriangleSelectionSmallestEdge.cpp \
    sources/NewPointMethodBisection.cpp \
    sources/InsideInsertionBasic.cpp \
    sources/InsideInsertion.cpp \
    sources/NewPointMethodCircumcenter.cpp \
    sources/InsideInsertionFlipDiagonal.cpp
