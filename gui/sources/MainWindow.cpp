#include <QFileDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "headers/MainWindow.h"
#include "headers/Mesh.h"
#include "headers/InsertionType.h"
#include "headers/InsertionTypeFactory.h"
#include "headers/InsertionMethod.h"
#include "headers/InsertionMethodFactory.h"
#include "headers/TriangleSelection.h"
#include "headers/TriangleSelectionFactory.h"
#include "headers/PreProcessFactory.h"

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
    if( this->mesh == 0){
        this->mesh = new Mesh(QFileDialog::getOpenFileName());

        this->glWidget->updateGL();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("La malla ha sido modificada");
        msgBox.setInformativeText("Desea guardar los cambios?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
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

//! [5]
void MainWindow::on_refineOnce_clicked()
{
    qDebug("MainWindow::on_refineOnce_clicked()");
    Triangle* A;

    // SELECT TRIANGLE
    if(ui->manualRadioButton->isChecked()){
        A = this->mesh->getSelectedTriangle();
    }
    else if (ui->automaticRadioButton->isChecked()){
        // TODO: implement triangle selection methods
        A = TriangleSelectionFactory::build((Constant::TriangleSelectionType)this->ui->automaticTriangleSelectionComboBox->currentIndex())->process(this->mesh, this->ui->automaticTriangleSelectionSpinBox->value());
    }
    // PRE PROCESS
    bool onlyFirst = this->ui->preProcessCheckBox->isChecked();
    if( !onlyFirst || (onlyFirst && this->mesh->isVirgin()) )
        PreProcessFactory::build((Constant::PreProcessType)this->ui->preProcessComboBox->currentIndex())->execute();

    // PROCESS
    if( A != 0){
        InsertionType* it = InsertionTypeFactory::build(ui->insertionTypeComboBox->currentIndex());
        InsertionMethod* iim = InsertionMethodFactory::build(Constant::INSIDE, ui->insideInsertionMethodComboBox->currentIndex());
        InsertionMethod* bim = InsertionMethodFactory::build(Constant::ON_BORDER, ui->borderInsertionMethodComboBox->currentIndex());
        InsertionMethod* rim = InsertionMethodFactory::build(Constant::RESTRICTED, ui->restrictedInsertionMethodComboBox->currentIndex());
        this->mesh->removeAndDeleteTriangle(A);
        this->mesh->setSelectedTriangle(0);
    }


    this->glWidget->updateGL();

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
