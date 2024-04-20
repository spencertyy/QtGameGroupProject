SOURCES += \
    bucket.cpp \
    droplet.cpp \
    game1scene.cpp \
    loginpage.cpp \
    main.cpp \
    profile.cpp \
    signupdialog.cpp

RESOURCES += \
    projectRes.qrc \

HEADERS += \
    bucket.h \
    cloud.h \
    droplet.h \
    game1scene.h \
    loginpage.h \
    profile.h \
    signupdialog.h \

QT += core gui widgets
QT += sql

QMAKE_LFLAGS += -v

FORMS += \
    loginpage.ui \
    profile.ui

DISTFILES +=
