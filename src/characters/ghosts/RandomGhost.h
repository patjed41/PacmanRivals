#pragma once

#include "Ghost.h"

class RandomGhost : public Ghost {

private:

    Direction _new_direction;

public:

    RandomGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction);

    void randNewDirection();

    void update(float dt_as_seconds) override;

};
