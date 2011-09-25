#include <QFileDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "lib/gui/MainWindow.h"
#include "lib/geometric/Mesh.h"
#include "lib/refinement/Options.h"
#include "lib/refinement/RefineProcess.h"

//! [0]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->glWidget = new GLWidget(this);
    ui->glLayout->addWidget( glWidget );
    // TODO: check this seg fault
    this->disableControl();
}
//! [0]

void MainWindow::updateControl(){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    // TODO: do this in other way mesh update
    mesh->setValue(this->ui->automaticTriangleSelectionDoubleSpinBox->value());
    this->ui->scaleSpinBox->setValue(mesh->scale());
    this->ui->xTranslateDoubleSpinBox->setValue(mesh->center()->x());
    this->ui->yTranslateDoubleSpinBox->setValue(mesh->center()->y());
}

//! [1]
MainWindow::~MainWindow()
{
    delete ui;
}
//! [1]

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
    // TODO: get info from refinement process
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if(mesh != 0){
        QString t   = QString::number(mesh->trianglesSize());
        QString v   = QString::number(mesh->vertexsSize());
        QString a   = QString::number(mesh->minAngle());
        this->ui->infoTextEdit->append("<strong>&Aacute;ngulo M&iacute;nimo:</strong> " + a + "<br /><strong>Tri&aacute;ngulos:</strong> " + t + "<br /><strong>V&eacute;rtices:</strong> " + v);
    }
    else{
        this->ui->infoTextEdit->append("No hay malla cargada");
    }
    this->ui->infoTextEdit->append("===============<br />");
}

void MainWindow::on_actionReload_triggered(){
    RefineProcess::getInstance().reloadMesh();
    RefineProcess::getInstance().mesh()->scale(this->glWidget->width(),this->glWidget->height());
    this->updateControl();
    this->glWidget->updateGL();
}

//! [4]
void MainWindow::on_actionLoad_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Mesh...", "../data");
    RefineProcess::getInstance().loadMesh(filePath);
    RefineProcess::getInstance().mesh()->scale(this->glWidget->width(),this->glWidget->height());
    this->enableControl(true);
    this->updateControl();
    this->glWidget->updateGL();
}
//! [4]

Options* MainWindow::getOptions(){
    Options* ret =  new Options();
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
    if(this->ui->automaticRadioButton->isChecked())
        this->ui->refineButton->setEnabled(active);
    this->ui->stopButton->setEnabled(!active);
    this->ui->automaticRadioButton->setEnabled(active);
    this->ui->manualRadioButton->setEnabled(active);
}

void MainWindow::disableControl(){
    this->ui->refineOnceButton->setEnabled(false);
    if(this->ui->automaticRadioButton->isChecked())
        this->ui->refineButton->setEnabled(false);
    this->ui->stopButton->setEnabled(false);
    this->ui->automaticRadioButton->setEnabled(false);
    this->ui->manualRadioButton->setEnabled(false);
}

void MainWindow::addInfo(Options* options){
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
        RefineProcess::getInstance().refine(options);
        this->glWidget->updateGL();
        this->enableControl(true);
        this->updateInfo();
    }
    catch(QString e){
        qDebug(e.toUtf8());
    }
}
//! [5]

void MainWindow::on_refineButton_clicked()
{
    try{
        bool go = true;
        this->enableControl(false);
        Options* options = this->getOptions();
        this->addInfo(options);
        while(go){
            go = RefineProcess::getInstance().refine(options);
            this->glWidget->updateGL();
        }
        this->enableControl(true);
        this->glWidget->updateGL();
        this->updateInfo();
    }
    catch(QString e){
        qDebug(e.toUtf8());
        this->enableControl(true);
        this->glWidget->updateGL();
        this->updateInfo();
        return;
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
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if(mesh != 0)
        mesh->setScale(this->ui->scaleSpinBox->value());
    this->glWidget->updateGL();
}
//! [8]

//! [9]
void MainWindow::on_xTranslateDoubleSpinBox_editingFinished(){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if(mesh != 0){
        mesh->setXCenter(this->ui->xTranslateDoubleSpinBox->value());
    }
    this->glWidget->updateGL();
}
//! [9]

//! [10]
void MainWindow::on_yTranslateDoubleSpinBox_editingFinished(){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if(mesh != 0){
        mesh->setYCenter(this->ui->yTranslateDoubleSpinBox->value());
    }
    this->glWidget->updateGL();
}
//! [10]


void MainWindow::on_automaticTriangleSelectionDoubleSpinBox_editingFinished(){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    mesh->setValue(this->ui->automaticTriangleSelectionDoubleSpinBox->value());
    this->glWidget->updateGL();
}
