#include <QFileDialog>
#include <QMessageBox>
#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/Mesh.h"

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

    }
    return;
}

void MainWindow::on_pushButton_2_clicked()
{

}
