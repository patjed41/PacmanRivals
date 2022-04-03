#include "CycleGhost.h"

#include "../../texture-holder/TextureHolder.h"

CycleGhost::CycleGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, std::vector<int> directions) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghost-green.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _directions = std::move(directions);
    _direction = static_cast<Direction>(_directions[0]);
}

void CycleGhost::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds)) {
        _cycle_index = (_cycle_index + 1) % _directions.size();

        moveForward(dt_as_seconds);

        if (_direction != static_cast<Direction>(_directions[_cycle_index])) {
            correct();
            _direction = static_cast<Direction>(_directions[_cycle_index]);
            moveForward(dt_as_seconds);
        }
    } else {
        moveForward(dt_as_seconds);
    }
}
