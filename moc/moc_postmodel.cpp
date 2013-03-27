/****************************************************************************
** Meta object code from reading C++ file 'postmodel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../postmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'postmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PostModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       5,   69, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      26,   10,   10,   10, 0x05,
      43,   10,   10,   10, 0x05,
      58,   10,   10,   10, 0x05,
      71,   10,   10,   10, 0x05,
      87,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,   96,   10,   10, 0x0a,
     120,  113,   10,   10, 0x0a,
     139,   10,   10,   10, 0x0a,
     146,   10,   10,   10, 0x0a,
     157,   10,   10,   10, 0x08,

 // properties: name, type, flags
     176,  172, 0x02495001,
     187,  182, 0x01495001,
     203,  195, 0x0a495001,
      96,  209, 0x11495103,
     113,  195, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

static const char qt_meta_stringdata_PostModel[] = {
    "PostModel\0\0countChanged()\0loadingChanged()\0"
    "errorChanged()\0apiChanged()\0methodChanged()\0"
    "loaded()\0api\0setApi(QUrl)\0method\0"
    "setMethod(QString)\0load()\0loadMore()\0"
    "slotFinished()\0int\0count\0bool\0loading\0"
    "QString\0error\0QUrl\0"
};

void PostModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PostModel *_t = static_cast<PostModel *>(_o);
        switch (_id) {
        case 0: _t->countChanged(); break;
        case 1: _t->loadingChanged(); break;
        case 2: _t->errorChanged(); break;
        case 3: _t->apiChanged(); break;
        case 4: _t->methodChanged(); break;
        case 5: _t->loaded(); break;
        case 6: _t->setApi((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 7: _t->setMethod((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->load(); break;
        case 9: _t->loadMore(); break;
        case 10: _t->slotFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PostModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PostModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_PostModel,
      qt_meta_data_PostModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PostModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PostModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PostModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PostModel))
        return static_cast<void*>(const_cast< PostModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int PostModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = count(); break;
        case 1: *reinterpret_cast< bool*>(_v) = loading(); break;
        case 2: *reinterpret_cast< QString*>(_v) = error(); break;
        case 3: *reinterpret_cast< QUrl*>(_v) = api(); break;
        case 4: *reinterpret_cast< QString*>(_v) = method(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: setApi(*reinterpret_cast< QUrl*>(_v)); break;
        case 4: setMethod(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PostModel::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PostModel::loadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void PostModel::errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void PostModel::apiChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void PostModel::methodChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void PostModel::loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
