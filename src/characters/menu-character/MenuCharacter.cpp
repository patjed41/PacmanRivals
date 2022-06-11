#include "MenuCharacter.h"
#include "../../texture-holder/TextureHolder.h"

MenuCharacter::MenuCharacter(float start_tile_x, float start_tile_y,  int direction) {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-yellow.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _direction = static_cast<Direction>(direction);
}

void MenuCharacter::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds)) {
        sf::FloatRect curr_position = getPosition();

        sf::Vector2i curr_tile = {(int) (curr_position.left / TILE_SIZE + 0.5), (int) (curr_position.top / TILE_SIZE + 0.5)};
        sf::Vector2i next_tile = positionOfNewTile(curr_tile);

        move(dt_as_seconds);
    } else {
        move(dt_as_seconds);
    }

    sf::FloatRect curr_position = getPosition();
    if (curr_position.left < 0) {
        _sprite.setPosition(sf::VideoMode::getDesktopMode().width, curr_position.top);
    }
}
