/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Sat May 28 19:41:57 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionLoad;
    QAction *actionReload;
    QAction *actionSaveAs;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QFrame *viewerFrame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *glLayout;
    QSpacerItem *verticalSpacer;
    QFrame *controlFrame;
    QVBoxLayout *verticalLayout;
    QLabel *infoControl;
    QHBoxLayout *horizontalLayout_3;
    QLabel *scaleLabel;
    QDoubleSpinBox *scaleSpinBox;
    QLabel *openCenterLavel;
    QDoubleSpinBox *xTranslateDoubleSpinBox;
    QLabel *commaCenterLabel;
    QDoubleSpinBox *yTranslateDoubleSpinBox;
    QLabel *closeCenterLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *selectionTriangleLabel;
    QRadioButton *manualRadioButton;
    QRadioButton *automaticRadioButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *stopButton;
    QPushButton *refineOnceButton;
    QPushButton *refineButton;
    QFrame *optionFrame;
    QVBoxLayout *verticalLayout_3;
    QToolBox *optionToolBox;
    QWidget *triangleSelectPage;
    QFormLayout *formLayout_5;
    QLabel *label_2;
    QDoubleSpinBox *automaticTriangleSelectionDoubleSpinBox;
    QLabel *label_3;
    QCheckBox *repeatSelectedTriangleCheckBox;
    QComboBox *automaticTriangleSelectionComboBox;
    QWidget *newPointPage;
    QFormLayout *formLayout_3;
    QLabel *label;
    QComboBox *newPointMethodComboBox;
    QWidget *insertionPage;
    QFormLayout *formLayout;
    QComboBox *insideNewPointCaseComboBox;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *infoTextEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuMesh;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1118, 662);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        viewerFrame = new QFrame(centralWidget);
        viewerFrame->setObjectName(QString::fromUtf8("viewerFrame"));
        viewerFrame->setFrameShape(QFrame::StyledPanel);
        viewerFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(viewerFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        glLayout = new QHBoxLayout();
        glLayout->setSpacing(6);
        glLayout->setObjectName(QString::fromUtf8("glLayout"));

        gridLayout_2->addLayout(glLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout_4->addWidget(viewerFrame, 0, 0, 6, 1);

        controlFrame = new QFrame(centralWidget);
        controlFrame->setObjectName(QString::fromUtf8("controlFrame"));
        controlFrame->setFrameShape(QFrame::StyledPanel);
        controlFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(controlFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoControl = new QLabel(controlFrame);
        infoControl->setObjectName(QString::fromUtf8("infoControl"));

        verticalLayout->addWidget(infoControl);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scaleLabel = new QLabel(controlFrame);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));

        horizontalLayout_3->addWidget(scaleLabel);

        scaleSpinBox = new QDoubleSpinBox(controlFrame);
        scaleSpinBox->setObjectName(QString::fromUtf8("scaleSpinBox"));
        scaleSpinBox->setDecimals(6);
        scaleSpinBox->setMinimum(1e-06);
        scaleSpinBox->setMaximum(1e+09);
        scaleSpinBox->setSingleStep(0.5);
        scaleSpinBox->setValue(1);

        horizontalLayout_3->addWidget(scaleSpinBox);

        openCenterLavel = new QLabel(controlFrame);
        openCenterLavel->setObjectName(QString::fromUtf8("openCenterLavel"));

        horizontalLayout_3->addWidget(openCenterLavel);

        xTranslateDoubleSpinBox = new QDoubleSpinBox(controlFrame);
        xTranslateDoubleSpinBox->setObjectName(QString::fromUtf8("xTranslateDoubleSpinBox"));
        xTranslateDoubleSpinBox->setDecimals(6);
        xTranslateDoubleSpinBox->setMinimum(-1e+09);
        xTranslateDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_3->addWidget(xTranslateDoubleSpinBox);

        commaCenterLabel = new QLabel(controlFrame);
        commaCenterLabel->setObjectName(QString::fromUtf8("commaCenterLabel"));

        horizontalLayout_3->addWidget(commaCenterLabel);

        yTranslateDoubleSpinBox = new QDoubleSpinBox(controlFrame);
        yTranslateDoubleSpinBox->setObjectName(QString::fromUtf8("yTranslateDoubleSpinBox"));
        yTranslateDoubleSpinBox->setDecimals(6);
        yTranslateDoubleSpinBox->setMinimum(-1e+09);
        yTranslateDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_3->addWidget(yTranslateDoubleSpinBox);

        closeCenterLabel = new QLabel(controlFrame);
        closeCenterLabel->setObjectName(QString::fromUtf8("closeCenterLabel"));

        horizontalLayout_3->addWidget(closeCenterLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectionTriangleLabel = new QLabel(controlFrame);
        selectionTriangleLabel->setObjectName(QString::fromUtf8("selectionTriangleLabel"));

        horizontalLayout->addWidget(selectionTriangleLabel);

        manualRadioButton = new QRadioButton(controlFrame);
        manualRadioButton->setObjectName(QString::fromUtf8("manualRadioButton"));

        horizontalLayout->addWidget(manualRadioButton);

        automaticRadioButton = new QRadioButton(controlFrame);
        automaticRadioButton->setObjectName(QString::fromUtf8("automaticRadioButton"));
        automaticRadioButton->setChecked(true);

        horizontalLayout->addWidget(automaticRadioButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stopButton = new QPushButton(controlFrame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setEnabled(false);

        horizontalLayout_2->addWidget(stopButton);

        refineOnceButton = new QPushButton(controlFrame);
        refineOnceButton->setObjectName(QString::fromUtf8("refineOnceButton"));
        refineOnceButton->setEnabled(false);

        horizontalLayout_2->addWidget(refineOnceButton);

        refineButton = new QPushButton(controlFrame);
        refineButton->setObjectName(QString::fromUtf8("refineButton"));
        refineButton->setEnabled(false);

        horizontalLayout_2->addWidget(refineButton);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_4->addWidget(controlFrame, 6, 0, 2, 1);

        optionFrame = new QFrame(centralWidget);
        optionFrame->setObjectName(QString::fromUtf8("optionFrame"));
        optionFrame->setFrameShape(QFrame::StyledPanel);
        optionFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(optionFrame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        optionToolBox = new QToolBox(optionFrame);
        optionToolBox->setObjectName(QString::fromUtf8("optionToolBox"));
        optionToolBox->setEnabled(true);
        triangleSelectPage = new QWidget();
        triangleSelectPage->setObjectName(QString::fromUtf8("triangleSelectPage"));
        triangleSelectPage->setGeometry(QRect(0, 0, 437, 202));
        formLayout_5 = new QFormLayout(triangleSelectPage);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_2 = new QLabel(triangleSelectPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_2);

        automaticTriangleSelectionDoubleSpinBox = new QDoubleSpinBox(triangleSelectPage);
        automaticTriangleSelectionDoubleSpinBox->setObjectName(QString::fromUtf8("automaticTriangleSelectionDoubleSpinBox"));
        sizePolicy.setHeightForWidth(automaticTriangleSelectionDoubleSpinBox->sizePolicy().hasHeightForWidth());
        automaticTriangleSelectionDoubleSpinBox->setSizePolicy(sizePolicy);
        automaticTriangleSelectionDoubleSpinBox->setValue(20);

        formLayout_5->setWidget(4, QFormLayout::FieldRole, automaticTriangleSelectionDoubleSpinBox);

        label_3 = new QLabel(triangleSelectPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_3);

        repeatSelectedTriangleCheckBox = new QCheckBox(triangleSelectPage);
        repeatSelectedTriangleCheckBox->setObjectName(QString::fromUtf8("repeatSelectedTriangleCheckBox"));
        repeatSelectedTriangleCheckBox->setChecked(true);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, repeatSelectedTriangleCheckBox);

        automaticTriangleSelectionComboBox = new QComboBox(triangleSelectPage);
        automaticTriangleSelectionComboBox->setObjectName(QString::fromUtf8("automaticTriangleSelectionComboBox"));
        automaticTriangleSelectionComboBox->setEnabled(true);
        sizePolicy.setHeightForWidth(automaticTriangleSelectionComboBox->sizePolicy().hasHeightForWidth());
        automaticTriangleSelectionComboBox->setSizePolicy(sizePolicy);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, automaticTriangleSelectionComboBox);

        optionToolBox->addItem(triangleSelectPage, QString::fromUtf8("Priorizaci\303\263n de Tri\303\241ngulo para Refinar"));
        newPointPage = new QWidget();
        newPointPage->setObjectName(QString::fromUtf8("newPointPage"));
        newPointPage->setGeometry(QRect(0, 0, 437, 202));
        formLayout_3 = new QFormLayout(newPointPage);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(newPointPage);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        newPointMethodComboBox = new QComboBox(newPointPage);
        newPointMethodComboBox->setObjectName(QString::fromUtf8("newPointMethodComboBox"));

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, newPointMethodComboBox);

        optionToolBox->addItem(newPointPage, QString::fromUtf8("Criterio Selecci\303\263n Nuevo Punto para Insertar"));
        insertionPage = new QWidget();
        insertionPage->setObjectName(QString::fromUtf8("insertionPage"));
        insertionPage->setGeometry(QRect(0, 0, 437, 202));
        formLayout = new QFormLayout(insertionPage);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        insideNewPointCaseComboBox = new QComboBox(insertionPage);
        insideNewPointCaseComboBox->setObjectName(QString::fromUtf8("insideNewPointCaseComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, insideNewPointCaseComboBox);

        optionToolBox->addItem(insertionPage, QString::fromUtf8("M\303\251todo Inserci\303\263n de Nuevo Punto"));

        verticalLayout_3->addWidget(optionToolBox);


        gridLayout_4->addWidget(optionFrame, 0, 1, 4, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        infoTextEdit = new QTextEdit(frame);
        infoTextEdit->setObjectName(QString::fromUtf8("infoTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoTextEdit->sizePolicy().hasHeightForWidth());
        infoTextEdit->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(infoTextEdit);


        gridLayout_4->addWidget(frame, 4, 1, 4, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1118, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuMesh = new QMenu(menuBar);
        menuMesh->setObjectName(QString::fromUtf8("menuMesh"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(refineOnceButton, stopButton);
        QWidget::setTabOrder(stopButton, refineButton);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuMesh->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuMesh->addAction(actionLoad);
        menuMesh->addAction(actionReload);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        optionToolBox->setCurrentIndex(2);
        optionToolBox->layout()->setSpacing(1);
        newPointMethodComboBox->setCurrentIndex(0);
        insideNewPointCaseComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MeshSuite", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "Nueva", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Abrir...", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Guardar", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Cargar...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLoad->setToolTip(QApplication::translate("MainWindow", "Cargar Malla", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionReload->setText(QApplication::translate("MainWindow", "Recargar", 0, QApplication::UnicodeUTF8));
        actionReload->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Guardar como...", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "Acerca...", 0, QApplication::UnicodeUTF8));
        infoControl->setText(QApplication::translate("MainWindow", "Control", 0, QApplication::UnicodeUTF8));
        scaleLabel->setText(QApplication::translate("MainWindow", "Zoom     ", 0, QApplication::UnicodeUTF8));
        openCenterLavel->setText(QApplication::translate("MainWindow", "Center (", 0, QApplication::UnicodeUTF8));
        commaCenterLabel->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        closeCenterLabel->setText(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
        selectionTriangleLabel->setText(QApplication::translate("MainWindow", "Selecci\303\263n Tri\303\241ngulo", 0, QApplication::UnicodeUTF8));
        manualRadioButton->setText(QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8));
        manualRadioButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        automaticRadioButton->setText(QApplication::translate("MainWindow", "Autom\303\241tico", 0, QApplication::UnicodeUTF8));
        automaticRadioButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "||", 0, QApplication::UnicodeUTF8));
        refineOnceButton->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        refineOnceButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Space", 0, QApplication::UnicodeUTF8));
        refineButton->setText(QApplication::translate("MainWindow", ">>", 0, QApplication::UnicodeUTF8));
        refineButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+Space", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Par\303\241metro de calidad", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Priorizar por:", 0, QApplication::UnicodeUTF8));
        repeatSelectedTriangleCheckBox->setText(QApplication::translate("MainWindow", "Repetir tri\303\241ngulo hasta destruir", 0, QApplication::UnicodeUTF8));
        automaticTriangleSelectionComboBox->clear();
        automaticTriangleSelectionComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sin Priorizar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\303\201ngulo Interno Menor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Arista M\303\241s Peque\303\261a", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Arista M\303\241s Peque\303\261a, Prioridad Bordes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Menor Circunradio", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Largo Borde", 0, QApplication::UnicodeUTF8)
        );
        optionToolBox->setItemText(optionToolBox->indexOf(triangleSelectPage), QApplication::translate("MainWindow", "Priorizaci\303\263n de Tri\303\241ngulo para Refinar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "M\303\251todo para Nuevo Punto:", 0, QApplication::UnicodeUTF8));
        newPointMethodComboBox->clear();
        newPointMethodComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lepp - Bisecci\303\263n", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Circuncentro - Delaunay", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp - Punto Medio - Delaunay", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp - Centroide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Off-Center - Delaunay", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp - Circuncentro - Delaunay", 0, QApplication::UnicodeUTF8)
        );
        optionToolBox->setItemText(optionToolBox->indexOf(newPointPage), QApplication::translate("MainWindow", "Criterio Selecci\303\263n Nuevo Punto para Insertar", 0, QApplication::UnicodeUTF8));
        insideNewPointCaseComboBox->clear();
        insideNewPointCaseComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Flip Diagonal (Delaunay)", 0, QApplication::UnicodeUTF8)
        );
        optionToolBox->setItemText(optionToolBox->indexOf(insertionPage), QApplication::translate("MainWindow", "M\303\251todo Inserci\303\263n de Nuevo Punto", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuMesh->setTitle(QApplication::translate("MainWindow", "PSLG", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
