#include "LinearGhost.h"

#include "../../texture-holder/TextureHolder.h"

LinearGhost::LinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghost-yellow.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _direction = static_cast<Direction>(direction);
}

void LinearGhost::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds)) {
        sf::FloatRect curr_position = getPosition();

        sf::Vector2i curr_tile = {(int) curr_position.left / TILE_SIZE, (int) curr_position.top / TILE_SIZE};
        sf::Vector2i next_tile = getNextTile(curr_tile);

        if (_map.get()->getTiles()[next_tile.y][next_tile.x].isWall()) {
            moveForward(dt_as_seconds);
            correct();
            turnBack();
            moveForward(dt_as_seconds);
        }
    }
}
