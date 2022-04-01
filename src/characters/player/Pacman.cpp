#include "Pacman.h"
#include "../../texture-holder/TextureHolder.h"

Pacman::Pacman() : Character() {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/pac-man.png"));
//    _sprite.setPosition(start_tile_x, start_tile_y);
}

void Pacman::update(float dt_as_seconds) {

}