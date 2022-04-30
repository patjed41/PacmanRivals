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
    src/texture-holder/TextureHolder.cpp
    src/map/Tile.cpp
    src/map/Map.cpp
    src/level-manager/LevelManager.cpp
    src/characters/Character.cpp
    src/characters/player/Pacman.cpp
    src/characters/ghosts/Ghost.cpp
    src/characters/ghosts/LinearGhost.cpp
    src/characters/ghosts/RandomGhost.cpp
    src/characters/ghosts/CycleGhost.cpp
    src/coins/Coin.cpp
    src/screens/menu/MenuScreen.cpp
    src/screens/lobby/LobbyScreen.cpp
    src/screens/game/GameScreen.cpp
)

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
    macro(make_new_test TEST_NAME TEST_FOLDER)
        # Creating test executable.
        add_executable(${TEST_NAME} "tests/${TEST_FOLDER}/${TEST_NAME}.cpp" ${ARGN})
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

    # Groups of source files common for many tests:
    set(TEST_FILES
        src/texture-holder/TextureHolder.cpp
    )

    set(CHARACTER_FILES
        ${TEST_FILES}
        src/characters/Character.cpp
        src/map/Map.cpp
        src/map/Tile.cpp
    )

    set(GHOST_FILES
        ${CHARACTER_FILES}
        src/characters/ghosts/Ghost.cpp
        src/characters/ghosts/LinearGhost.cpp
        src/characters/ghosts/CycleGhost.cpp
        src/characters/ghosts/RandomGhost.cpp
    )

    set(PLAYER_FILES
        ${CHARACTER_FILES}
        src/characters/player/Pacman.cpp
    )

    set(LEVEL_FILES
        ${PLAYER_FILES}
        ${GHOST_FILES}
        src/level-manager/LevelManager.cpp
    )

    set(COINS_FILES
        ${TEST_FILES}
        src/coins/Coin.cpp
    )

    # Tests:
    make_new_test(check_initial_positions_players board ${LEVEL_FILES})
    make_new_test(check_initial_board board ${LEVEL_FILES})
    make_new_test(check_correctLeft character ${CHARACTER_FILES})
    make_new_test(check_correctRight character ${CHARACTER_FILES})
    make_new_test(check_correctUp character ${CHARACTER_FILES})
    make_new_test(check_correctDown character ${CHARACTER_FILES})
    make_new_test(check_reachedNewTile character ${CHARACTER_FILES})
    make_new_test(check_turnLeft pacman ${PLAYER_FILES} )
    make_new_test(check_turnRight pacman ${PLAYER_FILES})
    make_new_test(check_turnUp pacman ${PLAYER_FILES})
    make_new_test(check_turnDown pacman ${PLAYER_FILES})
    make_new_test(check_turningBack pacman ${PLAYER_FILES})
    make_new_test(check_move pacman ${PLAYER_FILES})
    make_new_test(check_positionOfTileInNewDirection pacman ${PLAYER_FILES})
    make_new_test(check_positionOfNewTile pacman ${PLAYER_FILES})
    make_new_test(check_update pacman ${PLAYER_FILES})
    make_new_test(check_moveForward ghost ${GHOST_FILES})
    make_new_test(check_getUpTile ghost ${GHOST_FILES})
    make_new_test(check_getDownTile ghost ${GHOST_FILES})
    make_new_test(check_getLeftTile ghost ${GHOST_FILES})
    make_new_test(check_getRightTile ghost ${GHOST_FILES})
    make_new_test(check_getNextTile ghost ${GHOST_FILES})
    make_new_test(check_getOppositeDirection ghost ${GHOST_FILES})
    make_new_test(check_coins coins ${COINS_FILES})

endif()