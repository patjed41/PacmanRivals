#include "MenuCharacter.h"
#include "../../texture-holder/TextureHolder.h"
#include "../../../include/random.h"

MenuCharacter::MenuCharacter(float start_tile_x, float start_tile_y,  int direction) {
    int if_pacman = random(0, 1);
    if (if_pacman) {
        std::vector<std::string> colors{"darkblue", "darkgreen", "ghost", "lightblue", "lightgreen", "orange", "pink", "purple", "red", "yellow"};
        int color = random(0, colors.size() - 1);
        _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + colors[color] + ".png"));
    } else {
        std::vector<std::string> colors{"green", "pink", "yellow"};
        int color = random(0, 2);
        _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-" + colors[color] + ".png"));
    }
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    if(random(0, 3) == 0) {
        _if_random = true;
    }

    _direction = static_cast<Direction>(direction);
}

void MenuCharacter::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds)) {

        move(dt_as_seconds);

        if (_if_random) {
            auto new_direction = static_cast<Direction>(random(0, 3));
            if (_direction != new_direction) {
                correct();
                _direction = new_direction;
                move(dt_as_seconds);
            }
        }
    } else {
        move(dt_as_seconds);
    }

    sf::FloatRect curr_position = getPosition();
    if (curr_position.left < 0) {
        _sprite.setPosition(sf::VideoMode::getDesktopMode().width, curr_position.top);
    } else if (curr_position.top < 0) {
        _sprite.setPosition(curr_position.top, sf::VideoMode::getDesktopMode().height);
    } else if (curr_position.left > sf::VideoMode::getDesktopMode().width) {
        _sprite.setPosition(0, curr_position.top);
    } else if (curr_position.top > sf::VideoMode::getDesktopMode().height) {
        _sprite.setPosition(curr_position.left, 0);
    }
}
