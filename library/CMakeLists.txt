cmake_minimum_required (VERSION 3.0)

set (CMAKE_AUTOMOC ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

file (GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library (FontSizeGeneratorLib SHARED "${HEADERS}" "${SOURCES}")
qt5_use_modules (FontSizeGeneratorLib Widgets)

