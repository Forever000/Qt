/****************************************************************************
** Meta object code from reading C++ file 'loginwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CloudMusicPlayer/loginwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_loginWidget_t {
    QByteArrayData data[7];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loginWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loginWidget_t qt_meta_stringdata_loginWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "loginWidget"
QT_MOC_LITERAL(1, 12, 19), // "signal_loginSuccess"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "signal_register_click"
QT_MOC_LITERAL(4, 55, 16), // "signal_loginName"
QT_MOC_LITERAL(5, 72, 16), // "doProcessLoginIn"
QT_MOC_LITERAL(6, 89, 17) // "doProcessRegister"

    },
    "loginWidget\0signal_loginSuccess\0\0"
    "signal_register_click\0signal_loginName\0"
    "doProcessLoginIn\0doProcessRegister"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void loginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loginWidget *_t = static_cast<loginWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_loginSuccess(); break;
        case 1: _t->signal_register_click(); break;
        case 2: _t->signal_loginName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->doProcessLoginIn(); break;
        case 4: _t->doProcessRegister(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (loginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&loginWidget::signal_loginSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (loginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&loginWidget::signal_register_click)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (loginWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&loginWidget::signal_loginName)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject loginWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_loginWidget.data,
      qt_meta_data_loginWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *loginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_loginWidget.stringdata0))
        return static_cast<void*>(const_cast< loginWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int loginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void loginWidget::signal_loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void loginWidget::signal_register_click()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void loginWidget::signal_loginName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
