/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 29 14:08:49 2010
**      by: Qt User Interface Compiler version 4.6.2
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
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
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
    QHBoxLayout *glLayout;
    QTabWidget *processTab;
    QWidget *automaticPage;
    QFormLayout *processLayout;
    QLabel *label_12;
    QComboBox *comboBox_10;
    QFrame *line;
    QLabel *label;
    QComboBox *comboBox;
    QFrame *line_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QCheckBox *checkBox;
    QFrame *line_3;
    QLabel *label_9;
    QComboBox *comboBox_8;
    QFrame *line_4;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QFrame *line_5;
    QLabel *label_5;
    QComboBox *comboBox_4;
    QFrame *line_6;
    QLabel *label_13;
    QTextEdit *textEdit_2;
    QSplitter *splitter_4;
    QLineEdit *lineEdit;
    QLabel *label_14;
    QWidget *manualPage;
    QFormLayout *formLayout;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox_6;
    QComboBox *comboBox_7;
    QComboBox *comboBox_9;
    QLabel *label_10;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QFrame *frame;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSplitter *splitter_2;
    QLabel *label_11;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCombination;
    QMenu *menuMesh;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 662);
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
        glLayout = new QHBoxLayout();
        glLayout->setSpacing(6);
        glLayout->setObjectName(QString::fromUtf8("glLayout"));

        gridLayout_4->addLayout(glLayout, 0, 0, 4, 2);

        processTab = new QTabWidget(centralWidget);
        processTab->setObjectName(QString::fromUtf8("processTab"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(processTab->sizePolicy().hasHeightForWidth());
        processTab->setSizePolicy(sizePolicy1);
        automaticPage = new QWidget();
        automaticPage->setObjectName(QString::fromUtf8("automaticPage"));
        processLayout = new QFormLayout(automaticPage);
        processLayout->setSpacing(6);
        processLayout->setContentsMargins(11, 11, 11, 11);
        processLayout->setObjectName(QString::fromUtf8("processLayout"));
        processLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_12 = new QLabel(automaticPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        processLayout->setWidget(0, QFormLayout::LabelRole, label_12);

        comboBox_10 = new QComboBox(automaticPage);
        comboBox_10->setObjectName(QString::fromUtf8("comboBox_10"));

        processLayout->setWidget(0, QFormLayout::FieldRole, comboBox_10);

        line = new QFrame(automaticPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        processLayout->setWidget(2, QFormLayout::SpanningRole, line);

        label = new QLabel(automaticPage);
        label->setObjectName(QString::fromUtf8("label"));

        processLayout->setWidget(3, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(automaticPage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        processLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        line_2 = new QFrame(automaticPage);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        processLayout->setWidget(4, QFormLayout::SpanningRole, line_2);

        label_2 = new QLabel(automaticPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        processLayout->setWidget(5, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(automaticPage);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        processLayout->setWidget(5, QFormLayout::FieldRole, comboBox_2);

        label_4 = new QLabel(automaticPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        processLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        checkBox = new QCheckBox(automaticPage);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        processLayout->setWidget(6, QFormLayout::FieldRole, checkBox);

        line_3 = new QFrame(automaticPage);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        processLayout->setWidget(7, QFormLayout::SpanningRole, line_3);

        label_9 = new QLabel(automaticPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        processLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        comboBox_8 = new QComboBox(automaticPage);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        processLayout->setWidget(8, QFormLayout::FieldRole, comboBox_8);

        line_4 = new QFrame(automaticPage);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        processLayout->setWidget(9, QFormLayout::SpanningRole, line_4);

        label_3 = new QLabel(automaticPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        processLayout->setWidget(10, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(automaticPage);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        processLayout->setWidget(10, QFormLayout::FieldRole, comboBox_3);

        line_5 = new QFrame(automaticPage);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        processLayout->setWidget(11, QFormLayout::SpanningRole, line_5);

        label_5 = new QLabel(automaticPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        processLayout->setWidget(12, QFormLayout::LabelRole, label_5);

        comboBox_4 = new QComboBox(automaticPage);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        processLayout->setWidget(12, QFormLayout::FieldRole, comboBox_4);

        line_6 = new QFrame(automaticPage);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        processLayout->setWidget(14, QFormLayout::SpanningRole, line_6);

        label_13 = new QLabel(automaticPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        processLayout->setWidget(15, QFormLayout::LabelRole, label_13);

        textEdit_2 = new QTextEdit(automaticPage);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setReadOnly(true);

        processLayout->setWidget(16, QFormLayout::SpanningRole, textEdit_2);

        splitter_4 = new QSplitter(automaticPage);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setEnabled(true);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setOpaqueResize(true);
        splitter_4->setHandleWidth(6);
        splitter_4->setChildrenCollapsible(true);
        lineEdit = new QLineEdit(splitter_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_4->addWidget(lineEdit);
        label_14 = new QLabel(splitter_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        splitter_4->addWidget(label_14);

        processLayout->setWidget(1, QFormLayout::FieldRole, splitter_4);

        processTab->addTab(automaticPage, QString());
        manualPage = new QWidget();
        manualPage->setObjectName(QString::fromUtf8("manualPage"));
        formLayout = new QFormLayout(manualPage);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(manualPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        comboBox_5 = new QComboBox(manualPage);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_5);

        label_7 = new QLabel(manualPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(manualPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        comboBox_6 = new QComboBox(manualPage);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_6);

        comboBox_7 = new QComboBox(manualPage);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_7);

        comboBox_9 = new QComboBox(manualPage);
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_9);

        label_10 = new QLabel(manualPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        processTab->addTab(manualPage, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        processTab->addTab(tab, QString());

        gridLayout_4->addWidget(processTab, 0, 2, 5, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        splitter_3 = new QSplitter(frame);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(60, 20, 391, 73));
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pushButton_3 = new QPushButton(splitter);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        splitter->addWidget(pushButton_3);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        label_11 = new QLabel(splitter_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        splitter_2->addWidget(label_11);
        horizontalSlider = new QSlider(splitter_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setValue(50);
        horizontalSlider->setSliderPosition(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        splitter_2->addWidget(horizontalSlider);
        splitter_3->addWidget(splitter_2);

        gridLayout_4->addWidget(frame, 4, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCombination = new QMenu(menuBar);
        menuCombination->setObjectName(QString::fromUtf8("menuCombination"));
        menuMesh = new QMenu(menuBar);
        menuMesh->setObjectName(QString::fromUtf8("menuMesh"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCombination->menuAction());
        menuBar->addAction(menuMesh->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuCombination->addAction(actionNew);
        menuCombination->addAction(actionOpen);
        menuCombination->addAction(actionSave);
        menuCombination->addAction(actionSaveAs);
        menuMesh->addAction(actionLoad);
        menuMesh->addAction(actionReload);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        processTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "Nueva", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Abrir...", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Guardar", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Cargar...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLoad->setToolTip(QApplication::translate("MainWindow", "Cargar Malla", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionReload->setText(QApplication::translate("MainWindow", "Recargar", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Guardar como...", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "Acerca...", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Criterio Calidad", 0, QApplication::UnicodeUTF8));
        comboBox_10->clear();
        comboBox_10->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Menor \303\241ngulo interior", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Pre-proceso", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Ninguno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Revisar Diametro", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Selecci\303\263n de punto", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lepp-Bisection", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Circumcenter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Bisection", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Centroid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp-Centroid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp-Delaunay", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Off-Center", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QString());
        checkBox->setText(QApplication::translate("MainWindow", "Iterar", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Tipo Inserci\303\263n", 0, QApplication::UnicodeUTF8));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Cavidad*", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Flip Diagonals", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "Inserci\303\263n en Borde", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Rivara", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ruppert", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Inserci\303\263n Restringida", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Rivara", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ruppert", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("MainWindow", "Resumen", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\302\272", 0, QApplication::UnicodeUTF8));
        processTab->setTabText(processTab->indexOf(automaticPage), QApplication::translate("MainWindow", "Autom\303\241tico", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Selecci\303\263n de punto", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Circumcenter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Bisection", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp-Bisection", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Centroid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp-Centroid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lepp-Delaunay", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Off-Center", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("MainWindow", "Inserci\303\263n en Borde", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Inserci\303\263n Restringida", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Rupert", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rivara", 0, QApplication::UnicodeUTF8)
        );
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Ruppert", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rivara", 0, QApplication::UnicodeUTF8)
        );
        comboBox_9->clear();
        comboBox_9->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Flip Diagonal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Cavidad*", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("MainWindow", "Tipo Inserci\303\263n", 0, QApplication::UnicodeUTF8));
        processTab->setTabText(processTab->indexOf(manualPage), QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        processTab->setTabText(processTab->indexOf(tab), QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "||", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", ">>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuCombination->setTitle(QApplication::translate("MainWindow", "Combinaci\303\263n", 0, QApplication::UnicodeUTF8));
        menuMesh->setTitle(QApplication::translate("MainWindow", "Malla", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
