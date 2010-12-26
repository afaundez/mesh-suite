#include "lib/headers/LoadMeshDialog.h"
#include "ui_LoadMeshDialog.h"

LoadMesh::LoadMesh(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::LoadMesh)
{
    m_ui->setupUi(this);
}

LoadMesh::~LoadMesh()
{
    delete m_ui;
}

void LoadMesh::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
