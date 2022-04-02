#pragma once

#include "Ghost.h"
#include "../../texture-holder/TextureHolder.h"

#include <memory>

class LinearGhost : public Ghost {

public:

    LinearGhost() = default;

    LinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction);

    ~LinearGhost() override = default;

    void update(float dt_as_seconds) override;

};

LinearGhost::LinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghost-yellow.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);

    _direction = static_cast<Direction>(direction);
}

void LinearGhost::update(float dt_as_seconds) {}
