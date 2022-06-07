#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

int main() {
    TextureHolder textureHolder;
    LevelManager manager = LevelManager();

    manager.loadNewLevel();
    std::vector<std::shared_ptr<Pacman>> players;
    while (manager.getLoadedLevel() != 1) {
        manager.loadNewLevel();
        players = manager.getPlayers();
    }

    sf::Texture texturePacMan;
    texturePacMan.loadFromFile("../assets/graphics/pac-man-yellow.png");
    std::vector<sf::Sprite> spritePacMan(players.size());


    for (int i = 0; i < players.size(); i++) {
        spritePacMan[i].setTexture(texturePacMan);
        spritePacMan[i].setPosition((*players[i].get()).getSprite().getGlobalBounds().left, (*players[i].get()).getSprite().getGlobalBounds().top);
    }

    std::ifstream myfile;
    myfile.open("../assets/maps/players/players1.txt");

    if (myfile.is_open()) {
        int size;
        myfile >> size;

        for (int k = 0; k < size; k++) {
            int i, j;
            myfile >> i >> j;

            err::check(spritePacMan[k].getPosition().x == i * TILE_SIZE, k);
            err::check(spritePacMan[k].getPosition().y == j * TILE_SIZE, k);
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }

    return 0;
}