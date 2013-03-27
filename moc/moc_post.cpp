/****************************************************************************
** Meta object code from reading C++ file 'post.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../post.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'post.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Post[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       9,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      18,    5,    5,    5, 0x05,
      32,    5,    5,    5, 0x05,
      45,    5,    5,    5, 0x05,
      60,    5,    5,    5, 0x05,
      77,    5,    5,    5, 0x05,
      94,    5,    5,    5, 0x05,
     108,    5,    5,    5, 0x05,
     126,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     152,  142,    5,    5, 0x0a,

 // properties: name, type, flags
     198,  190, 0x0a495001,
     201,  190, 0x0a495001,
     211,  206, 0x11495001,
     215,  190, 0x0a495001,
     221,  190, 0x0a495001,
     229,  190, 0x0a495001,
     247,  237, 0x10495001,
     252,  237, 0x10495001,
     269,  261, 0x00495009,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,

       0        // eod
};

static const char qt_meta_stringdata_Post[] = {
    "Post\0\0idChanged()\0slugChanged()\0"
    "urlChanged()\0titleChanged()\0"
    "contentChanged()\0excerptChanged()\0"
    "dateChanged()\0modifiedChanged()\0"
    "authorChanged()\0data,pool\0"
    "update(JsonObject,SharedObjectsPool*)\0"
    "QString\0id\0slug\0QUrl\0url\0title\0content\0"
    "excerpt\0QDateTime\0date\0modified\0Author*\0"
    "author\0"
};

void Post::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Post *_t = static_cast<Post *>(_o);
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->slugChanged(); break;
        case 2: _t->urlChanged(); break;
        case 3: _t->titleChanged(); break;
        case 4: _t->contentChanged(); break;
        case 5: _t->excerptChanged(); break;
        case 6: _t->dateChanged(); break;
        case 7: _t->modifiedChanged(); break;
        case 8: _t->authorChanged(); break;
        case 9: _t->update((*reinterpret_cast< const JsonObject(*)>(_a[1])),(*reinterpret_cast< SharedObjectsPool*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Post::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Post::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Post,
      qt_meta_data_Post, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Post::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Post::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Post::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Post))
        return static_cast<void*>(const_cast< Post*>(this));
    return QObject::qt_metacast(_clname);
}

int Post::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = slug(); break;
        case 2: *reinterpret_cast< QUrl*>(_v) = url(); break;
        case 3: *reinterpret_cast< QString*>(_v) = title(); break;
        case 4: *reinterpret_cast< QString*>(_v) = content(); break;
        case 5: *reinterpret_cast< QString*>(_v) = excerpt(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = date(); break;
        case 7: *reinterpret_cast< QDateTime*>(_v) = modified(); break;
        case 8: *reinterpret_cast< Author**>(_v) = author(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Post::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Post::slugChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Post::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Post::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Post::contentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Post::excerptChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Post::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Post::modifiedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Post::authorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
