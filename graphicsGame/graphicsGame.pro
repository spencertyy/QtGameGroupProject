SOURCES += \
    bucket.cpp \
    droplet.cpp \
    game1scene.cpp \
    gameoverdialog.cpp \
    loginpage.cpp \
    main.cpp \
    profile.cpp \
    signupdialog.cpp \
    usermanager.cpp

RESOURCES += \
    background.qrc \
    projectRes.qrc \
    rainingMen.qrc

HEADERS += \
    bucket.h \
    cloud.h \
    droplet.h \
    game1scene.h \
    gameoverdialog.h \
    loginpage.h \
    profile.h \
    signupdialog.h \
    usermanager.h

QT += core gui widgets
QT += sql
QT += multimedia

QMAKE_LFLAGS += -v

FORMS += \
    loginpage.ui \
    profile.ui

DISTFILES +=
