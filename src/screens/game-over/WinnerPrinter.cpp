#include "WinnerPrinter.h"
#include "../../texture-holder/TextureHolder.h"

#include <iostream>

const float WinnerPrinter::FIRST_PLACE_POSITION_Y = 250.0f;
const float WinnerPrinter::ONE_POSITION_OFFSET = 200.0f;

WinnerPrinter::WinnerPrinter(const PlayerInfo & player_info, unsigned int id, const sf::View* view) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in WinnerPrinter constructor.\n";
        exit(1);
    }

    _pacman.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + player_info.getColor() + ".png"));
    _pacman.setScale(3, 3);

    _nickname.setFont(_font);
    _nickname.setString(player_info.getNickname());
    _nickname.setFillColor(sf::Color::White);
    _nickname.setCharacterSize(75);

    _nickname.setPosition(view->getCenter().x / 1.2, FIRST_PLACE_POSITION_Y + ONE_POSITION_OFFSET * id);
    _pacman.setPosition(_nickname.getGlobalBounds().left - _pacman.getGlobalBounds().width * 1.5,
                        _nickname.getGlobalBounds().top - (_pacman.getGlobalBounds().height - _nickname.getGlobalBounds().height) / 2);

    _crown.setTexture(TextureHolder::GetTexture("../assets/graphics/crown.png"));
    _crown.setScale(3, 3);
    _crown.setPosition(_pacman.getGlobalBounds().left,
                       _pacman.getGlobalBounds().top - _crown.getGlobalBounds().height / 2);
}

void WinnerPrinter::draw(sf::RenderWindow* window) {
    _nickname.setFont(_font);
    window->draw(_nickname);
    window->draw(_pacman);
    window->draw(_crown);
}
