#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "src/lib/gui/headers/GLWidget.h"
#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/refinement/headers/Options.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend void *ptest(void*);
    MainWindow(QWidget *parent = 0);
    void enableControl(bool active);
    void setManual(bool manual);
    void setScale(double scale);
    void setCenter(Point* center);
    void updateInfo();
    void updateControl();
    void addInfo(Options* options);
    Options* getOptions();
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    GLWidget *glWidget;

private slots:
    void on_automaticTriangleSelectionDoubleSpinBox_editingFinished();
    void on_yTranslateDoubleSpinBox_editingFinished();
    void on_xTranslateDoubleSpinBox_editingFinished();
    void on_scaleSpinBox_editingFinished();
    void on_manualRadioButton_clicked();
    void on_automaticRadioButton_clicked();
    void on_actionLoad_triggered();
    void on_actionReload_triggered();
    void on_refineOnceButton_clicked();
    void on_refineButton_clicked();
};

#endif // MAINWINDOW_H
