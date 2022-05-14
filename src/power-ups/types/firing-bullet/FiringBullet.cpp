#include "FiringBullet.h"
#include "../../../texture-holder/TextureHolder.h"

FiringBullet::FiringBullet(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/firing-bullet.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void FiringBullet::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {

}
