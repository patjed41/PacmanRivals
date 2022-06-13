#pragma once

#include "Ghost.h"

class LinearGhost : public Ghost {

private:

    void animate(float dt_as_seconds) override;

public:

    LinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction);

    void update(float dt_as_seconds) override;

};
