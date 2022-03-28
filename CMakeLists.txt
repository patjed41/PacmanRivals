cmake_minimum_required(VERSION 3.10.2)

project(PacmanRivals)

set(CMAKE_CXX_STANDARD 17)

# Release is a default build type.
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()
# -DNDEBUG flag is set in Release build type.
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-DNDEBUG")
endif()

set(SOURCE_FILES
        src/engine/GameEngine.cpp
        src/engine/Input.cpp
        src/engine/Update.cpp
        src/engine/Draw.cpp
        src/texture-holder/TextureHolder.cpp
        src/map/Tile.cpp
        src/map/Map.cpp
        src/level-manager/LevelManager.cpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Creating game executable.
add_executable(PacmanRivals app/PacmanRivals.cpp ${SOURCE_FILES})
# Linking SFML libraries to game executable.
target_link_libraries(PacmanRivals sfml-graphics sfml-window sfml-system sfml-audio)

# Tests with code coverage run in Debug build type.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # setting flags required for Debug
    SET(CMAKE_CXX_FLAGS= "-g -O0 -Wall -W -Wshadow -Wunused-variable
    -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers
    -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fprofile-arcs
    -ftest-coverage")

    include(CTest)

    enable_testing()

    # Macro that allows tests to be easily added (usage below).
    macro(make_new_test TEST_NAME)
        # Creating test executable.
        add_executable(${TEST_NAME} ${ARGN})
        # Setting flags required for code coverage.
        target_compile_options(${TEST_NAME} PUBLIC "-O0" "-fprofile-arcs" "-ftest-coverage")
        # Linking gcov - library that handles code coverage.
        target_link_libraries(${TEST_NAME} gcov)
        # Linking SFML libraries to test executable.
        target_link_libraries(${TEST_NAME} sfml-graphics sfml-window sfml-system sfml-audio)
        # Adding test to project run by ctest.
        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${PROJECT_DIR})
        # Test will fail if output has prefix "FAIL" (check include/err.h).
        set_tests_properties(${TEST_NAME} PROPERTIES FAIL_REGULAR_EXPRESSION "^FAIL")
    endmacro()

    # Tests:
    make_new_test(check_initial_positions tests/board/check_initial_positions_players.cpp src/level-manager/LevelManager.cpp src/map/Map.cpp src/map/Tile.cpp src/texture-holder/TextureHolder.cpp)
    make_new_test(check_initial_board tests/board/check_initial_board.cpp src/level-manager/LevelManager.cpp src/map/Map.cpp src/map/Tile.cpp src/texture-holder/TextureHolder.cpp)

endif()