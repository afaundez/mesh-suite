#include "mainwindow.h"
#include "ui_mainwindow.h"

//! [0]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glWidget = new GLWidget(parent);
    ui->glLayout->addWidget( glWidget );
}
//! [0]

//! [1]
MainWindow::~MainWindow()
{
    delete ui;
}
//! [1]

//! [2]
void MainWindow::on_pushButton_clicked()
{
    glWidget->updateGL();
}
//! [2]
