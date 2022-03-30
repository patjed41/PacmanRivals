#include "../../src/map/Map.h"
#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "TestCharacter.h"

#include <iostream>

int main() {
    TextureHolder textureHolder;

    sf::Sprite sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/path.png"));

    std::shared_ptr map = std::make_shared<Map>();
    TestCharacter character(sprite, map);

    // Right
    sprite.setPosition(TILE_SIZE - 5, TILE_SIZE);
    character = TestCharacter(sprite, map);
    character.turnR();
    err::check(character.checkReachedNewTile(1.f), 1);
    err::check(!character.checkReachedNewTile(0.1f), 2);

    // Left
    sprite.setPosition(TILE_SIZE + 5, TILE_SIZE);
    character = TestCharacter(sprite, map);
    character.turnL();
    err::check(character.checkReachedNewTile(1.f), 3);
    err::check(!character.checkReachedNewTile(0.1f), 4);

    // Up
    sprite.setPosition(TILE_SIZE, TILE_SIZE + 5);
    character = TestCharacter(sprite, map);
    character.turnU();
    err::check(character.checkReachedNewTile(1.f), 5);
    err::check(!character.checkReachedNewTile(0.1f), 6);

    // Down
    sprite.setPosition(TILE_SIZE, TILE_SIZE - 5);
    character = TestCharacter(sprite, map);
    character.turnD();
    err::check(character.checkReachedNewTile(1.f), 7);
    err::check(!character.checkReachedNewTile(0.1f), 8);

    return 0;
}
