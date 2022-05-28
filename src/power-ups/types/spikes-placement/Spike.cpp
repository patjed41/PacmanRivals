#include "Spike.h"

#include <utility>
#include "../../../texture-holder/TextureHolder.h"

Spike::Spike(sf::Vector2f position, unsigned int user) {
    _user = user;

    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/thorn.png"));
    _sprite.setOrigin(getPosition().width / 2, getPosition().height / 2);
    _sprite.setPosition(position);
}

sf::FloatRect Spike::getPosition() const {
    return _sprite.getGlobalBounds();
}

const sf::Sprite &Spike::getSprite() const {
    return _sprite;
}

unsigned int Spike::getUser() const {
    return _user;
}

void Spike::disappear() {
    _disappeared = true;
}

bool Spike::disappeared() const {
    return _disappeared;
}

void Spike::update(float dt_as_seconds) {
    if (disappeared()) {
        return;
    }
}
