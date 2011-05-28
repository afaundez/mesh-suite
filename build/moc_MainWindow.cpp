/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Sat May 28 19:42:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/lib/gui/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     316,   11,   11,   11, 0x08,
     346,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0"
    "on_automaticTriangleSelectionDoubleSpinBox_editingFinished()\0"
    "on_yTranslateDoubleSpinBox_editingFinished()\0"
    "on_xTranslateDoubleSpinBox_editingFinished()\0"
    "on_scaleSpinBox_editingFinished()\0"
    "on_manualRadioButton_clicked()\0"
    "on_automaticRadioButton_clicked()\0"
    "on_actionLoad_triggered()\0"
    "on_actionReload_triggered()\0"
    "on_refineOnceButton_clicked()\0"
    "on_refineButton_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_automaticTriangleSelectionDoubleSpinBox_editingFinished(); break;
        case 1: on_yTranslateDoubleSpinBox_editingFinished(); break;
        case 2: on_xTranslateDoubleSpinBox_editingFinished(); break;
        case 3: on_scaleSpinBox_editingFinished(); break;
        case 4: on_manualRadioButton_clicked(); break;
        case 5: on_automaticRadioButton_clicked(); break;
        case 6: on_actionLoad_triggered(); break;
        case 7: on_actionReload_triggered(); break;
        case 8: on_refineOnceButton_clicked(); break;
        case 9: on_refineButton_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
