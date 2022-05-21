#include "Bomb.h"
#include "../../../../include/game_constants.h"
#include "../../../texture-holder/TextureHolder.h"

#include <iostream>

const float Bomb::_SECONDS_TO_EXPLOSION = 4;

Bomb::Bomb(sf::Vector2f position, unsigned int bomberman) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in Bomb constructor.\n";
        exit(1);
    }

    _bomberman = bomberman;
    _exploded = false;
    _seconds_left = _SECONDS_TO_EXPLOSION;

    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/bomb.png"));
    _sprite.setOrigin(getPosition().width / 2, getPosition().height / 2);
    _sprite.setPosition((int)position.x / TILE_SIZE * TILE_SIZE + TILE_SIZE / 2,
                        (int)position.y / TILE_SIZE * TILE_SIZE + TILE_SIZE / 2);

    _time_info.setFont(_font);
    _time_info.setFillColor(sf::Color::White);
    _time_info.setCharacterSize(15);
    _time_info.setPosition(getPosition().left + 16, getPosition().top + 16);
    _time_info.setString("3");

    int y_tile = position.y / TILE_SIZE;
    int x_tile = position.x / TILE_SIZE;
    for (int y = y_tile - EXPLOSION_RADIUS; y <= y_tile + EXPLOSION_RADIUS; y++) {
        for (int x = x_tile - EXPLOSION_RADIUS; x <= x_tile + EXPLOSION_RADIUS; x++) {
            if (y >= 0 && x >= 0 && y < MAP_HEIGHT && x < MAP_WIDTH) {
                _explosion_sprites.emplace_back(TextureHolder::GetTexture("../assets/graphics/power-ups/explosion.png"));
                _explosion_sprites.back().setPosition(x * TILE_SIZE, y * TILE_SIZE);
            }
        }
    }
}

sf::FloatRect Bomb::getPosition() const {
    return _sprite.getGlobalBounds();
}

unsigned int Bomb::getBomberman() const {
    return _bomberman;
}

bool Bomb::timeToExplode() const {
    return _seconds_left <= 0 && !_exploded;
}

void Bomb::explode() {
    _exploded = true;
}

void Bomb::update(float dt_as_seconds) {
    if (_seconds_left >= 3 && _seconds_left - dt_as_seconds < 3) {
        _time_info.setString("2");
    }
    else if (_seconds_left >= 2 && _seconds_left - dt_as_seconds < 2) {
        _time_info.setString("1");
    }
    else if (_seconds_left >= 1 && _seconds_left - dt_as_seconds < 1) {
        _time_info.setString("0");
    }

    _seconds_left -= dt_as_seconds;
}

void Bomb::draw(sf::RenderWindow *window) {
    if (!_exploded) {
        window->draw(_sprite);
        window->draw(_time_info);
    }
    else if (_seconds_left >= -1) {
        for (const sf::Sprite &explosion_sprite :_explosion_sprites) {
            window->draw(explosion_sprite);
        }
    }
}

bool Bomb::explosionReaches(const sf::FloatRect &rect) const {
    for (const sf::Sprite &explosion_sprite :_explosion_sprites) {
        if (explosion_sprite.getGlobalBounds().intersects(rect)) {
            return true;
        }
    }

    return false;
}
