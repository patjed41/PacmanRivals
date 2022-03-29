#include "../../src/map/Map.h"
#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "TestCharacter.cpp"

int main() {
    TextureHolder textureHolder;
    LevelManager manager = LevelManager();

    manager.loadNewLevel();
    auto grid = manager.getGrid();

    std::ifstream myfile;
    myfile.open("../assets/maps/grids/grid1.txt");

    if (myfile.is_open()) {
        sf::Sprite sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/path.png"));
        sprite.setPosition(TILE_SIZE - 1, TILE_SIZE);

        Map map = Map();
        std::shared_ptr shared_map = std::make_shared<Map>();

        TestCharacter character = TestCharacter(sprite, shared_map);
        character.correctL();

        err::checkEqual(sprite.getGlobalBounds().left, character.getSprite().getGlobalBounds().left);
        err::checkEqual(sprite.getGlobalBounds().top, character.getSprite().getGlobalBounds().top);

        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }

    return 0;
}