cmake_minimum_required (VERSION 3.9)

enable_testing ()

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)

set (PROJECT_NAME FontController)
project (${PROJECT_NAME})

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/compilers_flags_helper_functions.cmake")

add_compiler_flags (--coverage)
add_linker_flags (--coverage)

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

include_directories (tests
                     tests/testing_framework
                     library)

add_subdirectory (library)


file (GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
                   "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")

file (GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/tests/testing_framework*.h")

add_executable (${PROJECT_NAME} "${SOURCES}" "${HEADERS}")

target_link_libraries (${PROJECT_NAME} FontControllerLibrary)

add_test (${PROJECT_NAME} ${PROJECT_NAME})


