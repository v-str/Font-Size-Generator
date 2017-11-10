cmake_minimum_required(VERSION 3.9)

set (cmake_cxx_standard 11)

project(FontController)

set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

file (GLOB sources "*.cpp")

add_library (FontController SHARED ${sources})

qt5_use_modules (FontController Widgets)
