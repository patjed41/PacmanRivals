#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

#include "../../characters/player/Pacman.h"

class PlayerInputHandler {

private:

    std::shared_ptr<Pacman> _pacman;

    bool _uses_arrows;
    bool _uses_WASD;
    int _controller = -1;

    PowerUpName _power_up_to_use;

    void handleArrows();
    void handleWASD();
    void handleController();

public:

    PlayerInputHandler() = default;

    PlayerInputHandler(std::shared_ptr<Pacman> pacman, std::string control);

    void input();

    PowerUpName getPowerUpToUse() const;

};
