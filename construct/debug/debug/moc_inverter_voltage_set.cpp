/****************************************************************************
** Meta object code from reading C++ file 'inverter_voltage_set.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../BMS/inverter_voltage_set.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inverter_voltage_set.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Inverter_Voltage_Set_t {
    QByteArrayData data[4];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Inverter_Voltage_Set_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Inverter_Voltage_Set_t qt_meta_stringdata_Inverter_Voltage_Set = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Inverter_Voltage_Set"
QT_MOC_LITERAL(1, 21, 37), // "on_set_Inverter_Voltage_OkBtn..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 39) // "on_set_Inverter_Voltage_QuitB..."

    },
    "Inverter_Voltage_Set\0"
    "on_set_Inverter_Voltage_OkBtn_clicked\0"
    "\0on_set_Inverter_Voltage_QuitBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Inverter_Voltage_Set[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Inverter_Voltage_Set::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Inverter_Voltage_Set *_t = static_cast<Inverter_Voltage_Set *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_set_Inverter_Voltage_OkBtn_clicked(); break;
        case 1: _t->on_set_Inverter_Voltage_QuitBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Inverter_Voltage_Set::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Inverter_Voltage_Set.data,
      qt_meta_data_Inverter_Voltage_Set,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Inverter_Voltage_Set::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Inverter_Voltage_Set::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Inverter_Voltage_Set.stringdata0))
        return static_cast<void*>(const_cast< Inverter_Voltage_Set*>(this));
    return QDialog::qt_metacast(_clname);
}

int Inverter_Voltage_Set::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
