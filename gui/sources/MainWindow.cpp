#include <QFileDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "headers/MainWindow.h"
#include "headers/Mesh.h"
#include "headers/Options.h"
#include "headers/RefineProcess.h"
#include <pthread.h>

//! [0]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->glWidget = new GLWidget(this);
    ui->glLayout->addWidget( glWidget );
    this->mesh = new Mesh("../data/b.mesh");
    this->mesh->setValue(this->ui->automaticTriangleSelectionDoubleSpinBox->value());
    this->updateInfo();
    this->enableControl(true);
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

void MainWindow::setManual(bool manual){
    this->ui->automaticRadioButton->setChecked(!manual);
    this->ui->manualRadioButton->setChecked(manual);
}

void MainWindow::setScale(double scale){
    this->ui->scaleSpinBox->setValue(scale);
}

void MainWindow::setCenter(Point *center){
    this->ui->xTranslateDoubleSpinBox->setValue(center->x());
    this->ui->yTranslateDoubleSpinBox->setValue(center->y());
}

void MainWindow::updateInfo(){
    if(this->mesh != 0){
        QString t   = QString::number(this->mesh->trianglesSize());
        QString v   = QString::number(this->mesh->vertexsSize());
        QString a   = QString::number(this->mesh->minAngle());
        this->ui->infoTextEdit->append("<strong>&Aacute;ngulo M&iacute;nimo:</strong> " + a + "<br /><strong>Tri&aacute;ngulos:</strong> " + t + "<br /><strong>V&eacute;rtices:</strong> " + v);
    }
    else{
        this->ui->infoTextEdit->append("No hay malla cargada");
    }
    this->ui->infoTextEdit->append("===============<br />");
}

//! [4]
void MainWindow::on_actionLoad_triggered()
{
    if( this->mesh == 0 || mesh->isVirgin()){
        QString filepath = QFileDialog::getOpenFileName(this, "Open Mesh...", "../data");
        if(!filepath.isEmpty()){
            this->ui->infoTextEdit->append("<strong>Opening:</strong> <code>" + filepath + "</code>");
            this->mesh = new Mesh(filepath);
            if(this->mesh != 0 && 0 < this->mesh->trianglesSize()){
                this->enableControl(true);
                this->glWidget->updateGL();
            }
            this->ui->infoTextEdit->append("===============<br />");
            this->updateInfo();
        }
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
    ret->setTriangleSelectionValue(this->ui->automaticTriangleSelectionDoubleSpinBox->value());
    ret->setNewPointMethod(this->ui->newPointMethodComboBox->currentIndex());
    ret->setInsideInsertion(this->ui->insideNewPointCaseComboBox->currentIndex());
    ret->setRepeatLastSelectedTriangle(this->ui->repeatSelectedTriangleCheckBox->isChecked());
    ret->setAutomatic(this->ui->automaticRadioButton->isChecked());
    return ret;
}

void MainWindow::enableControl(bool active){
    this->ui->refineOnceButton->setEnabled(active);
    this->ui->refineButton->setEnabled(active);
    this->ui->stopButton->setEnabled(!active);
    this->ui->automaticRadioButton->setEnabled(active);
    this->ui->manualRadioButton->setEnabled(active);
}

void MainWindow::addInfo(Options* options){
    if(!options->onlyFirstPreProcess() || ( options->onlyFirstPreProcess() && this->mesh->isVirgin() ))
        this->ui->infoTextEdit->append("<strong>Pre-proceso:</strong>: " + QString(Constant::preProcessNames[options->preProcess()]) + "<br />");
    if(options->automatic())
        this->ui->infoTextEdit->append("<strong>Selecci&oacute;n Tri&aacute;ngulo:</strong> " + QString(Constant::triangleSelectionNames[options->triangleSelection()]) + "<br />");
    else
        this->ui->infoTextEdit->append("Selecci&oacute;n Manual<br />");
    this->ui->infoTextEdit->append("<strong>&Aacute;ngulo exigido:</strong> " + QString::number(options->triangleSelectionValue()) + "&deg;<br />");
    this->ui->infoTextEdit->append("<strong>Nuevo Punto:</strong> " + QString(Constant::newPointNames[options->newPointMethod()]) + "<br />");
    this->ui->infoTextEdit->append("<strong>Tipo Inserci&oacute;n:</strong> " + QString(Constant::insertionNames[options->insideInsertion()]) + "<br />");
}


//! [5]
void MainWindow::on_refineOnceButton_clicked()
{
    try{
        this->enableControl(false);
        Options* options = this->getOptions();
        this->addInfo(options);
        RefineProcess::refine(mesh, options);
        this->glWidget->updateGL();
        this->enableControl(true);
        this->updateInfo();
    }
    catch(QString e){
        qDebug(e.toUtf8());
    }
}
//! [5]


void MainWindow::test()
{
    try{
        bool go = true;
        this->enableControl(false);
        Options* options = this->getOptions();
        this->addInfo(options);
        while(go){
            go = RefineProcess::refine(mesh, options);
            //this->glWidget->updateGL();
        }
        this->enableControl(true);
        //this->glWidget->updateGL();
        this->updateInfo();
    }
    catch(QString e){
        qDebug(e.toUtf8());
    }
}

void *ptest(void* ptr){
    static_cast<MainWindow*>(ptr)->test();
}

void MainWindow::on_refineButton_clicked()
{
    try{
//        this->enableControl(false);
//        pthread_t refine;
//        int iret1 = pthread_create( &refine, NULL, ptest, (void*)this);

        bool go = true;
        this->enableControl(false);
        Options* options = this->getOptions();
        this->addInfo(options);
        while(go){
            go = RefineProcess::refine(mesh, options);
            this->glWidget->updateGL();
        }
        this->enableControl(true);
        this->glWidget->updateGL();
        this->updateInfo();
    }
    catch(QString e){
        qDebug(e.toUtf8());
    }
}


//! [6]
void MainWindow::on_automaticRadioButton_clicked(){
    this->setManual(false);
    this->ui->refineButton->setEnabled(true);
}
//! [6]

//! [7]
void MainWindow::on_manualRadioButton_clicked(){
    this->setManual(true);
    this->ui->stopButton->setEnabled(false);
    this->ui->refineButton->setEnabled(false);
}
//! [7]

//! [8]
void MainWindow::on_scaleSpinBox_editingFinished(){
    if(this->mesh != 0)
        this->mesh->setScale(this->ui->scaleSpinBox->value());
    this->glWidget->updateGL();
}
//! [8]

//! [9]
void MainWindow::on_xTranslateDoubleSpinBox_editingFinished(){
    if(this->mesh != 0){
        this->mesh->setXCenter(this->ui->xTranslateDoubleSpinBox->value());
    }
    this->glWidget->updateGL();
}
//! [9]

//! [10]
void MainWindow::on_yTranslateDoubleSpinBox_editingFinished(){
    if(this->mesh != 0){
        this->mesh->setYCenter(this->ui->yTranslateDoubleSpinBox->value());
    }
    this->glWidget->updateGL();
}
//! [10]


void MainWindow::on_automaticTriangleSelectionDoubleSpinBox_editingFinished(){
    this->mesh->setValue(this->ui->automaticTriangleSelectionDoubleSpinBox->value());
    this->glWidget->updateGL();
}
