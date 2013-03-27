/****************************************************************************
** Meta object code from reading C++ file 'author.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../author.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'author.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Author[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       8,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      20,    7,    7,    7, 0x05,
      34,    7,    7,    7, 0x05,
      48,    7,    7,    7, 0x05,
      67,    7,    7,    7, 0x05,
      85,    7,    7,    7, 0x05,
     103,    7,    7,    7, 0x05,
     116,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     142,  137,    7,    7, 0x0a,

 // properties: name, type, flags
     169,  161, 0x0a495001,
     172,  161, 0x0a495001,
     177,  161, 0x0a495001,
     182,  161, 0x0a495001,
     192,  161, 0x0a495001,
     201,  161, 0x0a495001,
     215,  210, 0x11495001,
     219,  161, 0x0a495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

static const char qt_meta_stringdata_Author[] = {
    "Author\0\0idChanged()\0slugChanged()\0"
    "nameChanged()\0firstNameChanged()\0"
    "lastNameChanged()\0nicknameChanged()\0"
    "urlChanged()\0descriptionChanged()\0"
    "data\0update(JsonObject)\0QString\0id\0"
    "slug\0name\0firstName\0lastName\0nickname\0"
    "QUrl\0url\0description\0"
};

void Author::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Author *_t = static_cast<Author *>(_o);
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->slugChanged(); break;
        case 2: _t->nameChanged(); break;
        case 3: _t->firstNameChanged(); break;
        case 4: _t->lastNameChanged(); break;
        case 5: _t->nicknameChanged(); break;
        case 6: _t->urlChanged(); break;
        case 7: _t->descriptionChanged(); break;
        case 8: _t->update((*reinterpret_cast< const JsonObject(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Author::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Author::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Author,
      qt_meta_data_Author, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Author::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Author::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Author::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Author))
        return static_cast<void*>(const_cast< Author*>(this));
    return QObject::qt_metacast(_clname);
}

int Author::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = slug(); break;
        case 2: *reinterpret_cast< QString*>(_v) = name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = firstName(); break;
        case 4: *reinterpret_cast< QString*>(_v) = lastName(); break;
        case 5: *reinterpret_cast< QString*>(_v) = nickname(); break;
        case 6: *reinterpret_cast< QUrl*>(_v) = url(); break;
        case 7: *reinterpret_cast< QString*>(_v) = description(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Author::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Author::slugChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Author::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Author::firstNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Author::lastNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Author::nicknameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Author::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Author::descriptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
