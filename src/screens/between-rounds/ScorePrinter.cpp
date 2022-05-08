#include "ScorePrinter.h"
#include "../../texture-holder/TextureHolder.h"

#include <iostream>
#include <sstream>

#include "../../../include/game_constants.h"

const float ScorePrinter::FIRST_PLACE_POSITION_Y = 200.0f;
const float ScorePrinter::ONE_POSITION_OFFSET = 200.0f;

ScorePrinter::ScorePrinter(const PlayerInfo & player_info, unsigned int place, const sf::View* view) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ScorePrinter constructor.\n";
        exit(1);
    }

    _pacman.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + player_info.getColor() + ".png"));
    _pacman.setScale(4, 4);

    _text.setFont(_font);
    std::stringstream ss;
    ss << player_info.getNickname();
    for (size_t i = 0; i < NICKLEN_MAX - player_info.getNickname().size(); i++) {
        ss << " ";
    }
    ss << " - " << player_info.getRoundsWon()
       << (player_info.getRoundsWon() == 1 ? " win " : " wins");
    _text.setString(ss.str());
    _text.setFillColor(sf::Color::White);
    _text.setCharacterSize(75);
    sf::FloatRect text_bounds = _text.getGlobalBounds();
    _text.setOrigin(text_bounds.width / 2, text_bounds.height / 2);

    _text.setPosition(view->getCenter().x + _pacman.getGlobalBounds().width / 2,
                      FIRST_PLACE_POSITION_Y + ONE_POSITION_OFFSET * place);
    _pacman.setPosition(_text.getGlobalBounds().left - _pacman.getGlobalBounds().width * 1.5,
                        _text.getGlobalBounds().top - (_pacman.getGlobalBounds().height - _text.getGlobalBounds().height) / 2);
}

void ScorePrinter::draw(sf::RenderWindow* window) {
    _text.setFont(_font);
    window->draw(_text);
    window->draw(_pacman);
}
