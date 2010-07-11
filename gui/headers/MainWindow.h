#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "GLWidget.h"
#include "Mesh.h"
#include "Options.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    Mesh* getMesh();
    Options* getOptions();
    ~MainWindow();


private:
    QString currentMesh;
    Mesh* mesh;
    Ui::MainWindow *ui;
    GLWidget::GLWidget *glWidget;

private slots:
    void on_manualRadioButton_clicked();
    void on_automaticRadioButton_clicked();
    void on_refineOnce_clicked();
    void on_actionLoad_triggered();
};

#endif // MAINWINDOW_H
