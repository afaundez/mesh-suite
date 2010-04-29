# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = ../MeshSuite
TEMPLATE = app
SOURCES += source/main.cpp \
    source/mainwindow.cpp \
    source/Vertex.cpp \
    source/Triangle.cpp \
    source/Mesh.cpp \
    source/loadmesh.cpp \
    source/glwidget.cpp
HEADERS += headers/mainwindow.h \
    headers/glwidget.h \
    headers/Mesh.h \
    headers/Triangle.h \
    headers/Vertex.h \
    headers/loadmesh.h \
    headers/QualityCriterionFactory.h \
    headers/PreProcessCriterionFactory.h \
    headers/InsertionSelectionFactory.h \
    headers/RegularInsertionFactory.h \
    headers/BorderInsertionFactory.h \
    headers/RestrictedInsertionFactory.h \
    headers/InsertionMethodFactory.h \
    headers/QualityCriterion.h \
    headers/ui_mainwindow.h \
    headers/ui_loadmesh.h \
    headers/QualityCriterion.h
FORMS += forms/mainwindow.ui \
    forms/loadmesh.ui
