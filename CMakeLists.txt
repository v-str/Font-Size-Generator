cmake_minimum_required (VERSION 3.9)

set (PROJECT_NAME FontController)
project (${PROJECT_NAME})

enable_testing ()

include_directories (src
                     src/testing_framework
                     lib)


set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory (lib)
add_subdirectory (tests)
