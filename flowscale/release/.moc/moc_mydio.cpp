/****************************************************************************
** Meta object code from reading C++ file 'mydio.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/mydio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mydio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyDio[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      25,    6,    6,    6, 0x05,
      42,    6,    6,    6, 0x05,
      61,    6,    6,    6, 0x05,
      91,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     122,  120,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyDio[] = {
    "MyDio\0\0inputValue(ulong)\0conveyorSignal()\0"
    "tachoSignal(ulong)\0enteringProductSensorSignal()\0"
    "leavingProductSensorSignal()\0,\0"
    "setOutput(int,int)\0"
};

void MyDio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyDio *_t = static_cast<MyDio *>(_o);
        switch (_id) {
        case 0: _t->inputValue((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 1: _t->conveyorSignal(); break;
        case 2: _t->tachoSignal((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 3: _t->enteringProductSensorSignal(); break;
        case 4: _t->leavingProductSensorSignal(); break;
        case 5: _t->setOutput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyDio::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyDio::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyDio,
      qt_meta_data_MyDio, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyDio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyDio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyDio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyDio))
        return static_cast<void*>(const_cast< MyDio*>(this));
    return QThread::qt_metacast(_clname);
}

int MyDio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyDio::inputValue(unsigned long _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyDio::conveyorSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MyDio::tachoSignal(unsigned long _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyDio::enteringProductSensorSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MyDio::leavingProductSensorSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
