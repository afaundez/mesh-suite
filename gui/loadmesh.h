#ifndef LOADMESH_H
#define LOADMESH_H

#include <QtGui/QDialog>

namespace Ui {
    class LoadMesh;
}

class LoadMesh : public QDialog {
    Q_OBJECT
public:
    LoadMesh(QWidget *parent = 0);
    ~LoadMesh();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LoadMesh *m_ui;
};

#endif // LOADMESH_H
