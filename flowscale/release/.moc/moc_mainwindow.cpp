/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   11,   11,   11, 0x05,
      42,   11,   11,   11, 0x05,
      56,   11,   11,   11, 0x05,
      70,   11,   11,   11, 0x05,
      84,   11,   11,   11, 0x05,
      98,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     183,  175,   11,   11, 0x08,
     219,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     281,   11,   11,   11, 0x08,
     303,   11,   11,   11, 0x08,
     332,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     386,   11,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     442,   11,   11,   11, 0x08,
     460,   11,   11,   11, 0x08,
     478,   11,   11,   11, 0x08,
     496,   11,   11,   11, 0x08,
     520,   11,   11,   11, 0x08,
     544,   11,   11,   11, 0x08,
     577,   11,   11,   11, 0x08,
     611,   11,   11,   11, 0x08,
     652,  647,   11,   11, 0x08,
     687,  647,   11,   11, 0x08,
     724,   11,   11,   11, 0x0a,
     745,   11,   11,   11, 0x0a,
     763,   11,   11,   11, 0x0a,
     790,   11,   11,   11, 0x0a,
     817,   11,   11,   11, 0x0a,
     839,   11,   11,   11, 0x0a,
     864,   11,   11,   11, 0x0a,
     887,   11,   11,   11, 0x0a,
     909,   11,   11,   11, 0x0a,
     927,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0avgWeight(int)\0value(QString)\0"
    "xmin(QString)\0xmax(QString)\0ymin(QString)\0"
    "ymax(QString)\0setCurrentRecipe(QString)\0"
    "on_btnConnect_clicked()\0"
    "on_btnDisconnect_clicked()\0checked\0"
    "on_chkWriteToLoadcell_toggled(bool)\0"
    "on_btnCalibrateZERO_clicked()\0"
    "on_btnCalibrateWEIGHT_clicked()\0"
    "on_btnAPPLY_clicked()\0"
    "on_btnSemiAutoZERO_clicked()\0"
    "on_btnGrossWeight_clicked()\0"
    "on_btnNetWeight_clicked()\0"
    "on_btnEditCalibrationWeight_clicked()\0"
    "on_xmin_clicked()\0on_xmax_clicked()\0"
    "on_ymin_clicked()\0on_ymax_clicked()\0"
    "on_btnReverse_clicked()\0on_btnForward_clicked()\0"
    "on_btnNetWeightConnect_clicked()\0"
    "on_btnRefreshRecipeList_clicked()\0"
    "on_btnRefreshSettingsList_clicked()\0"
    "arg1\0on_cbRecipeMenu_activated(QString)\0"
    "on_cbSettingsMenu_activated(QString)\0"
    "conveyorBeltSignal()\0recordWeight(int)\0"
    "displayReceivedWeight(int)\0"
    "displayFilteredWeight(int)\0"
    "displayDebugData(int)\0displayInputValue(ulong)\0"
    "plotProductWeight(int)\0plotProductGraph(int)\0"
    "keyValue(QString)\0graphBoundaries(QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->avgWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->value((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->xmin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->xmax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->ymin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->ymax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setCurrentRecipe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_btnConnect_clicked(); break;
        case 8: _t->on_btnDisconnect_clicked(); break;
        case 9: _t->on_chkWriteToLoadcell_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_btnCalibrateZERO_clicked(); break;
        case 11: _t->on_btnCalibrateWEIGHT_clicked(); break;
        case 12: _t->on_btnAPPLY_clicked(); break;
        case 13: _t->on_btnSemiAutoZERO_clicked(); break;
        case 14: _t->on_btnGrossWeight_clicked(); break;
        case 15: _t->on_btnNetWeight_clicked(); break;
        case 16: _t->on_btnEditCalibrationWeight_clicked(); break;
        case 17: _t->on_xmin_clicked(); break;
        case 18: _t->on_xmax_clicked(); break;
        case 19: _t->on_ymin_clicked(); break;
        case 20: _t->on_ymax_clicked(); break;
        case 21: _t->on_btnReverse_clicked(); break;
        case 22: _t->on_btnForward_clicked(); break;
        case 23: _t->on_btnNetWeightConnect_clicked(); break;
        case 24: _t->on_btnRefreshRecipeList_clicked(); break;
        case 25: _t->on_btnRefreshSettingsList_clicked(); break;
        case 26: _t->on_cbRecipeMenu_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->on_cbSettingsMenu_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->conveyorBeltSignal(); break;
        case 29: _t->recordWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->displayReceivedWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->displayFilteredWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->displayDebugData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->displayInputValue((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 34: _t->plotProductWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->plotProductGraph((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->keyValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->graphBoundaries((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::avgWeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::value(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::xmin(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::xmax(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::ymin(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::ymax(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::setCurrentRecipe(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
