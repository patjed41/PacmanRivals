#pragma once

#include "Ghost.h"
#include "../../texture-holder/TextureHolder.h"

#include <memory>

class CycleGhost : public Ghost {

public:

    CycleGhost(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y);

    void update(float dt_as_seconds) override;

};

CycleGhost::CycleGhost(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y) {
    _map = std::move(map);

    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/ghost-green.png"));
    _sprite.setPosition(start_tile_x * TILE_SIZE, start_tile_y * TILE_SIZE);
}

void CycleGhost::update(float dt_as_seconds) {

}
