/****************************************************************************
** Meta object code from reading C++ file 'dialogsetting1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CloudMusicPlayer/dialogsetting1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsetting1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dialogSetting1_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialogSetting1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialogSetting1_t qt_meta_stringdata_dialogSetting1 = {
    {
QT_MOC_LITERAL(0, 0, 14), // "dialogSetting1"
QT_MOC_LITERAL(1, 15, 11), // "engineChose"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "index"
QT_MOC_LITERAL(4, 34, 23), // "doProcessbuttonBoxClick"
QT_MOC_LITERAL(5, 58, 16), // "QAbstractButton*"
QT_MOC_LITERAL(6, 75, 18), // "doProcessTakePhoto"
QT_MOC_LITERAL(7, 94, 16) // "doProcessOpenPic"

    },
    "dialogSetting1\0engineChose\0\0index\0"
    "doProcessbuttonBoxClick\0QAbstractButton*\0"
    "doProcessTakePhoto\0doProcessOpenPic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialogSetting1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialogSetting1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialogSetting1 *_t = static_cast<dialogSetting1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->engineChose((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->doProcessbuttonBoxClick((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: _t->doProcessTakePhoto(); break;
        case 3: _t->doProcessOpenPic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (dialogSetting1::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dialogSetting1::engineChose)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject dialogSetting1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialogSetting1.data,
      qt_meta_data_dialogSetting1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dialogSetting1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialogSetting1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dialogSetting1.stringdata0))
        return static_cast<void*>(const_cast< dialogSetting1*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialogSetting1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
int dialogSetting1::engineChose(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
