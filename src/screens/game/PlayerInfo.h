#pragma once

#include <string>
#include <utility>

class PlayerInfo {

private:

    std::string _nickname;
    std::string _color; // 'yellow', 'red', ...
    std::string _control; // 'WASD', 'Arrows', 'C1', 'C2, 'C3', 'C4'

    unsigned int _rounds_won;

public:

    PlayerInfo() = default;

    PlayerInfo(std::string nickname, std::string color, std::string control);

    std::string getNickname() const;

    std::string getColor() const;

    std::string getControl() const;

    void newWin();

    unsigned int getRoundsWon() const;

};
