QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clients.cpp \
    databasemanager.cpp \
    main.cpp \
    lab_7_mdi.cpp \
    protocols.cpp \
    sertifications.cpp

HEADERS += \
    clients.h \
    databasemanager.h \
    lab_7_mdi.h \
    protocols.h \
    sertifications.h

FORMS += \
    clients.ui \
    lab_7_mdi.ui \
    protocols.ui \
    sertifications.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BD_gen.py
