#include "SlowDown.h"
#include "../../../texture-holder/TextureHolder.h"

SlowDown::SlowDown(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/place-holder.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void SlowDown::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
    for (int i = 0; i < pacmans.size(); ++i) {
        if (i == user) continue;
        pacmans[i].get()->setSpeed(50);
    }
}