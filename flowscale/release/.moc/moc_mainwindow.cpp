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
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   11,   11,   11, 0x05,
      42,   11,   11,   11, 0x05,
      56,   11,   11,   11, 0x05,
      70,   11,   11,   11, 0x05,
      84,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     157,  149,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     334,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     398,   11,   11,   11, 0x08,
     416,   11,   11,   11, 0x08,
     434,   11,   11,   11, 0x08,
     452,   11,   11,   11, 0x08,
     472,  470,   11,   11, 0x08,
     491,   11,   11,   11, 0x08,
     515,   11,   11,   11, 0x08,
     539,   11,   11,   11, 0x08,
     572,   11,   11,   11, 0x08,
     606,   11,   11,   11, 0x08,
     647,  642,   11,   11, 0x08,
     682,  642,   11,   11, 0x08,
     719,   11,   11,   11, 0x0a,
     740,   11,   11,   11, 0x0a,
     775,   11,   11,   11, 0x0a,
     793,   11,   11,   11, 0x0a,
     820,   11,   11,   11, 0x0a,
     848,   11,   11,   11, 0x0a,
     872,   11,   11,   11, 0x0a,
     897,   11,   11,   11, 0x0a,
     923,   11,   11,   11, 0x0a,
     951,   11,   11,   11, 0x0a,
     976,   11,   11,   11, 0x0a,
    1003,   11,   11,   11, 0x0a,
    1030,   11,   11,   11, 0x0a,
    1053,   11,   11,   11, 0x0a,
    1085,   11,   11,   11, 0x0a,
    1110,   11,   11,   11, 0x0a,
    1138,   11,   11,   11, 0x0a,
    1160,   11,   11,   11, 0x0a,
    1178,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0avgWeight(int)\0value(QString)\0"
    "xmin(QString)\0xmax(QString)\0ymin(QString)\0"
    "ymax(QString)\0on_btnConnect_clicked()\0"
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
    ",\0setOutput(int,int)\0on_btnReverse_clicked()\0"
    "on_btnForward_clicked()\0"
    "on_btnNetWeightConnect_clicked()\0"
    "on_btnRefreshRecipeList_clicked()\0"
    "on_btnRefreshSettingsList_clicked()\0"
    "arg1\0on_cbRecipeMenu_activated(QString)\0"
    "on_cbSettingsMenu_activated(QString)\0"
    "conveyorBeltSignal()\0"
    "conveyorRunStateIndicator(QString)\0"
    "recordWeight(int)\0displayReceivedWeight(int)\0"
    "displayDescription(QString)\0"
    "displayBatchId(QString)\0"
    "displayRecipeId(QString)\0"
    "displayProductId(QString)\0"
    "displayProductType(QString)\0"
    "displaySerialNumber(int)\0"
    "displayFilteredWeight(int)\0"
    "displayConfidence(QString)\0"
    "displayLength(QString)\0"
    "displayDestinationGate(QString)\0"
    "displayInputValue(ulong)\0"
    "productWeightToDisplay(int)\0"
    "plotProductGraph(int)\0keyValue(QString)\0"
    "graphBoundaries(QString)\0"
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
        case 6: _t->on_btnConnect_clicked(); break;
        case 7: _t->on_btnDisconnect_clicked(); break;
        case 8: _t->on_chkWriteToLoadcell_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_btnCalibrateZERO_clicked(); break;
        case 10: _t->on_btnCalibrateWEIGHT_clicked(); break;
        case 11: _t->on_btnAPPLY_clicked(); break;
        case 12: _t->on_btnSemiAutoZERO_clicked(); break;
        case 13: _t->on_btnGrossWeight_clicked(); break;
        case 14: _t->on_btnNetWeight_clicked(); break;
        case 15: _t->on_btnEditCalibrationWeight_clicked(); break;
        case 16: _t->on_xmin_clicked(); break;
        case 17: _t->on_xmax_clicked(); break;
        case 18: _t->on_ymin_clicked(); break;
        case 19: _t->on_ymax_clicked(); break;
        case 20: _t->setOutput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->on_btnReverse_clicked(); break;
        case 22: _t->on_btnForward_clicked(); break;
        case 23: _t->on_btnNetWeightConnect_clicked(); break;
        case 24: _t->on_btnRefreshRecipeList_clicked(); break;
        case 25: _t->on_btnRefreshSettingsList_clicked(); break;
        case 26: _t->on_cbRecipeMenu_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->on_cbSettingsMenu_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->conveyorBeltSignal(); break;
        case 29: _t->conveyorRunStateIndicator((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->recordWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->displayReceivedWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->displayDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->displayBatchId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->displayRecipeId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->displayProductId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->displayProductType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->displaySerialNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->displayFilteredWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->displayConfidence((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->displayLength((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->displayDestinationGate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->displayInputValue((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 43: _t->productWeightToDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->plotProductGraph((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->keyValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 46: _t->graphBoundaries((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
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
QT_END_MOC_NAMESPACE
