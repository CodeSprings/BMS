/****************************************************************************
** Meta object code from reading C++ file 'inverter_controlmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BMS/inverter_controlmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inverter_controlmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Inverter_ControlMode_t {
    QByteArrayData data[8];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Inverter_ControlMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Inverter_ControlMode_t qt_meta_stringdata_Inverter_ControlMode = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Inverter_ControlMode"
QT_MOC_LITERAL(1, 21, 37), // "on_Inverter_ControlMode_OkBtn..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 39), // "on_Inverter_ControlMode_QuitB..."
QT_MOC_LITERAL(4, 100, 40), // "on_Constant_Current_Charging_..."
QT_MOC_LITERAL(5, 141, 41), // "on_Constant_Current_Discharge..."
QT_MOC_LITERAL(6, 183, 38), // "on_Constant_Power_Charging_Bt..."
QT_MOC_LITERAL(7, 222, 39) // "on_Constant_Power_Discharge_B..."

    },
    "Inverter_ControlMode\0"
    "on_Inverter_ControlMode_OkBtn_clicked\0"
    "\0on_Inverter_ControlMode_QuitBtn_clicked\0"
    "on_Constant_Current_Charging_Btn_clicked\0"
    "on_Constant_Current_Discharge_Btn_clicked\0"
    "on_Constant_Power_Charging_Btn_clicked\0"
    "on_Constant_Power_Discharge_Btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Inverter_ControlMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Inverter_ControlMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Inverter_ControlMode *_t = static_cast<Inverter_ControlMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Inverter_ControlMode_OkBtn_clicked(); break;
        case 1: _t->on_Inverter_ControlMode_QuitBtn_clicked(); break;
        case 2: _t->on_Constant_Current_Charging_Btn_clicked(); break;
        case 3: _t->on_Constant_Current_Discharge_Btn_clicked(); break;
        case 4: _t->on_Constant_Power_Charging_Btn_clicked(); break;
        case 5: _t->on_Constant_Power_Discharge_Btn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Inverter_ControlMode::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Inverter_ControlMode.data,
      qt_meta_data_Inverter_ControlMode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Inverter_ControlMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Inverter_ControlMode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Inverter_ControlMode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Inverter_ControlMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
