#-------------------------------------------------
#
# Project created by QtCreator 2019-02-24T11:48:52
#
#-------------------------------------------------

QT += core gui widgets dbus x11extras
TARGET = optimus-manager-qt
TEMPLATE = app
CONFIG += c++1z

include(src/third-party/singleapplication/singleapplication.pri)

DEFINES += \
    QAPPLICATION_CLASS=QApplication \
    QT_DEPRECATED_WARNINGS

#DEFINES += PLASMA
contains(DEFINES, PLASMA){
  QT += KNotifications KIconThemes
}

SOURCES += \
    src/main.cpp \
    src/optimusmanager.cpp \
    src/settingsdialog.cpp \
    src/optimussettings.cpp \
    src/appsettings.cpp \
    src/daemonclient.cpp


HEADERS += \
    src/optimusmanager.h \
    src/session.h \
    src/settingsdialog.h \
    src/optimussettings.h \
    src/appsettings.h \
    src/daemonclient.h \
    src/x11deleters.h

FORMS += \
    src/settingsdialog.ui

TRANSLATIONS += \
    data/translations/optimus-manager.ts \
    data/translations/optimus-manager_zh_CN.ts \
    data/translations/optimus-manager_fi.ts \
    data/translations/optimus-manager_de.ts \
    data/translations/optimus-manager_pt_BR.ts \
    data/translations/optimus-manager_ru.ts \
    data/translations/optimus-manager_es.ts \
    data/translations/optimus-manager_tr.ts \
    data/translations/optimus-manager_hu.ts

INSTALLS += \
    bin \
    desktop \
    icons

RESOURCES += \
    data/resources.qrc

LIBS += -lXrandr

# Rules for deployment
bin.path = /usr/bin
bin.files = $${TARGET}

desktop.path = /usr/share/applications
desktop.files = dist/optimus-manager-qt.desktop

icons.path = /usr/share/icons/hicolor/
icons.files = dist/icons/*

# Compile translations
system(lrelease $${TARGET}.pro)
