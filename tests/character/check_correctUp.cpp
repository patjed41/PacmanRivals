#include "../../src/map/Map.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "TestCharacter.h"

int main() {
    TextureHolder textureHolder;

    sf::Sprite sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/path.png"));
    sprite.setPosition(TILE_SIZE, TILE_SIZE - 1);

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestCharacter character = TestCharacter(sprite, shared_map);
    character.correctU();

    sf::Sprite expected_sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/path.png"));
    expected_sprite.setPosition(TILE_SIZE, TILE_SIZE);

    err::checkEqualFloat(expected_sprite.getGlobalBounds().left, character.getPosition().left);
    err::checkEqualFloat(expected_sprite.getGlobalBounds().top, character.getPosition().top);

    return 0;
}