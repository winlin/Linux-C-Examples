/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Aug 24 15:01:30 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TextEdit/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     247,   11,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     299,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionNew_triggered()\0"
    "on_actionSaveAS_triggered()\0"
    "on_actionSafe_triggered()\0"
    "on_actionOpen_triggered()\0"
    "on_actionExit_triggered()\0"
    "on_actionUndo_triggered()\0"
    "on_actionCopy_triggered()\0"
    "on_actionPaste_triggered()\0"
    "on_actionCut_triggered()\0"
    "on_actionRedo_triggered()\0"
    "on_actionFind_triggered()\0findString()\0"
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
        case 0: on_actionNew_triggered(); break;
        case 1: on_actionSaveAS_triggered(); break;
        case 2: on_actionSafe_triggered(); break;
        case 3: on_actionOpen_triggered(); break;
        case 4: on_actionExit_triggered(); break;
        case 5: on_actionUndo_triggered(); break;
        case 6: on_actionCopy_triggered(); break;
        case 7: on_actionPaste_triggered(); break;
        case 8: on_actionCut_triggered(); break;
        case 9: on_actionRedo_triggered(); break;
        case 10: on_actionFind_triggered(); break;
        case 11: findString(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
