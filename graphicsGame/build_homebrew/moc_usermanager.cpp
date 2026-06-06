/****************************************************************************
** Meta object code from reading C++ file 'usermanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usermanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11UserManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto UserManager::qt_create_metaobjectdata<qt_meta_tag_ZN11UserManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "UserManager",
        "userAuthenticated",
        "",
        "UserInfo*",
        "user",
        "userAuthenticationFailed",
        "userNameTaken",
        "userSignedUp",
        "userInfo",
        "authenticateUser",
        "userName",
        "password",
        "signUpUser",
        "UserRequest*",
        "userRequest"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'userAuthenticated'
        QtMocHelpers::SignalData<void(UserInfo *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'userAuthenticationFailed'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'userNameTaken'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'userSignedUp'
        QtMocHelpers::SignalData<void(UserInfo *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 8 },
        }}),
        // Slot 'authenticateUser'
        QtMocHelpers::SlotData<void(QString, QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 11 },
        }}),
        // Slot 'signUpUser'
        QtMocHelpers::SlotData<void(UserRequest *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<UserManager, qt_meta_tag_ZN11UserManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject UserManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11UserManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11UserManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11UserManagerE_t>.metaTypes,
    nullptr
} };

void UserManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UserManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->userAuthenticated((*reinterpret_cast<std::add_pointer_t<UserInfo*>>(_a[1]))); break;
        case 1: _t->userAuthenticationFailed(); break;
        case 2: _t->userNameTaken(); break;
        case 3: _t->userSignedUp((*reinterpret_cast<std::add_pointer_t<UserInfo*>>(_a[1]))); break;
        case 4: _t->authenticateUser((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->signUpUser((*reinterpret_cast<std::add_pointer_t<UserRequest*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UserManager::*)(UserInfo * )>(_a, &UserManager::userAuthenticated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (UserManager::*)()>(_a, &UserManager::userAuthenticationFailed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (UserManager::*)()>(_a, &UserManager::userNameTaken, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (UserManager::*)(UserInfo * )>(_a, &UserManager::userSignedUp, 3))
            return;
    }
}

const QMetaObject *UserManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11UserManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UserManager::userAuthenticated(UserInfo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void UserManager::userAuthenticationFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UserManager::userNameTaken()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UserManager::userSignedUp(UserInfo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
