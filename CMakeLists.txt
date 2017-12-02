cmake_minimum_required (VERSION 3.0)

set (PROJECT_NAME FontSizeGenerator)
project (${PROJECT_NAME})

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)

set (CMAKE_AUTOMOC ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

include_directories (library)

file (GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/library/*.h")
file (GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/library*.cpp")

add_library (FontSizeGeneratorLib SHARED "${HEADERS}" "${SOURCES}")
qt5_use_modules (FontSizeGeneratorLib Widgets)



