#include "ColorSelector.h"

void ColorSelector::input() {
    // TODO: keys A-D change _current_color
    // TODO: set _current_selector_id to _my_id
}

void ColorSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
}

void ColorSelector::draw() {
    // TODO: draw this class (box with _current_color and A, D buttons)
}

std::string ColorSelector::getCurrentColor() const {
    return _current_color;
}
