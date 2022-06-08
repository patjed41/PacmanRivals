#include "CycleGhost.h"

#include "../../texture-holder/TextureHolder.h"

CycleGhost::CycleGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, std::vector<int> directions) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-green-1.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _directions = std::move(directions);
    _direction = static_cast<Direction>(_directions[0]);
    _start = true;
    _state = "1";
}

void CycleGhost::animate(float dt_as_seconds) {
    _textureChange += dt_as_seconds;

    if (_textureChange >= 0.6){
        _textureChange -= 0.6;

        if (_state == "1"){
            _state = "2";
        }
        else {
            _state = "1";
        }
    }
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-green-" + _state + ".png"));
}

void CycleGhost::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds) && !_start) {
        _cycle_index = (_cycle_index + 1) % _directions.size();

        move(dt_as_seconds);

        if (_direction != static_cast<Direction>(_directions[_cycle_index])) {
            correct();
            _direction = static_cast<Direction>(_directions[_cycle_index]);
            move(dt_as_seconds);
        }
    } else {
        move(dt_as_seconds);
        _start = false;
    }
}
