#-------------------------------------------------
#
# Project created by QtCreator 2019-02-24T11:48:52
#
#-------------------------------------------------

QT += core gui widgets dbus x11extras
TARGET = optimus-manager-qt
TEMPLATE = app
CONFIG += c++1z lrelease embed_translations

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
    data/translations/optimus-manager_de.ts \
    data/translations/optimus-manager_es.ts \
    data/translations/optimus-manager_fi.ts \
    data/translations/optimus-manager_hu.ts \
    data/translations/optimus-manager_pt_BR.ts \
    data/translations/optimus-manager_ru.ts \
    data/translations/optimus-manager_tr.ts \
    data/translations/optimus-manager_zh_CN.ts

INSTALLS += \
    bin \
    desktop \
    icon16 \
    icon22 \
    icon24 \
    icon48 \
    icon64 \
    icon96 \
    icon128 \
    icon256 \
    icon512 \
    iconScalable \
    statusIcons16 \
    statusIcons22 \
    statusIcons24 \
    statusIconsScalable

RESOURCES += \
    data/resources.qrc

LIBS += -lXrandr

# Rules for deployment
bin.path = /usr/bin
bin.files = $${TARGET}

desktop.path = /usr/share/applications
desktop.files = dist/io.optimus_manager.OptimusManagerQt.desktop

icon16.path = /usr/share/icons/hicolor/16x16/apps/
icon16.files = dist/icons/16x16/apps/*
icon22.path = /usr/share/icons/hicolor/22x22/apps/
icon22.files = dist/icons/22x22/apps/*
icon24.path = /usr/share/icons/hicolor/24x24/apps/
icon24.files = dist/icons/24x24/apps/*
icon48.path = /usr/share/icons/hicolor/48x48/apps/
icon48.files = dist/icons/48x48/apps/*
icon64.path = /usr/share/icons/hicolor/64x64/apps/
icon64.files = dist/icons/64x64/apps/*
icon96.path = /usr/share/icons/hicolor/96x96/apps/
icon96.files = dist/icons/96x96/apps/*
icon128.path = /usr/share/icons/hicolor/128x128/apps/
icon128.files = dist/icons/128x128/apps/*
icon256.path = /usr/share/icons/hicolor/256x256/apps/
icon256.files = dist/icons/256x256/apps/*
icon512.path = /usr/share/icons/hicolor/512x512/apps/
icon512.files = dist/icons/512x512/apps/*
iconScalable.path = /usr/share/icons/hicolor/scalable/apps/
iconScalable.files = dist/icons/scalable/apps/*

statusIcons16.path = /usr/share/icons/hicolor/16x16/status/
statusIcons16.files = dist/icons/16x16/status/*
statusIcons22.path = /usr/share/icons/hicolor/22x22/status/
statusIcons22.files = dist/icons/22x22/status/*
statusIcons24.path = /usr/share/icons/hicolor/24x24/status/
statusIcons24.files = dist/icons/24x24/status/*
statusIconsScalable.path = /usr/share/icons/hicolor/scalable/status/
statusIconsScalable.files = dist/icons/scalable/status/*
