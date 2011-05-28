# -------------------------------------------------
# Project created by QtCreator 2010-04-14T15:48:19
# -------------------------------------------------
QT += opengl
TARGET = mesh_suite
TEMPLATE = app
HEADERS += \
   lib/gui/MainWindow.h \
   lib/gui/LoadMeshDialog.h \
   lib/gui/GLWidget.h \
   lib/geometric/Mesh.h \
   lib/geometric/Triangle.h \
   lib/geometric/Vertex.h \
   lib/geometric/Point.h \
   lib/refinement/Configuration.h \
   lib/refinement/Options.h \
   lib/refinement/Constant.h \
   lib/refinement/RefineProcess.h \
   lib/refinement/Util.h \
   lib/refinement/insertion/FactoryInsertionMethod.h \
   lib/refinement/insertion/InsideInsertion.h \
   lib/refinement/insertion/InsertionMethod.h \
   lib/refinement/insertion/InsideInsertionFlipDiagonal.h \
   lib/refinement/new_point/FactoryNewPointMethod.h \
   lib/refinement/new_point/NewPointMethod.h \
   lib/refinement/new_point/NewPointMethodBisection.h \
   lib/refinement/new_point/NewPointMethodLeppBisection.h \
   lib/refinement/new_point/NewPointMethodRuppert.h \
   lib/refinement/new_point/NewPointMethodLeppCentroid.h \
   lib/refinement/new_point/NewPointMethodUngor.h \
   lib/refinement/new_point/NewPointMethodLeppCircumcenter.h \
   lib/refinement/new_point/NewPointMethodLeppDelaunay.h \
   lib/refinement/triangle_selection/FactoryTriangleSelection.h \
   lib/refinement/triangle_selection/TriangleSelection.h \
   lib/refinement/triangle_selection/TriangleSelectionSmallestEdgeBorderTriangleFirst.h \
   lib/refinement/triangle_selection/TriangleSelectionSmallestEdge.h \
   lib/refinement/triangle_selection/TriangleSelectionSmallestInternalAngle.h \
   lib/refinement/triangle_selection/TriangleSelectionSmallestCircumradius.h \
   lib/refinement/triangle_selection/TriangleSelectionLongEdgeOnlyBorder.h \
   lib/refinement/triangle_selection/TriangleSelectionNoPriority.h
FORMS += \
   forms/MainWindow.ui \
   forms/LoadMeshDialog.ui
SOURCES += \
   lib/gui/main.cpp \
   lib/gui/MainWindow.cpp \
   lib/gui/LoadMeshDialog.cpp \
   lib/gui/GLWidget.cpp \
   lib/geometric/Mesh.cpp \
   lib/geometric/Point.cpp \
   lib/geometric/Triangle.cpp \
   lib/geometric/Vertex.cpp \
   lib/refinement/RefineProcess.cpp \
   lib/refinement/Options.cpp \
   lib/refinement/Configuration.cpp \
   lib/refinement/Constant.cpp \
   lib/refinement/insertion/FactoryInsertionMethod.cpp \
   lib/refinement/insertion/InsideInsertion.cpp \
   lib/refinement/insertion/InsideInsertionFlipDiagonal.cpp \
   lib/refinement/new_point/FactoryNewPointMethod.cpp \
   lib/refinement/new_point/NewPointMethodBisection.cpp \
   lib/refinement/new_point/NewPointMethodRuppert.cpp \
   lib/refinement/new_point/NewPointMethodLeppBisection.cpp \
   lib/refinement/new_point/NewPointMethodLeppCircumcenter.cpp \
   lib/refinement/new_point/NewPointMethodUngor.cpp \
   lib/refinement/new_point/NewPointMethodLeppDelaunay.cpp \
   lib/refinement/new_point/NewPointMethodLeppCentroid.cpp \
   lib/refinement/triangle_selection/FactoryTriangleSelection.cpp \
   lib/refinement/triangle_selection/TriangleSelectionSmallestInternalAngle.cpp \
   lib/refinement/triangle_selection/TriangleSelectionSmallestEdgeBorderTriangleFirst.cpp \
   lib/refinement/triangle_selection/TriangleSelectionSmallestEdge.cpp \
   lib/refinement/triangle_selection/TriangleSelectionSmallestCircumradius.cpp \
   lib/refinement/triangle_selection/TriangleSelectionLongEdgeOnlyBorder.cpp \
   lib/refinement/triangle_selection/TriangleSelectionNoPriority.cpp
