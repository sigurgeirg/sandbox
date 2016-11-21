/****************************************************************************
** Meta object code from reading C++ file 'myscale.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/myscale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myscale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyScale[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      37,    8,    8,    8, 0x05,
      64,    8,    8,    8, 0x05,
      86,    8,    8,    8, 0x05,
     111,    8,    8,    8, 0x05,
     132,    8,    8,    8, 0x05,
     154,    8,    8,    8, 0x05,
     177,    8,    8,    8, 0x05,
     202,    8,    8,    8, 0x05,
     226,    8,    8,    8, 0x05,
     246,    8,    8,    8, 0x05,
     275,    8,    8,    8, 0x05,
     289,    8,    8,    8, 0x05,
     308,    8,    8,    8, 0x05,
     334,    8,    8,    8, 0x05,
     362,  360,    8,    8, 0x05,
     392,  360,    8,    8, 0x05,
     418,  360,    8,    8, 0x05,
     446,  360,    8,    8, 0x05,
     467,  360,    8,    8, 0x05,
     492,  360,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     518,    8,    8,    8, 0x0a,
     539,    8,    8,    8, 0x0a,
     569,    8,    8,    8, 0x0a,
     598,    8,    8,    8, 0x0a,
     612,    8,    8,    8, 0x0a,
     626,    8,    8,    8, 0x0a,
     640,    8,    8,    8, 0x0a,
     654,    8,    8,    8, 0x0a,
     674,    8,    8,    8, 0x0a,
     694,    8,    8,    8, 0x0a,
     714,    8,    8,    8, 0x0a,
     734,    8,    8,    8, 0x0a,
     754,    8,    8,    8, 0x0a,
     774,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyScale[] = {
    "MyScale\0\0continuousModbusWeight(int)\0"
    "sendFilteredWeight(double)\0"
    "sendSerialNumber(int)\0sendDescription(QString)\0"
    "sendBatchId(QString)\0sendRecipeId(QString)\0"
    "sendProductId(QString)\0sendProductType(QString)\0"
    "sendConfidence(QString)\0sendLength(QString)\0"
    "sendDestinationGate(QString)\0plotData(int)\0"
    "productWeight(int)\0requestNewRecipe(QString)\0"
    "conveyorRunState(QString)\0,\0"
    "sendMQTT(QString,const char*)\0"
    "activateGateArm(int,bool)\0"
    "activateGateDiode(int,bool)\0"
    "enableGate(int,bool)\0bufferCount(int,QString)\0"
    "bufferWeight(int,QString)\0"
    "conveyorBeltSignal()\0enteringProductSensorSignal()\0"
    "leavingProductSensorSignal()\0xmin(QString)\0"
    "xmax(QString)\0ymin(QString)\0ymax(QString)\0"
    "gate01_Closed(bool)\0gate02_Closed(bool)\0"
    "gate03_Closed(bool)\0gate04_Closed(bool)\0"
    "gate05_Closed(bool)\0gate06_Closed(bool)\0"
    "changeGateStateWithButtonPress(int)\0"
};

void MyScale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyScale *_t = static_cast<MyScale *>(_o);
        switch (_id) {
        case 0: _t->continuousModbusWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendFilteredWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->sendSerialNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendBatchId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sendRecipeId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendProductId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendProductType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendConfidence((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->sendLength((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sendDestinationGate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->plotData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->productWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->requestNewRecipe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->conveyorRunState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->sendMQTT((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2]))); break;
        case 16: _t->activateGateArm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 17: _t->activateGateDiode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->enableGate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 19: _t->bufferCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->bufferWeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: _t->conveyorBeltSignal(); break;
        case 22: _t->enteringProductSensorSignal(); break;
        case 23: _t->leavingProductSensorSignal(); break;
        case 24: _t->xmin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->xmax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->ymin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->ymax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->gate01_Closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->gate02_Closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->gate03_Closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->gate04_Closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->gate05_Closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->gate06_Closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->changeGateStateWithButtonPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyScale::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyScale::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyScale,
      qt_meta_data_MyScale, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyScale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyScale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyScale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyScale))
        return static_cast<void*>(const_cast< MyScale*>(this));
    return QThread::qt_metacast(_clname);
}

int MyScale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void MyScale::continuousModbusWeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyScale::sendFilteredWeight(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyScale::sendSerialNumber(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyScale::sendDescription(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyScale::sendBatchId(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyScale::sendRecipeId(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyScale::sendProductId(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyScale::sendProductType(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyScale::sendConfidence(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyScale::sendLength(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyScale::sendDestinationGate(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MyScale::plotData(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MyScale::productWeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MyScale::requestNewRecipe(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MyScale::conveyorRunState(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MyScale::sendMQTT(QString _t1, const char * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MyScale::activateGateArm(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MyScale::activateGateDiode(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MyScale::enableGate(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MyScale::bufferCount(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MyScale::bufferWeight(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}
QT_END_MOC_NAMESPACE
