#pragma once

inline float manhattanDistance(sf::Vector2f p1, sf::Vector2f p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}
