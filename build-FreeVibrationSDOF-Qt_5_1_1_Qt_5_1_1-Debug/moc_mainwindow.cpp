/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FreeVibrationSDOF/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 8),
QT_MOC_LITERAL(4, 41, 19),
QT_MOC_LITERAL(5, 61, 18),
QT_MOC_LITERAL(6, 80, 18),
QT_MOC_LITERAL(7, 99, 18),
QT_MOC_LITERAL(8, 118, 20),
QT_MOC_LITERAL(9, 139, 21),
QT_MOC_LITERAL(10, 161, 20),
QT_MOC_LITERAL(11, 182, 21),
QT_MOC_LITERAL(12, 204, 20),
QT_MOC_LITERAL(13, 225, 21),
QT_MOC_LITERAL(14, 247, 21),
QT_MOC_LITERAL(15, 269, 22),
QT_MOC_LITERAL(16, 292, 21),
QT_MOC_LITERAL(17, 314, 22)
    },
    "MainWindow\0on_inV0_sliderMoved\0\0"
    "position\0on_inU0_sliderMoved\0"
    "on_inM_sliderMoved\0on_inK_sliderMoved\0"
    "on_inZ_sliderMoved\0on_inZ_sliderPressed\0"
    "on_inZ_sliderReleased\0on_inK_sliderPressed\0"
    "on_inK_sliderReleased\0on_inM_sliderPressed\0"
    "on_inM_sliderReleased\0on_inU0_sliderPressed\0"
    "on_inU0_sliderReleased\0on_inV0_sliderPressed\0"
    "on_inV0_sliderReleased\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08,
       4,    1,   92,    2, 0x08,
       5,    1,   95,    2, 0x08,
       6,    1,   98,    2, 0x08,
       7,    1,  101,    2, 0x08,
       8,    0,  104,    2, 0x08,
       9,    0,  105,    2, 0x08,
      10,    0,  106,    2, 0x08,
      11,    0,  107,    2, 0x08,
      12,    0,  108,    2, 0x08,
      13,    0,  109,    2, 0x08,
      14,    0,  110,    2, 0x08,
      15,    0,  111,    2, 0x08,
      16,    0,  112,    2, 0x08,
      17,    0,  113,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_inV0_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_inU0_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_inM_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_inK_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_inZ_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_inZ_sliderPressed(); break;
        case 6: _t->on_inZ_sliderReleased(); break;
        case 7: _t->on_inK_sliderPressed(); break;
        case 8: _t->on_inK_sliderReleased(); break;
        case 9: _t->on_inM_sliderPressed(); break;
        case 10: _t->on_inM_sliderReleased(); break;
        case 11: _t->on_inU0_sliderPressed(); break;
        case 12: _t->on_inU0_sliderReleased(); break;
        case 13: _t->on_inV0_sliderPressed(); break;
        case 14: _t->on_inV0_sliderReleased(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
