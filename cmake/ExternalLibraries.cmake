include(FetchContent)

set(QAPPLICATION_CLASS QApplication)
FetchContent_Declare(SingleApplication
    GIT_REPOSITORY https://github.com/itay-grudev/SingleApplication
    GIT_TAG v3.1.5
)

FetchContent_Declare(CircleFlags
    GIT_REPOSITORY https://github.com/HatScripts/circle-flags
    GIT_TAG v2.0.0
)

FetchContent_Declare(Papirus
    GIT_REPOSITORY https://github.com/PapirusDevelopmentTeam/papirus-icon-theme
    GIT_TAG 20210401
)

FetchContent_MakeAvailable(SingleApplication CircleFlags Papirus)
FetchContent_GetProperties(CircleFlags SOURCE_DIR CircleFlags_SOURCE_DIR)
FetchContent_GetProperties(Papirus SOURCE_DIR Papirus_SOURCE_DIR)
