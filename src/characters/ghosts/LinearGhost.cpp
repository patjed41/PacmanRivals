#include "LinearGhost.h"

#include "../../texture-holder/TextureHolder.h"

LinearGhost::LinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-yellow-1-right.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _direction = static_cast<Direction>(direction);
    _state = "1";
    _textureChange = 0.0;
}

void LinearGhost::animate(float dt_as_seconds) {
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
    if (_direction == LEFT || _direction == UP){
        _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-yellow-" + _state + "-left.png"));

    }
    else {
        _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/ghosts/ghost-yellow-" + _state + "-right.png"));
    }
}

void LinearGhost::update(float dt_as_seconds) {
    animate(dt_as_seconds);
    if (reachedNewTile(dt_as_seconds)) {
        sf::FloatRect curr_position = getPosition();

        sf::Vector2i curr_tile = {(int) (curr_position.left / TILE_SIZE + 0.5), (int) (curr_position.top / TILE_SIZE + 0.5)};
        sf::Vector2i next_tile = positionOfNewTile(curr_tile);

        move(dt_as_seconds);
        if (_map->getTiles()[next_tile.y][next_tile.x].isWall()) {
            correct();
            _direction = getOppositeDirection();
            move(dt_as_seconds);
        }
    } else {
        move(dt_as_seconds);
    }
}
