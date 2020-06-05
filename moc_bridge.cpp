/****************************************************************************
** Meta object code from reading C++ file 'bridge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bridge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bridge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bridge_t {
    QByteArrayData data[18];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bridge_t qt_meta_stringdata_bridge = {
    {
QT_MOC_LITERAL(0, 0, 6), // "bridge"
QT_MOC_LITERAL(1, 7, 14), // "sigUpdateLight"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "removePoints"
QT_MOC_LITERAL(4, 36, 14), // "sigLightStatus"
QT_MOC_LITERAL(5, 51, 7), // "strName"
QT_MOC_LITERAL(6, 59, 6), // "nvalue"
QT_MOC_LITERAL(7, 66, 9), // "toRecvMsg"
QT_MOC_LITERAL(8, 76, 3), // "msg"
QT_MOC_LITERAL(9, 80, 19), // "targetPointReceived"
QT_MOC_LITERAL(10, 100, 14), // "rotateNavPoint"
QT_MOC_LITERAL(11, 115, 3), // "rot"
QT_MOC_LITERAL(12, 119, 9), // "onLightOn"
QT_MOC_LITERAL(13, 129, 10), // "onLightOff"
QT_MOC_LITERAL(14, 140, 12), // "onUpdateData"
QT_MOC_LITERAL(15, 153, 9), // "jsSendMsg"
QT_MOC_LITERAL(16, 163, 17), // "jsSendTargetPoint"
QT_MOC_LITERAL(17, 181, 12) // "GetLightData"

    },
    "bridge\0sigUpdateLight\0\0removePoints\0"
    "sigLightStatus\0strName\0nvalue\0toRecvMsg\0"
    "msg\0targetPointReceived\0rotateNavPoint\0"
    "rot\0onLightOn\0onLightOff\0onUpdateData\0"
    "jsSendMsg\0jsSendTargetPoint\0GetLightData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bridge[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    2,   76,    2, 0x06 /* Public */,
       7,    1,   81,    2, 0x06 /* Public */,
       9,    1,   84,    2, 0x06 /* Public */,
      10,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   90,    2, 0x0a /* Public */,
      13,    1,   93,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      17,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::QVariantList,

       0        // eod
};

void bridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bridge *_t = static_cast<bridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateLight(); break;
        case 1: _t->removePoints(); break;
        case 2: _t->sigLightStatus((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->toRecvMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->targetPointReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->rotateNavPoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onLightOn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onLightOff((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->onUpdateData(); break;
        case 9: _t->jsSendMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->jsSendTargetPoint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: { QVariantList _r = _t->GetLightData();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (bridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sigUpdateLight)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (bridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::removePoints)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (bridge::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::sigLightStatus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (bridge::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::toRecvMsg)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (bridge::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::targetPointReceived)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (bridge::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::rotateNavPoint)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject bridge::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_bridge.data,
      qt_meta_data_bridge,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *bridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int bridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void bridge::sigUpdateLight()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void bridge::removePoints()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void bridge::sigLightStatus(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void bridge::toRecvMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void bridge::targetPointReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void bridge::rotateNavPoint(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
