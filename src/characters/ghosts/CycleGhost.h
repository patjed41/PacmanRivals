#pragma once

#include "Ghost.h"

class CycleGhost : public Ghost {

private:

    size_t _cycle_index = 0;

    std::vector<int> _directions;

    bool _start;

    void animate(float dt_as_seconds) override;

public:

    CycleGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, std::vector<int> directions);

    void update(float dt_as_seconds) override;

};
