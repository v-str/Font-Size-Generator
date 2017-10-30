cmake_minimum_required(VERSION 3.9)

set (cmake_cxx_standard 11)
set (cmake_automoc ON)
set (cmake_include_current_dir ON)
set (project_name FontController)
project(${project_name})

find_package (Qt5Widgets REQUIRED)

include_directories (test_code library)

set (library_output_path ${project_binary_dir})

add_subdirectory (library)

file (GLOB sources "test_code/*.cpp")

add_executable (${project_name} ${sources})

target_link_libraries (${project_name} library)
