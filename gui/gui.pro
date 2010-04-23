# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = gui
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    glwidget.cpp \
    Vertex.cpp \
    Triangle.cpp \
    Mesh.cpp \
    loadmesh.cpp
HEADERS += mainwindow.h \
    glwidget.h \
    Mesh.h \
    Triangle.h \
    Vertex.h \
    loadmesh.h \
    QualityCriterionFactory.h \
    PreProcessCriterionFactory.h \
    InsertionSelectionFactory.h \
    RegularInsertionFactory.h \
    BorderInsertionFactory.h \
    RestrictedInsertionFactory.h \
    InsertionMethodFactory.h
FORMS += mainwindow.ui \
    loadmesh.ui
