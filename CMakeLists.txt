cmake_minimum_required (VERSION 3.9)

enable_testing ()

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)

set (PROJECT_NAME FontController)
project (${PROJECT_NAME})

include_directories (testing_framework
                     library)

add_subdirectory (library)

file (GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable (${PROJECT_NAME} "${SOURCES}")

target_link_libraries (${PROJECT_NAME} FontControllerLibrary)

add_test (${PROJECT_NAME} ${PROJECT_NAME})


