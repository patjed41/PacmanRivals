#include "Tile.h"
#include "../texture-holder/TextureHolder.h"

Tile::Tile(int type, int color) : _type(type) {
    if (_type == 1) {
        _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/walls/wall" + std::to_string(color) + ".png"));
    } else {
        _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/walls/path.png"));
    }
}

const sf::Sprite &Tile::getSprite() const {
    return _sprite;
}

bool Tile::isWall() const {
    return _type == 1;
}

void Tile::setPosition(int i, int j) {
    _sprite.setPosition(j * TILE_SIZE, i * TILE_SIZE);
    if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
        _edge = true;
    }
    else {
        _edge = false;
    }
}

bool Tile::isEdge() const {
    return _edge;
}
