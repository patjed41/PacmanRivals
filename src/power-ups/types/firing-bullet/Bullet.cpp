#include "Bullet.h"
#include "../../../texture-holder/TextureHolder.h"

Bullet::Bullet(sf::Vector2f position, std::shared_ptr<Map> map,
               unsigned int shooter, int direction) {
    _map = map;
    _shooter = shooter;
    _direction = static_cast<Direction>(direction);

    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/bullet.png"));
    _sprite.setOrigin(getPosition().width / 2, getPosition().height / 2);
    _sprite.setPosition(position);
    switch (_direction) {
        case LEFT:
            _sprite.move(-TILE_SIZE, 0);
            _sprite.rotate(0);
            break;
        case RIGHT:
            _sprite.move(TILE_SIZE, 0);
            _sprite.rotate(180);
            break;
        case UP:
            _sprite.move(0, -TILE_SIZE);
            _sprite.rotate(90);
            break;
        case DOWN:
            _sprite.move(0, TILE_SIZE);
            _sprite.rotate(270);
            break;
    }
}

sf::FloatRect Bullet::getPosition() const {
    return _sprite.getGlobalBounds();
}

const sf::Sprite &Bullet::getSprite() const {
    return _sprite;
}

unsigned int Bullet::getShooter() const {
    return _shooter;
}

void Bullet::disappear() {
    _disappeared = true;
}

bool Bullet::disappeared() const {
    return _disappeared;
}

void Bullet::update(float dt_as_seconds) {
    if (disappeared()) {
        return;
    }

    switch (_direction) {
        case LEFT:
            _sprite.move(-_speed * dt_as_seconds, 0);
            break;
        case RIGHT:
            _sprite.move(_speed * dt_as_seconds, 0);
            break;
        case UP:
            _sprite.move(0, -_speed * dt_as_seconds);
            break;
        case DOWN:
            _sprite.move(0, _speed * dt_as_seconds);
            break;
    }

    int x = (getPosition().left + getPosition().width / 2) / TILE_SIZE;
    int y = (getPosition().top + getPosition().height / 2) / TILE_SIZE;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i >= 0 && j >= 0 && i < MAP_HEIGHT && j < MAP_WIDTH && _map->getTiles()[i][j].isWall()
                && _map->getTiles()[i][j].getSprite().getGlobalBounds().intersects(getPosition())) {
                disappear();
            }
        }
    }
}
