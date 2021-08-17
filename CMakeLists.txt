cmake_minimum_required(VERSION 3.7.0)

project(optimus-manager-qt VERSION 1.6.3 LANGUAGES CXX DESCRIPTION "An interface for Optimus Manager that allows to switch GPUs on Optimus laptops.")

set(APPLICATION_NAME "Optimus Manager Qt")
set(ORGANIZATION_NAME "Optimus Manager")
set(DESKTOP_FILE io.optimus_manager.OptimusManagerQt.desktop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

option(WITH_PLASMA "Use additional KDE API feautures")

find_package(ECM REQUIRED NO_MODULE)
list(APPEND CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Qt5 5.10 COMPONENTS Widgets DBus LinguistTools REQUIRED)
if(WITH_PLASMA)
    find_package(KF5 COMPONENTS Notifications IconThemes REQUIRED)
endif()

include(ExternalLibraries)
include(ECMInstallIcons)
include(GNUInstallDirs)

qt5_add_translation(QM_FILES
    data/translations/${PROJECT_NAME}_de.ts
    data/translations/${PROJECT_NAME}_es.ts
    data/translations/${PROJECT_NAME}_fi.ts
    data/translations/${PROJECT_NAME}_hu.ts
    data/translations/${PROJECT_NAME}_pt.ts
    data/translations/${PROJECT_NAME}_ro.ts
    data/translations/${PROJECT_NAME}_ru.ts
    data/translations/${PROJECT_NAME}_tr.ts
    data/translations/${PROJECT_NAME}_uk.ts
    data/translations/${PROJECT_NAME}_zh.ts
)

configure_file(src/cmake.h.in cmake.h)
configure_file(data/icons/flags.qrc ${CircleFlags_SOURCE_DIR}/flags/flags.qrc COPYONLY)
configure_file(data/icons/masalla.qrc ${Masalla_SOURCE_DIR}/masalla/masalla.qrc COPYONLY)

add_executable(${PROJECT_NAME}
    ${CircleFlags_SOURCE_DIR}/flags/flags.qrc
    ${Masalla_SOURCE_DIR}/masalla/masalla.qrc
    ${QM_FILES}
    src/appsettings.cpp
    src/daemonclient.cpp
    src/main.cpp
    src/optimusmanager.cpp
    src/optimussettings.cpp
    src/settingsdialog.cpp
    src/settingsdialog.ui
)

target_link_libraries(${PROJECT_NAME} PRIVATE SingleApplication::SingleApplication Qt5::DBus)
if(WITH_PLASMA)
    target_link_libraries(${PROJECT_NAME} PRIVATE KF5::Notifications KF5::IconThemes)
    target_compile_definitions(${PROJECT_NAME} PRIVATE WITH_PLASMA)
endif()

install(TARGETS ${PROJECT_NAME})
install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${ORGANIZATION_NAME}/${APPLICATION_NAME}/translations)
install(FILES data/${DESKTOP_FILE} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications)

# System tray icons cannot be embedded in the application on Linux, so install them to hicolor icons
ecm_install_icons(ICONS
    data/icons/freedesktop/128-apps-optimus-manager.svg
    data/icons/freedesktop/16-apps-optimus-manager.svg
    data/icons/freedesktop/16-status-cpu.svg
    data/icons/freedesktop/16-status-prime-hybrid.svg
    data/icons/freedesktop/16-status-prime-nvidia.svg
    data/icons/freedesktop/22-apps-optimus-manager.svg
    data/icons/freedesktop/22-status-cpu.svg
    data/icons/freedesktop/22-status-prime-hybrid.svg
    data/icons/freedesktop/22-status-prime-nvidia.svg
    data/icons/freedesktop/24-apps-optimus-manager.svg
    data/icons/freedesktop/24-status-cpu.svg
    data/icons/freedesktop/24-status-prime-intel.svg
    data/icons/freedesktop/24-status-prime-nvidia.svg
    data/icons/freedesktop/256-apps-optimus-manager.svg
    data/icons/freedesktop/48-apps-optimus-manager.svg
    data/icons/freedesktop/512-apps-optimus-manager.svg
    data/icons/freedesktop/64-apps-optimus-manager.svg
    data/icons/freedesktop/96-apps-optimus-manager.svg
    data/icons/freedesktop/sc-apps-optimus-manager.svg
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/icons
)
