#-------------------------------------------------
#
# Project created by QtCreator 2019-02-24T11:48:52
#
#-------------------------------------------------

QT += core gui widgets dbus
TARGET = optimus-manager-qt
TEMPLATE = app
CONFIG += c++1z

include(src/third-party/singleapplication/singleapplication.pri)

# Rules for deployment
bin.path = /usr/bin
bin.files = $${TARGET}

desktop.path = /usr/share/applications
desktop.files = dist/optimus-manager-qt.desktop

# Compile translations
system(lrelease $${TARGET}.pro)

#DEFINES += PLASMA
contains(DEFINES, PLASMA){
  QT += KNotifications KIconThemes
}

DEFINES += \
    QAPPLICATION_CLASS=QApplication \
    QT_DEPRECATED_WARNINGS

SOURCES += \
    src/main.cpp \
    src/optimusmanager.cpp \
    src/settingsdialog.cpp \
    src/optimussettings.cpp \
    src/appsettings.cpp \
    src/daemonclient.cpp


HEADERS += \
    src/optimusmanager.h \
    src/settingsdialog.h \
    src/optimussettings.h \
    src/appsettings.h \
    src/daemonclient.h

FORMS += \
    src/settingsdialog.ui

TRANSLATIONS += \
    data/translations/optimus-manager.ts \
    data/translations/optimus-manager_ru.ts \

INSTALLS += \
    bin \
    desktop

RESOURCES += \
    data/resources.qrc
