SOURCES += \
    bucket.cpp \
    droplet.cpp \
    game1scene.cpp \
    main.cpp \
    signupdialog.cpp

RESOURCES += \
    background.qrc \
    projectRes.qrc

HEADERS += \
    bucket.h \
    cloud.h \
    droplet.h \
    game1scene.h \
    signupdialog.h

QT += core gui widgets
QT += sql

QMAKE_LFLAGS += -v
