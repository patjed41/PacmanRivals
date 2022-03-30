#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

int main() {
    TextureHolder textureHolder;
    LevelManager manager = LevelManager();

    manager.loadNewLevel();
    std::vector<sf::Vector2i> players_positions = manager.getPlayersPositions();

    sf::Texture texturePacMan;
    texturePacMan.loadFromFile("../assets/graphics/pac-man.png");
    std::vector<sf::Sprite> spritePacMan(players_positions.size());


    for (int i = 0; i < players_positions.size(); i++) {
        spritePacMan[i].setTexture(texturePacMan);
        spritePacMan[i].setPosition(players_positions[i].x * MAP_WIDTH, players_positions[i].y * MAP_HEIGHT);
    }

    std::ifstream myfile;
    myfile.open("../assets/maps/players/players1.txt");

    if (myfile.is_open()) {
        int size;
        myfile >> size;

        for (int k = 0; k < size; k++) {
            int i, j;
            myfile >> i >> j;

            err::check(spritePacMan[k].getPosition().x == i * MAP_WIDTH, k);
            err::check(spritePacMan[k].getPosition().y == j * MAP_HEIGHT, k);
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }

    return 0;
}