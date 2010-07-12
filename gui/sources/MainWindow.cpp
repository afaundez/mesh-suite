#include <QFileDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "headers/MainWindow.h"
#include "headers/Mesh.h"
#include "headers/Options.h"
#include "headers/RefineProcess.h"

//! [0]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->glWidget = new GLWidget(this);
    ui->glLayout->addWidget( glWidget );
    this->mesh = 0;
}
//! [0]

//! [1]
MainWindow::~MainWindow()
{
    delete ui;
}
//! [1]

//! [3]
Mesh* MainWindow::getMesh(){
    return this->mesh;
}
//! [3]

//! [4]
void MainWindow::on_actionLoad_triggered()
{
    if( this->mesh == 0 || mesh->isVirgin()){
        this->mesh = new Mesh(QFileDialog::getOpenFileName());
        if(this->mesh != 0 && 0 < this->mesh->trianglesSize()){
            this->ui->refineOnceButton->setEnabled(true);
            this->ui->refineButton->setEnabled(true);
            this->ui->unRefineOnceButton->setEnabled(true);
            this->ui->stopButton->setEnabled(false);
        }
        this->glWidget->updateGL();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("La malla ha sido modificada");
        msgBox.setInformativeText("Desea guardar los cambios?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setButtonText(QMessageBox::Save, "Guardar Cambios");
        msgBox.setButtonText(QMessageBox::Discard, "Descartar cambios");
        msgBox.setButtonText(QMessageBox::Cancel, "Cancelar");
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch(ret){
        case QMessageBox::Save:
        case QMessageBox::Discard:
            delete this->mesh;
            this->mesh = new Mesh(QFileDialog::getOpenFileName());
            this->glWidget->updateGL();
            break;
        case QMessageBox::Cancel:
        default:
            break;
        }
    }
    return;
}
//! [4]

Options* MainWindow::getOptions(){
    Options* ret =  new Options();
    ret->setOnlyFirstPreProcess(this->ui->preProcessCheckBox->isChecked());
    ret->setPreProcess(this->ui->preProcessComboBox->currentIndex());
    ret->setTriangleSelection(this->ui->automaticTriangleSelectionComboBox->currentIndex());
    ret->setTriangleSelectionValue(this->ui->automaticTriangleSelectionSpinBox->value());
    ret->setNewPointMethod(this->ui->newPointMethodComboBox->currentIndex());
    ret->setOutsideNewPointMethod(this->ui->outsideNewPointCaseComboBox->currentIndex());
    ret->setOneEdgeRestrictedInsertion(this->ui->oneRestrictedNewPointCaseComboBox->currentIndex());
    ret->setTwoEdgeRestrictedInsertion(this->ui->twoRestrictedNewPointCaseComboBox->currentIndex());
    ret->setThreeEdgeRestrictedInsertion(this->ui->threeRestrictedNewPointCaseComboBox->currentIndex());
    return ret;
}

//! [5]
void MainWindow::on_refineOnce_clicked()
{
    this->ui->refineOnceButton->setEnabled(false);
    this->ui->refineButton->setEnabled(false);
    this->ui->unRefineOnceButton->setEnabled(false);
    this->ui->stopButton->setEnabled(true);
    qDebug("MainWindow::on_refineOnce_clicked()");
    Options* options;
    // GET OPTIONS
    qDebug("Getting GUI selected options...");
    options = this->getOptions();
    try{
        // REFINE
        qDebug("Refining...");
        RefineProcess::refine(mesh, options);
    }
    catch (...)
    {
        qDebug("An exception occurred");
    }
    this->glWidget->updateGL();

    this->ui->refineOnceButton->setEnabled(true);
    this->ui->refineButton->setEnabled(true);
    this->ui->unRefineOnceButton->setEnabled(true);
    this->ui->stopButton->setEnabled(false);

}
//! [5]

//! [6]
void MainWindow::on_automaticRadioButton_clicked(){
    ui->automaticTriangleSelectionComboBox->setEnabled(true);
    ui->automaticTriangleSelectionSpinBox->setEnabled(true);
}
//! [6]

//! [7]
void MainWindow::on_manualRadioButton_clicked(){
    ui->automaticTriangleSelectionComboBox->setEnabled(false);
    ui->automaticTriangleSelectionSpinBox->setEnabled(false);
}
//! [7]
