#include "PlayerStats.h"
#include "../../texture-holder/TextureHolder.h"

#include <iostream>
#include <sstream>

const float PlayerStats::POSITION_OFFSET = 50.0f;
const float PlayerStats::TIME_BAR_WIDTH = 150.0f;
const float PlayerStats::TIME_BAR_HEIGHT = 35.0f;

PlayerStats::PlayerStats(const PlayerInfo &player_info, unsigned int player_no, const sf::View* view) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in PlayerStats constructor.\n";
        exit(1);
    }

    switch (player_no) {
        case 0:
            _position_x = -113.0f;
            _position_y = 20.0f;
            break;
        case 1:
            _position_x = -113.0f;
            _position_y = 600.0f; // or view->getCenter().y
            break;
        case 2:
            _position_x = 1605.0f;
            _position_y = 20.0f;
            break;
        case 3:
            _position_x = 1605.0f;
            _position_y = 600.0f; // or view->getCenter().y
            break;
    }

    _pacman.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + player_info.getColor() + ".png"));
    _pacman.setScale(0.8, 0.8);

    _power_up_time.setSize(sf::Vector2f(TIME_BAR_WIDTH, TIME_BAR_HEIGHT));
    _power_up_time.setFillColor(sf::Color::Blue);

    _nickname.setFont(_font);
    _points.setFont(_font);
    _status_alive.setFont(_font);
    _status_dead.setFont(_font);

    std::stringstream ss;
    ss << player_info.getNickname();
    _nickname.setString(ss.str());
    _nickname.setFillColor(sf::Color::White);
    _nickname.setCharacterSize(20);

    _points.setFillColor(sf::Color::White);
    _points.setCharacterSize(20);

    _status_alive.setString("Alive");
    _status_alive.setFillColor(sf::Color::Green);
    _status_alive.setCharacterSize(20);

    _status_dead.setString("Dead");
    _status_dead.setFillColor(sf::Color::Red);
    _status_dead.setCharacterSize(20);

    sf::FloatRect text_bounds = _nickname.getGlobalBounds();
    _nickname.setOrigin(text_bounds.width / 2, text_bounds.height / 2);

    _nickname.setPosition(_position_x + _pacman.getGlobalBounds().width / 2, _position_y);
    _pacman.setPosition(_nickname.getGlobalBounds().left - _pacman.getGlobalBounds().width,
                        _nickname.getGlobalBounds().top - (_pacman.getGlobalBounds().height - _nickname.getGlobalBounds().height) / 2);
    _points.setPosition(_pacman.getGlobalBounds().left,
                        _position_y + POSITION_OFFSET);
    _status_alive.setPosition(_pacman.getGlobalBounds().left,
                          _position_y + POSITION_OFFSET * 2);
    _status_dead.setPosition(_pacman.getGlobalBounds().left,
                              _position_y + POSITION_OFFSET * 2);
    _power_up.setPosition(_pacman.getGlobalBounds().left,
                          _position_y + POSITION_OFFSET * 3);
    _power_up_time.setPosition(_nickname.getGlobalBounds().left,
                               _power_up.getGlobalBounds().top);
}

void PlayerStats::update(const PlayerInfo & player_info) {
    switch (player_info.getPowerUp()) {
        case COIN_MULTIPLIER:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/place-holder.png")); // todo graphic is missing
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case SPEED_UP:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/speed-up.png"));
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case GLUTTONY:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/place-holder.png")); // todo graphic is missing
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case SHIELD:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/blocking-shield.png"));
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case WALL_PASSING:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/wall-breaker.png"));
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case SPIKES_PLACEMENT:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/thorns.png"));
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case BOMB_PLACEMENT:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/bomb-setter.png"));
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        case FIRING_BULLET:
            _power_up.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/firing-bullet.png"));
            _power_up.setScale(0.8, 0.8);
            _power_up_time.setSize(sf::Vector2f(player_info.getPowerUpTimeLeft() * TIME_BAR_WIDTH, _power_up.getGlobalBounds().height));
            break;
        default:
            _power_up.setScale(0, 0);
            _power_up_time.setSize(sf::Vector2f(0, 0));
            break;
    }

    std::stringstream ss_points;
    ss_points << "Points: " << std::to_string(player_info.getRoundPoints());
    _points.setString(ss_points.str());
}

void PlayerStats::drawAlive(sf::RenderWindow *window) {
    _nickname.setFont(_font);
    _points.setFont(_font);
    _status_alive.setFont(_font);

    window->draw(_pacman);
    window->draw(_nickname);
    window->draw(_points);
    window->draw(_status_alive);
    window->draw(_power_up);
    window->draw(_power_up_time);
}

void PlayerStats::drawDead(sf::RenderWindow *window) {
    _nickname.setFont(_font);
    _points.setFont(_font);
    _status_dead.setFont(_font);

    _pacman.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-black.png")); // todo pac-man-gray

    window->draw(_pacman);
    window->draw(_nickname);
    window->draw(_points);
    window->draw(_status_dead);
}
