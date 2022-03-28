#include "../../src/parser/LevelManager.h"
#include "../../include/err.h"

int main() {
    sf::RenderWindow _window;

    sf::View _main_view; // view used for drawing game (map and characters)

    sf::Vector2<unsigned int> resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    _window.create(sf::VideoMode(resolution.x, resolution.y), "Pacman Rivals", sf::Style::Fullscreen);
    _main_view.reset(sf::FloatRect(0, 0, (float)resolution.x, (float)resolution.y));
    _main_view.setCenter(MAP_WIDTH * TILE_SIZE / 2.f, MAP_HEIGHT * TILE_SIZE / 2.f);


    LevelManager manager = LevelManager();

    manager.loadNewPlayers();


    std::vector<sf::Vector2i> players_positions = manager.getPlayersPositions();
    while (_window.isOpen()) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            _window.close();
        }

        _window.clear(sf::Color::Black);
        _window.setView(_main_view);

        // draw
        sf::Texture texturePacMan;
        texturePacMan.loadFromFile("../assets/graphics/pac-man.png");
        sf::Sprite spritePacMan;
        spritePacMan.setTexture(texturePacMan);
        for (auto & players_position : players_positions){
            spritePacMan.setPosition(players_position.x*MAP_WIDTH, players_position.y*MAP_HEIGHT);

            err::check(players_position.x*MAP_WIDTH > 0, 1);
            err::check(players_position.y*MAP_HEIGHT > 0, 2);

            _window.draw(spritePacMan);
        }

        _window.display();
    }

    return 0;
}
