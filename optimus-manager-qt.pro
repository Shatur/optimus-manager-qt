#-------------------------------------------------
#
# Project created by QtCreator 2019-02-24T11:48:52
#
#-------------------------------------------------

QT += core gui widgets
TARGET = optimus-manager-qt
TEMPLATE = app
CONFIG += c++1z

include(src/third-party/singleapplication/singleapplication.pri)

# Rules for deployment
bin.path = /usr/bin
bin.files = $${TARGET}

DEFINES += \
    QAPPLICATION_CLASS=QApplication \
    QT_DEPRECATED_WARNINGS

SOURCES += \
    src/main.cpp \
    src/optimusmanager.cpp \
    src/settingsdialog.cpp \
    src/optimussettings.cpp \
    src/appsettings.cpp


HEADERS += \
    src/optimusmanager.h \
    src/settingsdialog.h \
    src/optimussettings.h \
    src/appsettings.h

FORMS += \
    src/settingsdialog.ui

INSTALLS += \
    bin
