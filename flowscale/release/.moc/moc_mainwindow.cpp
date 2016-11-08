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
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   11,   11,   11, 0x05,
      42,   11,   11,   11, 0x05,
      56,   11,   11,   11, 0x05,
      70,   11,   11,   11, 0x05,
      84,   11,   11,   11, 0x05,
      98,   11,   11,   11, 0x05,
     122,   11,   11,   11, 0x05,
     146,   11,   11,   11, 0x05,
     170,   11,   11,   11, 0x05,
     194,   11,   11,   11, 0x05,
     218,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     242,   11,   11,   11, 0x08,
     277,  269,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     343,   11,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,
     397,   11,   11,   11, 0x08,
     415,   11,   11,   11, 0x08,
     433,   11,   11,   11, 0x08,
     451,   11,   11,   11, 0x08,
     471,  469,   11,   11, 0x08,
     497,   11,   11,   11, 0x08,
     521,   11,   11,   11, 0x08,
     545,   11,   11,   11, 0x08,
     578,   11,   11,   11, 0x08,
     612,   11,   11,   11, 0x08,
     653,  648,   11,   11, 0x08,
     688,  648,   11,   11, 0x08,
     725,  269,   11,   11, 0x08,
     751,  269,   11,   11, 0x08,
     777,  269,   11,   11, 0x08,
     803,  269,   11,   11, 0x08,
     829,  269,   11,   11, 0x08,
     855,  269,   11,   11, 0x08,
     881,   11,   11,   11, 0x0a,
     902,   11,   11,   11, 0x0a,
     937,   11,   11,   11, 0x0a,
     955,   11,   11,   11, 0x0a,
     982,   11,   11,   11, 0x0a,
    1010,   11,   11,   11, 0x0a,
    1034,   11,   11,   11, 0x0a,
    1059,   11,   11,   11, 0x0a,
    1085,   11,   11,   11, 0x0a,
    1113,   11,   11,   11, 0x0a,
    1138,   11,   11,   11, 0x0a,
    1165,   11,   11,   11, 0x0a,
    1192,   11,   11,   11, 0x0a,
    1215,   11,   11,   11, 0x0a,
    1247,   11,   11,   11, 0x0a,
    1272,   11,   11,   11, 0x0a,
    1300,   11,   11,   11, 0x0a,
    1322,   11,   11,   11, 0x0a,
    1340,   11,   11,   11, 0x0a,
    1365,  469,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0avgWeight(int)\0value(QString)\0"
    "xmin(QString)\0xmax(QString)\0ymin(QString)\0"
    "ymax(QString)\0gate1Availability(bool)\0"
    "gate2Availability(bool)\0gate3Availability(bool)\0"
    "gate4Availability(bool)\0gate5Availability(bool)\0"
    "gate6Availability(bool)\0"
    "on_btnDisconnect_clicked()\0checked\0"
    "on_chkWriteToLoadcell_toggled(bool)\0"
    "on_btnCalibrateZERO_clicked()\0"
    "on_btnCalibrateWEIGHT_clicked()\0"
    "on_btnAPPLY_clicked()\0on_xmin_clicked()\0"
    "on_xmax_clicked()\0on_ymin_clicked()\0"
    "on_ymax_clicked()\0,\0activateGateArm(int,bool)\0"
    "on_btnReverse_clicked()\0on_btnForward_clicked()\0"
    "on_btnNetWeightConnect_clicked()\0"
    "on_btnRefreshRecipeList_clicked()\0"
    "on_btnRefreshSettingsList_clicked()\0"
    "arg1\0on_cbRecipeMenu_activated(QString)\0"
    "on_cbSettingsMenu_activated(QString)\0"
    "on_cbxGate1_clicked(bool)\0"
    "on_cbxGate2_clicked(bool)\0"
    "on_cbxGate3_clicked(bool)\0"
    "on_cbxGate4_clicked(bool)\0"
    "on_cbxGate5_clicked(bool)\0"
    "on_cbxGate6_clicked(bool)\0"
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
    "graphBoundaries(QString)\0enableGate(int,bool)\0"
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
        case 6: _t->gate1Availability((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->gate2Availability((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->gate3Availability((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->gate4Availability((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->gate5Availability((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->gate6Availability((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_btnDisconnect_clicked(); break;
        case 13: _t->on_chkWriteToLoadcell_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_btnCalibrateZERO_clicked(); break;
        case 15: _t->on_btnCalibrateWEIGHT_clicked(); break;
        case 16: _t->on_btnAPPLY_clicked(); break;
        case 17: _t->on_xmin_clicked(); break;
        case 18: _t->on_xmax_clicked(); break;
        case 19: _t->on_ymin_clicked(); break;
        case 20: _t->on_ymax_clicked(); break;
        case 21: _t->activateGateArm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->on_btnReverse_clicked(); break;
        case 23: _t->on_btnForward_clicked(); break;
        case 24: _t->on_btnNetWeightConnect_clicked(); break;
        case 25: _t->on_btnRefreshRecipeList_clicked(); break;
        case 26: _t->on_btnRefreshSettingsList_clicked(); break;
        case 27: _t->on_cbRecipeMenu_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->on_cbSettingsMenu_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->on_cbxGate1_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_cbxGate2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_cbxGate3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_cbxGate4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_cbxGate5_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_cbxGate6_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->conveyorBeltSignal(); break;
        case 36: _t->conveyorRunStateIndicator((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->recordWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->displayReceivedWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->displayDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->displayBatchId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->displayRecipeId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->displayProductId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 43: _t->displayProductType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 44: _t->displaySerialNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->displayFilteredWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->displayConfidence((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 47: _t->displayLength((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: _t->displayDestinationGate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->displayInputValue((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 50: _t->productWeightToDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->plotProductGraph((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->keyValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 53: _t->graphBoundaries((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 54: _t->enableGate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
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
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
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
void MainWindow::gate1Availability(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::gate2Availability(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::gate3Availability(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::gate4Availability(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::gate5Availability(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::gate6Availability(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
