#include "../../src/map/Map.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"
#include "TestCharacter.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    sf::Sprite sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/walls/path.png"));
    sprite.setPosition(TILE_SIZE, TILE_SIZE + 1);

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestCharacter character = TestCharacter(sprite, shared_map);
    character.correctD();

    sf::Sprite expected_sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/walls/path.png"));
    expected_sprite.setPosition(TILE_SIZE, TILE_SIZE);

    err::checkEqualFloat(expected_sprite.getGlobalBounds().left, character.getPosition().left);
    err::checkEqualFloat(expected_sprite.getGlobalBounds().top, character.getPosition().top);

    return 0;
}