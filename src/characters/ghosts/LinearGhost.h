#pragma once

#include "Ghost.h"

class LinearGhost : public Ghost {

public:

    LinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction);

    void animate(float dt_as_seconds) override;

    void update(float dt_as_seconds) override;

};
