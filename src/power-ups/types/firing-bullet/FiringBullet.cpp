#include "FiringBullet.h"
#include "../../../texture-holder/TextureHolder.h"

FiringBullet::FiringBullet() {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/firing-bullet.png"));
}

void FiringBullet::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {

}
