#include "RandomGhost.h"

#include "../../texture-holder/TextureHolder.h"

RandomGhost::RandomGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghost-pink.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _direction = static_cast<Direction>(direction);
}

void RandomGhost::randNewDirection() {
    std::vector<Direction> directions;

    sf::Vector2i up_tile = getUpTile(), down_tile = getDownTile(), left_tile = getLeftTile(), right_tile = getRightTile();

    switch (_direction) {
        case LEFT:
            if (!_map.get()->getTiles()[left_tile.y][left_tile.x].isWall()) directions.push_back(LEFT);
            if (!_map.get()->getTiles()[up_tile.y][up_tile.x].isWall()) directions.push_back(UP);
            if (!_map.get()->getTiles()[down_tile.y][down_tile.x].isWall()) directions.push_back(DOWN);
            break;
        case RIGHT:
            if (!_map.get()->getTiles()[right_tile.y][right_tile.x].isWall()) directions.emplace_back(RIGHT);
            if (!_map.get()->getTiles()[down_tile.y][down_tile.x].isWall()) directions.emplace_back(DOWN);
            if (!_map.get()->getTiles()[up_tile.y][up_tile.x].isWall()) directions.emplace_back(UP);
            break;
        case UP:
            if (!_map.get()->getTiles()[up_tile.y][up_tile.x].isWall()) directions.emplace_back(UP);
            if (!_map.get()->getTiles()[right_tile.y][right_tile.x].isWall()) directions.emplace_back(RIGHT);
            if (!_map.get()->getTiles()[left_tile.y][left_tile.x].isWall()) directions.emplace_back(LEFT);
            break;
        case DOWN:
            if (!_map.get()->getTiles()[down_tile.y][down_tile.x].isWall()) directions.emplace_back(DOWN);
            if (!_map.get()->getTiles()[left_tile.y][left_tile.x].isWall()) directions.emplace_back(LEFT);
            if (!_map.get()->getTiles()[right_tile.y][right_tile.x].isWall()) directions.emplace_back(RIGHT);
            break;
        default:
            break;
    }

    if (directions.empty()) {
        _new_direction = _direction;
        turnBack();
        std::swap(_direction, _new_direction);
    } else {
        // TODO: wcale nie losuje liczby, zawsze są te same
        size_t rand_idx = rand() % directions.size();
        _new_direction = directions[rand_idx];
    }
}

void RandomGhost::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds)) {
        randNewDirection();

        moveForward(dt_as_seconds);

        if (_direction != _new_direction) {
            correct();
            _direction = _new_direction;
        } else{
            moveForward(dt_as_seconds);
        }
    } else {
        moveForward(dt_as_seconds);
    }
}
