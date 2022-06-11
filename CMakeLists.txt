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
    src/sound-manager/SoundManager.cpp
    src/map/Tile.cpp
    src/map/Map.cpp
    src/level-manager/LevelManager.cpp
    src/characters/Character.cpp
    src/characters/player/Pacman.cpp
    src/characters/ghosts/Ghost.cpp
    src/characters/ghosts/LinearGhost.cpp
    src/characters/ghosts/RandomGhost.cpp
    src/characters/ghosts/CycleGhost.cpp
    src/characters/menu-character/MenuCharacter.cpp
    src/coins/Coin.cpp
    src/screens/menu/MenuScreen.cpp
    src/screens/controls/ControlsScreen.cpp
    src/screens/settings/SettingsScreen.cpp
    src/screens/lobby/LobbyScreen.cpp
    src/screens/lobby/options/Options.cpp
    src/screens/lobby/options/Selector.cpp
    src/screens/lobby/options/game/GameOptions.cpp
    src/screens/lobby/options/game/PlayersSelector.cpp
    src/screens/lobby/options/game/RoundsSelector.cpp
    src/screens/lobby/options/game/ControllerChecker.cpp
    src/screens/lobby/options/player/PlayerOptions.cpp
    src/screens/lobby/options/player/NickSelector.cpp
    src/screens/lobby/options/player/ColorSelector.cpp
    src/screens/lobby/options/player/ControlSelector.cpp
    src/screens/lobby/buttons/ButtonAD.cpp
    src/screens/game/GameScreen.cpp
    src/screens/game/PlayerInfo.cpp
    src/screens/game/PlayerInputHandler.cpp
    src/screens/game/PlayerStats.cpp
    src/screens/between-rounds/BetweenRoundsScreen.cpp
    src/screens/between-rounds/ScorePrinter.cpp
    src/screens/game-over/GameOverScreen.cpp
    src/screens/game-over/WinnerPrinter.cpp
    src/power-ups/PowerUp.cpp
    src/power-ups/PowerUpSpawner.cpp
    src/power-ups/types/slow_down/SlowDown.cpp
    src/power-ups/types/speed_up/SpeedUp.cpp
    src/power-ups/types/firing-bullet/FiringBullet.cpp
    src/power-ups/types/firing-bullet/Bullet.cpp
    src/power-ups/types/spikes-placement/SpikesPlacement.cpp
    src/power-ups/types/spikes-placement/Spike.cpp
    src/power-ups/types/shield/Shield.cpp
    src/power-ups/types/passing_walls/PassWall.cpp
    src/power-ups/types/gluttony/Gluttony.cpp
    src/power-ups/types/bomb-placement/BombPlacement.cpp
    src/power-ups/types/bomb-placement/Bomb.cpp
    src/power-ups/types/coin-multiplier/CoinMultiplier.cpp
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Creating game executable.
add_executable(PacmanRivals app/PacmanRivals.cpp ${SOURCE_FILES})
# Linking SFML libraries to game executable.
target_link_libraries(PacmanRivals sfml-graphics sfml-window sfml-system sfml-audio)

