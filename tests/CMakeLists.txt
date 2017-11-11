include_directories (src src/testing_framework)

file (GLOB_RECURSE FONT_CONTROLLER_TESTS_APPLICATION_HEADERS
                   "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

file (GLOB_RECURSE FONT_CONTROLLER_TESTS_APPLICATION_SOURCES
                   "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable (FontControllerTests
                "${FONT_CONTROLLER_TESTS_APPLICATION_HEADERS}"
                "${FONT_CONTROLLER_TESTS_APPLICATION_SOURCES}")

target_link_libraries (FontControllerTests FontController)

add_test (FontControllerTests FontControllerTests)
