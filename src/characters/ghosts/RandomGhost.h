#pragma once

#include "Ghost.h"
#include "../../texture-holder/TextureHolder.h"

#include <memory>

class RandomGhost : public Ghost {

public:

    RandomGhost(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y);

    void update(float dt_as_seconds) override;

};

RandomGhost::RandomGhost(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghost-pink.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);
}

void RandomGhost::update(float dt_as_seconds) {

}
