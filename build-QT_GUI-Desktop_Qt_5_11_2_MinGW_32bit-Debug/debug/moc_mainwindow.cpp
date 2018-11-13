/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Qt_PP_1819_GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_pushButton_got_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 28), // "on_pushButton_crypto_clicked"
QT_MOC_LITERAL(4, 67, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 89, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(6, 111, 4), // "arg1"
QT_MOC_LITERAL(7, 116, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(8, 140, 14), // "matrix_display"
QT_MOC_LITERAL(9, 155, 20), // "vector<vector<int> >"
QT_MOC_LITERAL(10, 176, 6), // "matrix"
QT_MOC_LITERAL(11, 183, 6), // "height"
QT_MOC_LITERAL(12, 190, 6), // "length"
QT_MOC_LITERAL(13, 197, 22), // "on_save_button_clicked"
QT_MOC_LITERAL(14, 220, 26), // "on_rand_mat_button_clicked"
QT_MOC_LITERAL(15, 247, 30) // "on_change_pixel_button_clicked"

    },
    "MainWindow\0on_pushButton_got_clicked\0"
    "\0on_pushButton_crypto_clicked\0"
    "on_pushButton_clicked\0on_comboBox_activated\0"
    "arg1\0on_spinBox_valueChanged\0"
    "matrix_display\0vector<vector<int> >\0"
    "matrix\0height\0length\0on_save_button_clicked\0"
    "on_rand_mat_button_clicked\0"
    "on_change_pixel_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       8,    3,   68,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_got_clicked(); break;
        case 1: _t->on_pushButton_crypto_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_spinBox_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->matrix_display((*reinterpret_cast< vector<vector<int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->on_save_button_clicked(); break;
        case 7: _t->on_rand_mat_button_clicked(); break;
        case 8: _t->on_change_pixel_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
