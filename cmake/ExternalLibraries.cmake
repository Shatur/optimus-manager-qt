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

FetchContent_Declare(Masalla
    GIT_REPOSITORY https://github.com/masalla-art/masalla-icon-theme
    GIT_TAG d3d3e90b6f36d3641e24e39f283a672ad5462a50
)

FetchContent_MakeAvailable(SingleApplication CircleFlags Masalla)
FetchContent_GetProperties(CircleFlags SOURCE_DIR CircleFlags_SOURCE_DIR)
FetchContent_GetProperties(Masalla SOURCE_DIR Masalla_SOURCE_DIR)
