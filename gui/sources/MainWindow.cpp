#include <QFileDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "headers/MainWindow.h"
#include "headers/Mesh.h"
#include "headers/InsertionType.h"
#include "headers/InsertionTypeFactory.h"
#include "headers/InsertionMethod.h"
#include "headers/InsertionMethodFactory.h"

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
    InsertionType* it = InsertionTypeFactory::build(ui->insertionTypeComboBox->currentIndex());
    InsertionMethod* iim = InsertionMethodFactory::build(Constant::INSIDE, ui->insideInsertionMethodComboBox->currentIndex());
    InsertionMethod* bim = InsertionMethodFactory::build(Constant::ON_BORDER, ui->borderInsertionMethodComboBox->currentIndex());
    InsertionMethod* rim = InsertionMethodFactory::build(Constant::RESTRICTED, ui->restrictedInsertionMethodComboBox->currentIndex());

}
//! [5]
