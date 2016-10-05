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
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      29,    8,    8,    8, 0x05,
      53,    8,    8,    8, 0x05,
      72,    8,    8,    8, 0x05,
      86,    8,    8,    8, 0x05,
     102,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,    8,    8,    8, 0x0a,
     149,    8,    8,    8, 0x0a,
     179,    8,    8,    8, 0x0a,
     208,    8,    8,    8, 0x0a,
     229,    8,    8,    8, 0x0a,
     243,    8,    8,    8, 0x0a,
     257,    8,    8,    8, 0x0a,
     271,    8,    8,    8, 0x0a,
     285,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyScale[] = {
    "MyScale\0\0receivedWeight(int)\0"
    "sendFilteredWeight(int)\0sendDebugData(int)\0"
    "plotData(int)\0plotWeight(int)\0"
    "requestNewRecipe(QString)\0"
    "conveyorBeltSignal()\0enteringProductSensorSignal()\0"
    "leavingProductSensorSignal()\0"
    "modelZeroWeight(int)\0xmin(QString)\0"
    "xmax(QString)\0ymin(QString)\0ymax(QString)\0"
    "updateRecipe(QString)\0"
};

void MyScale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyScale *_t = static_cast<MyScale *>(_o);
        switch (_id) {
        case 0: _t->receivedWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendFilteredWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendDebugData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->plotData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->plotWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->requestNewRecipe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->conveyorBeltSignal(); break;
        case 7: _t->enteringProductSensorSignal(); break;
        case 8: _t->leavingProductSensorSignal(); break;
        case 9: _t->modelZeroWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->xmin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->xmax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->ymin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->ymax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->updateRecipe((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MyScale::receivedWeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyScale::sendFilteredWeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyScale::sendDebugData(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyScale::plotData(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyScale::plotWeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyScale::requestNewRecipe(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
