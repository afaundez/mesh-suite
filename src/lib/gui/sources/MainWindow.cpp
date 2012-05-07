#include <QFileDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "src/lib/gui/headers/MainWindow.h"
#include "src/lib/geometric/headers/Mesh.h"
#include "src/lib/refinement/headers/Options.h"
#include "src/lib/refinement/headers/RefineProcess.h"

//! [0]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->glWidget = new GLWidget(this);
    ui->glLayout->addWidget( glWidget );
    // TODO: check this seg fault
    this->enableControl(true);

    // Total running time of algorithm is shown only when refineButton is clicked
    refineButtonClicked = false;
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
        QString time = QString::number(timeval_diff(NULL,&later,&earlier)/1000);
        if(refineButtonClicked)
            this->ui->infoTextEdit->append("<strong>Angulo Minimo:</strong> " + a + "<br /><strong>Triangulos:</strong> " + t + "<br /><strong>Vertices:</strong> " + v + "<br /><strong>Tiempo:</strong> " + time +  " ms");
        else
            this->ui->infoTextEdit->append("<strong>Angulo Minimo:</strong> " + a + "<br /><strong>Triangulos:</strong> " + t + "<br /><strong>Vertices:</strong> " + v);
        refineButtonClicked = false;
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
    this->updateControl();
    this->glWidget->updateGL();
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
    if(this->ui->automaticRadioButton->isChecked())
        this->ui->refineButton->setEnabled(active);
    this->ui->stopButton->setEnabled(!active);
    this->ui->automaticRadioButton->setEnabled(active);
    this->ui->manualRadioButton->setEnabled(active);
}

void MainWindow::addInfo(Options* options){
    Mesh* mesh = RefineProcess::getInstance().mesh();
    if(!options->onlyFirstPreProcess() || ( options->onlyFirstPreProcess() && mesh->isVirgin() ))
        this->ui->infoTextEdit->append("<strong>Pre-proceso:</strong>: " + QString(Constant::preProcessNames[options->preProcess()]) + "<br />");
    if(options->automatic())
        this->ui->infoTextEdit->append("<strong>Seleccion Triangulo:</strong> " + QString(Constant::triangleSelectionNames[options->triangleSelection()]) + "<br />");
    else
        this->ui->infoTextEdit->append("Seleccion Manual<br />");
    this->ui->infoTextEdit->append("<strong>Angulo exigido:</strong> " + QString::number(options->triangleSelectionValue()) + "&deg;<br />");
    this->ui->infoTextEdit->append("<strong>Nuevo Punto:</strong> " + QString(Constant::newPointNames[options->newPointMethod()]) + "<br />");
    this->ui->infoTextEdit->append("<strong>Tipo Insercion:</strong> " + QString(Constant::insertionNames[options->insideInsertion()]) + "<br />");
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
        refineButtonClicked = true;
        bool go = true;
        this->enableControl(false);
        Options* options = this->getOptions();
        this->addInfo(options);

        gettimeofday(&earlier,NULL); int i=0;
        while(go){
            go = RefineProcess::getInstance().refine(options);
            this->glWidget->updateGL();
        }
        gettimeofday(&later,NULL);

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