# Tests with code coverage run in Debug build type.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Setting flags required for Debug.
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
        src/sound-manager/SoundManager.cpp
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
        src/power-ups/types/firing-bullet/Bullet.cpp
        src/power-ups/types/spikes-placement/Spike.cpp
        src/power-ups/types/bomb-placement/Bomb.cpp
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

    set(SCREEN_FILES
        ${TEST_FILES}
        src/screens/Screen.h
    )

    set(BETWEEN_ROUNDS_SCREEN_FILES
        ${SCREEN_FILES}
        src/screens/between-rounds/BetweenRoundsScreen.cpp
        src/screens/between-rounds/ScorePrinter.cpp
        src/screens/game/PlayerInfo.cpp
    )

    set(GAME_OVER_SCREEN_FILES
        ${SCREEN_FILES}
        src/screens/game-over/GameOverScreen.cpp
        src/screens/game-over/WinnerPrinter.cpp
        src/screens/game/PlayerInfo.cpp
    )

    set(SETTINGS_SCREEN_FILES
        ${SCREEN_FILES}
        src/screens/settings/SettingsScreen.cpp
    )

    set(SELECTOR_FILES
        ${TEST_FILES}
        src/screens/lobby/options/Selector.cpp
        src/screens/lobby/buttons/ButtonAD.cpp
    )

    set(OPTIONS_FILES
        ${SELECTOR_FILES}
        src/screens/lobby/options/Options.cpp
    )

    set(GAME_OPTIONS_FILES
        ${OPTIONS_FILES}
        src/screens/lobby/options/game/GameOptions.cpp
        src/screens/lobby/options/game/PlayersSelector.cpp
        src/screens/lobby/options/game/RoundsSelector.cpp
        src/screens/lobby/options/game/ControllerChecker.cpp
    )

    set(PLAYER_OPTIONS_FILES
        ${OPTIONS_FILES}
        src/screens/lobby/options/player/PlayerOptions.cpp
        src/screens/lobby/options/player/NickSelector.cpp
        src/screens/lobby/options/player/ColorSelector.cpp
        src/screens/lobby/options/player/ControlSelector.cpp
        src/screens/game/PlayerInfo.cpp
    )

    set(LOBBY_SCREEN_FILES
        ${GAME_OPTIONS_FILES}
        ${PLAYER_OPTIONS_FILES}
        src/screens/lobby/LobbyScreen.cpp
        src/screens/game/PlayerInfo.cpp
    )

    set(POWER_UP_SPAWNER_FILES
        ${PLAYER_FILES}
        src/power-ups/PowerUpSpawner.cpp
        src/power-ups/PowerUp.cpp
        src/power-ups/types/speed_up/SpeedUp.cpp
        src/power-ups/types/slow_down/SlowDown.cpp
        src/power-ups/types/firing-bullet/FiringBullet.cpp
        src/power-ups/types/shield/Shield.cpp
        src/power-ups/types/passing_walls/PassWall.cpp
        src/power-ups/types/gluttony/Gluttony.cpp
        src/power-ups/types/bomb-placement/BombPlacement.cpp
        src/power-ups/types/spikes-placement/SpikesPlacement.cpp
        src/power-ups/types/coin-multiplier/CoinMultiplier.cpp
    )

    set(GAME_SCREEN_FILES
        ${SCREEN_FILES}
        ${LEVEL_FILES}
        ${COINS_FILES}
        ${POWER_UP_SPAWNER_FILES}
        src/screens/game/GameScreen.cpp
        src/screens/game/PlayerInputHandler.cpp
        src/screens/game/PlayerInfo.cpp
        src/screens/game/PlayerStats.cpp
    )

    set(CONTROLS_SCREEN_FILES
        ${SCREEN_FILES}
        src/screens/controls/ControlsScreen.cpp
    )

    set(FIRING_BULLET_FILES
        ${PLAYER_FILES}
        src/power-ups/types/firing-bullet/FiringBullet.cpp
    )

    set(BOMB_PLACEMENT_FILES
        ${PLAYER_FILES}
        src/power-ups/types/bomb-placement/BombPlacement.cpp
    )

    set(SPIKE_PLACEMENT_FILES
        ${PLAYER_FILES}
        src/power-ups/types/spikes-placement/SpikesPlacement.cpp
    )

    # Tests:
    make_new_test(check_initial_board board ${LEVEL_FILES})
    make_new_test(check_different_levels board ${LEVEL_FILES})
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
    make_new_test(check_ad_button AD-button ${TEST_FILES} src/screens/lobby/buttons/ButtonAD.cpp)
    make_new_test(check_one_player_auto_win game-screen ${GAME_SCREEN_FILES})
    make_new_test(check_players_selector players-selector ${SELECTOR_FILES} src/screens/lobby/options/game/PlayersSelector.cpp)
    make_new_test(check_rounds_selector rounds-selector ${SELECTOR_FILES} src/screens/lobby/options/game/RoundsSelector.cpp)
    make_new_test(check_nick_selector nick-selector ${SELECTOR_FILES} src/screens/lobby/options/player/NickSelector.cpp)
    make_new_test(check_control_selector control-selector ${SELECTOR_FILES} src/screens/lobby/options/player/ControlSelector.cpp)
    make_new_test(check_color_selector color-selector ${SELECTOR_FILES} src/screens/lobby/options/player/ColorSelector.cpp)
    make_new_test(check_game_options game-options ${GAME_OPTIONS_FILES})
    make_new_test(check_player_options player-options ${PLAYER_OPTIONS_FILES})
    make_new_test(check_menu_screen menu-screen ${SCREEN_FILES} src/screens/menu/MenuScreen.cpp)
    make_new_test(check_controls_screen controls-screen ${CONTROLS_SCREEN_FILES})
    make_new_test(check_settings_screen settings-screen ${SETTINGS_SCREEN_FILES})
    make_new_test(check_between_rounds_screen between-rounds-screen ${BETWEEN_ROUNDS_SCREEN_FILES})
    make_new_test(check_game_over_screen game-over-screen ${GAME_OVER_SCREEN_FILES})
    make_new_test(check_lobby_screen lobby-screen ${LOBBY_SCREEN_FILES})
    make_new_test(check_power_up_spawner power-up-spawner ${POWER_UP_SPAWNER_FILES})
    make_new_test(check_slow_down speed-up-down ${PLAYER_FILES} src/power-ups/types/slow_down/SlowDown.cpp)
    make_new_test(check_speed_up speed-up-down ${PLAYER_FILES} src/power-ups/types/speed_up/SpeedUp.cpp)
    make_new_test(check_shield shield ${PLAYER_FILES} src/power-ups/types/shield/Shield.cpp)
    make_new_test(check_coin_multiplier coin-multiplier ${PLAYER_FILES} src/power-ups/types/coin-multiplier/CoinMultiplier.cpp)
    make_new_test(check_firing_bullet firing-bullet ${FIRING_BULLET_FILES})
    make_new_test(check_bullet firing-bullet ${FIRING_BULLET_FILES})
    make_new_test(check_wall_passing wall-passing ${PLAYER_FILES} src/power-ups/types/passing_walls/PassWall.cpp)
    make_new_test(check_gluttony gluttony ${PLAYER_FILES} src/power-ups/types/gluttony/Gluttony.cpp)
    make_new_test(check_bomb_placement bomb-placement ${BOMB_PLACEMENT_FILES})
    make_new_test(check_bomb bomb-placement ${BOMB_PLACEMENT_FILES})
    make_new_test(check_spike spikes-placement ${SPIKE_PLACEMENT_FILES})
    make_new_test(check_spike_placement spikes-placement ${SPIKE_PLACEMENT_FILES})
    make_new_test(check_sound_manager sound-manager ${TEST_FILES})

endif()