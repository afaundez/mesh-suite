/********************************************************************************
** Form generated from reading UI file 'LoadMeshDialog.ui'
**
** Created: Sat May 28 19:41:57 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADMESHDIALOG_H
#define UI_LOADMESHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_LoadMesh
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LoadMesh)
    {
        if (LoadMesh->objectName().isEmpty())
            LoadMesh->setObjectName(QString::fromUtf8("LoadMesh"));
        LoadMesh->resize(400, 300);
        buttonBox = new QDialogButtonBox(LoadMesh);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(LoadMesh);
        QObject::connect(buttonBox, SIGNAL(accepted()), LoadMesh, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LoadMesh, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoadMesh);
    } // setupUi

    void retranslateUi(QDialog *LoadMesh)
    {
        LoadMesh->setWindowTitle(QApplication::translate("LoadMesh", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadMesh: public Ui_LoadMesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADMESHDIALOG_H
