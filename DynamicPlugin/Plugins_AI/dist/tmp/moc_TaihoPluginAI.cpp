/****************************************************************************
** Meta object code from reading C++ file 'TaihoPluginAI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../impl/TaihoPluginAI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaihoPluginAI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TaihoPluginAI_t {
    QByteArrayData data[4];
    char stringdata[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TaihoPluginAI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TaihoPluginAI_t qt_meta_stringdata_TaihoPluginAI = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 16),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 15)
    },
    "TaihoPluginAI\0sendMsgToManager\0\0"
    "TaihoPluginData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaihoPluginAI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void TaihoPluginAI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TaihoPluginAI *_t = static_cast<TaihoPluginAI *>(_o);
        switch (_id) {
        case 0: _t->sendMsgToManager((*reinterpret_cast< TaihoPluginData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaihoPluginData >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TaihoPluginAI::*_t)(TaihoPluginData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TaihoPluginAI::sendMsgToManager)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TaihoPluginAI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaihoPluginAI.data,
      qt_meta_data_TaihoPluginAI,  qt_static_metacall, 0, 0}
};


const QMetaObject *TaihoPluginAI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaihoPluginAI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TaihoPluginAI.stringdata))
        return static_cast<void*>(const_cast< TaihoPluginAI*>(this));
    if (!strcmp(_clname, "TaihoPluginInterface"))
        return static_cast< TaihoPluginInterface*>(const_cast< TaihoPluginAI*>(this));
    if (!strcmp(_clname, "com.taiho.core.TaihoPluginInterface"))
        return static_cast< TaihoPluginInterface*>(const_cast< TaihoPluginAI*>(this));
    return QWidget::qt_metacast(_clname);
}

int TaihoPluginAI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TaihoPluginAI::sendMsgToManager(TaihoPluginData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    0x71, 0x62, 0x6a, 0x73, 0x01, 0x00, 0x00, 0x00,
    0xac, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x98, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 0x49, 0x49, 0x44, 0x00, 0x00, 0x00,
    0x23, 0x00, 0x63, 0x6f, 0x6d, 0x2e, 0x74, 0x61,
    0x69, 0x68, 0x6f, 0x2e, 0x63, 0x6f, 0x72, 0x65,
    0x2e, 0x54, 0x61, 0x69, 0x68, 0x6f, 0x50, 0x6c,
    0x75, 0x67, 0x69, 0x6e, 0x49, 0x6e, 0x74, 0x65,
    0x72, 0x66, 0x61, 0x63, 0x65, 0x00, 0x00, 0x00,
    0x1b, 0x0a, 0x00, 0x00, 0x09, 0x00, 0x63, 0x6c,
    0x61, 0x73, 0x73, 0x4e, 0x61, 0x6d, 0x65, 0x00,
    0x0d, 0x00, 0x54, 0x61, 0x69, 0x68, 0x6f, 0x50,
    0x6c, 0x75, 0x67, 0x69, 0x6e, 0x41, 0x49, 0x00,
    0x3a, 0x20, 0xa0, 0x00, 0x07, 0x00, 0x76, 0x65,
    0x72, 0x73, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 0x64, 0x65,
    0x62, 0x75, 0x67, 0x00, 0x95, 0x11, 0x00, 0x00,
    0x08, 0x00, 0x4d, 0x65, 0x74, 0x61, 0x44, 0x61,
    0x74, 0x61, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x60, 0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    0x71, 0x62, 0x6a, 0x73, 0x01, 0x00, 0x00, 0x00,
    0xac, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x98, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 0x49, 0x49, 0x44, 0x00, 0x00, 0x00,
    0x23, 0x00, 0x63, 0x6f, 0x6d, 0x2e, 0x74, 0x61,
    0x69, 0x68, 0x6f, 0x2e, 0x63, 0x6f, 0x72, 0x65,
    0x2e, 0x54, 0x61, 0x69, 0x68, 0x6f, 0x50, 0x6c,
    0x75, 0x67, 0x69, 0x6e, 0x49, 0x6e, 0x74, 0x65,
    0x72, 0x66, 0x61, 0x63, 0x65, 0x00, 0x00, 0x00,
    0x15, 0x0a, 0x00, 0x00, 0x08, 0x00, 0x4d, 0x65,
    0x74, 0x61, 0x44, 0x61, 0x74, 0x61, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x9b, 0x0d, 0x00, 0x00,
    0x09, 0x00, 0x63, 0x6c, 0x61, 0x73, 0x73, 0x4e,
    0x61, 0x6d, 0x65, 0x00, 0x0d, 0x00, 0x54, 0x61,
    0x69, 0x68, 0x6f, 0x50, 0x6c, 0x75, 0x67, 0x69,
    0x6e, 0x41, 0x49, 0x00, 0x31, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x64, 0x65, 0x62, 0x75, 0x67, 0x00,
    0x3a, 0x20, 0xa0, 0x00, 0x07, 0x00, 0x76, 0x65,
    0x72, 0x73, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x5c, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00,
    0x88, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(TaihoPluginAI, TaihoPluginAI)

QT_END_MOC_NAMESPACE
