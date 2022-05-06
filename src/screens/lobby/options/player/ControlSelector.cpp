#include "ControlSelector.h"

ControlSelector::ControlSelector(sf::RenderWindow* window) : Selector(window) {

}

void ControlSelector::input(const sf::Event &event) {
    // TODO: keys A-D change _current_control
    // TODO: set _current_selector_id to _my_id
}

void ControlSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
}

void ControlSelector::draw() {
    // TODO: draw this class (box with _current_control and A, D buttons)
}

std::string ControlSelector::getCurrentControl() const {
    return _current_control;
}
