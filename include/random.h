#pragma once

#include <chrono>
#include <random>

static std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());

inline int random(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(gen);
}
