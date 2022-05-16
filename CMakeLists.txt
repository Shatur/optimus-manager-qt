cmake_minimum_required(VERSION 3.7.0)

project(optimus-manager-qt
    VERSION 1.6.8
    LANGUAGES CXX
    DESCRIPTION "An interface for Optimus Manager that allows to switch GPUs on Optimus laptops."
)

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

find_package(Qt5 5.10 COMPONENTS Widgets DBus X11Extras LinguistTools REQUIRED)
if(WITH_PLASMA)
    find_package(KF5 COMPONENTS Notifications IconThemes REQUIRED)
endif()

include(ECMInstallIcons)
include(GNUInstallDirs)

set(QAPPLICATION_CLASS QApplication)
add_subdirectory(src/third-party/singleapplication)

qt5_add_translation(QM_FILES
    data/translations/${PROJECT_NAME}_de_DE.ts
    data/translations/${PROJECT_NAME}_es_ES.ts
    data/translations/${PROJECT_NAME}_fi_FI.ts
    data/translations/${PROJECT_NAME}_hu_HU.ts
    data/translations/${PROJECT_NAME}_ja_JP.ts
    data/translations/${PROJECT_NAME}_nl_NL.ts
    data/translations/${PROJECT_NAME}_pt_BR.ts
    data/translations/${PROJECT_NAME}_ro_RO.ts
    data/translations/${PROJECT_NAME}_ru_RU.ts
    data/translations/${PROJECT_NAME}_tr_TR.ts
    data/translations/${PROJECT_NAME}_uk_UA.ts
    data/translations/${PROJECT_NAME}_zh_CN.ts
)

configure_file(src/cmake.h.in cmake.h)

add_executable(${PROJECT_NAME}
    ${QM_FILES}
    data/icons/flags.qrc
    data/icons/icon-theme.qrc
    src/daemonclient.cpp
    src/main.cpp
    src/optimusmanager.cpp
    src/settings/appsettings.cpp
    src/settings/autostartmanager/abstractautostartmanager.cpp
    src/settings/autostartmanager/portalautostartmanager.cpp
    src/settings/autostartmanager/unixautostartmanager.cpp
    src/settings/optimussettings.cpp
    src/settings/settingsdialog.cpp
    src/settings/settingsdialog.ui
    src/xdgdesktopportal.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE SingleApplication::SingleApplication Qt5::DBus Qt5::X11Extras)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
if(WITH_PLASMA)
    target_link_libraries(${PROJECT_NAME} PRIVATE KF5::Notifications KF5::IconThemes)
    target_compile_definitions(${PROJECT_NAME} PRIVATE WITH_PLASMA)
endif()

install(TARGETS ${PROJECT_NAME})
install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${ORGANIZATION_NAME}/${APPLICATION_NAME}/translations)
install(FILES data/${DESKTOP_FILE} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications)

# System tray icons cannot be embedded in the application on Linux, so install them to hicolor icons
ecm_install_icons(ICONS
    data/icons/app/128-apps-optimus-manager.svg
    data/icons/app/16-apps-optimus-manager.svg
    data/icons/app/16-status-cpu.svg
    data/icons/app/16-status-prime-hybrid.svg
    data/icons/app/16-status-prime-nvidia.svg
    data/icons/app/22-apps-optimus-manager.svg
    data/icons/app/22-status-cpu.svg
    data/icons/app/22-status-prime-hybrid.svg
    data/icons/app/22-status-prime-nvidia.svg
    data/icons/app/24-apps-optimus-manager.svg
    data/icons/app/24-status-cpu.svg
    data/icons/app/24-status-prime-intel.svg
    data/icons/app/24-status-prime-nvidia.svg
    data/icons/app/256-apps-optimus-manager.svg
    data/icons/app/48-apps-optimus-manager.svg
    data/icons/app/512-apps-optimus-manager.svg
    data/icons/app/64-apps-optimus-manager.svg
    data/icons/app/96-apps-optimus-manager.svg
    data/icons/app/sc-apps-optimus-manager.svg
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/icons
)
