/****************************************************************************
** Meta object code from reading C++ file 'tissasearch.h'
**
** Created: Sat Nov 12 11:20:46 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TISSA-Search/tissasearch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tissasearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TISSASearch[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      63,   12,   12,   12, 0x08,
      94,   89,   12,   12, 0x08,
     120,   89,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TISSASearch[] = {
    "TISSASearch\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0text\0"
    "enableFindButton(QString)\0"
    "enableSearchButton(QString)\0"
};

const QMetaObject TISSASearch::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TISSASearch,
      qt_meta_data_TISSASearch, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TISSASearch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TISSASearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TISSASearch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TISSASearch))
        return static_cast<void*>(const_cast< TISSASearch*>(this));
    return QDialog::qt_metacast(_clname);
}

int TISSASearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: on_pushButton_2_clicked(); break;
        case 2: on_pushButton_3_clicked(); break;
        case 3: enableFindButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: enableSearchButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
