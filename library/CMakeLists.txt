cmake_minimum_required (VERSION 3.9)

set (cmake_automoc ON)
set (cmake_include_current_dir ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

file (GLOB sources "*.cpp")

add_library (library SHARED ${sources})

qt5_use_modules (library Widgets)
