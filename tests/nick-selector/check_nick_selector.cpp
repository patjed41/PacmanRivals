#include "../../src/screens/lobby/options/player/NickSelector.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"
#include "../../include/game_constants.h"

#include <SFML/Graphics.hpp>
#include <string>

int main() {
    TextureHolder textureHolder;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    NickSelector nick_selector(&window, 1);

    // Check default value.
    err::checkEqual(std::string("player1"), nick_selector.getCurrentNick(), 1);

    // Check max length.
    std::string max_length_str;
    for (int i = 1; i <= 2 * NICKLEN_MAX; i++) {
        if (i <= NICKLEN_MAX) {
            max_length_str += 'A';
        }
        nick_selector.input(simulateKeypress(sf::Keyboard::Key::A));
        err::checkEqual(max_length_str, nick_selector.getCurrentNick(), i + 1);
    }

    // Check Backspace.
    nick_selector = NickSelector(&window, 1);
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(std::string("A"), nick_selector.getCurrentNick(), "Backspace1");
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    err::checkEqual(std::string("player1"), nick_selector.getCurrentNick(), "Backspace2");
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    err::checkEqual(std::string("player1"), nick_selector.getCurrentNick(), "Backspace3");

    // Check every letter and digit.
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(std::string("A"), nick_selector.getCurrentNick(), "A");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::B));
    err::checkEqual(std::string("B"), nick_selector.getCurrentNick(), "B");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::C));
    err::checkEqual(std::string("C"), nick_selector.getCurrentNick(), "C");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(std::string("D"), nick_selector.getCurrentNick(), "D");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::E));
    err::checkEqual(std::string("E"), nick_selector.getCurrentNick(), "E");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::F));
    err::checkEqual(std::string("F"), nick_selector.getCurrentNick(), "F");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::G));
    err::checkEqual(std::string("G"), nick_selector.getCurrentNick(), "G");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::H));
    err::checkEqual(std::string("H"), nick_selector.getCurrentNick(), "H");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::I));
    err::checkEqual(std::string("I"), nick_selector.getCurrentNick(), "I");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::J));
    err::checkEqual(std::string("J"), nick_selector.getCurrentNick(), "J");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::K));
    err::checkEqual(std::string("K"), nick_selector.getCurrentNick(), "K");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::L));
    err::checkEqual(std::string("L"), nick_selector.getCurrentNick(), "L");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::M));
    err::checkEqual(std::string("M"), nick_selector.getCurrentNick(), "M");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::N));
    err::checkEqual(std::string("N"), nick_selector.getCurrentNick(), "N");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::O));
    err::checkEqual(std::string("O"), nick_selector.getCurrentNick(), "O");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::P));
    err::checkEqual(std::string("P"), nick_selector.getCurrentNick(), "P");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Q));
    err::checkEqual(std::string("Q"), nick_selector.getCurrentNick(), "Q");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::R));
    err::checkEqual(std::string("R"), nick_selector.getCurrentNick(), "R");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::S));
    err::checkEqual(std::string("S"), nick_selector.getCurrentNick(), "S");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::T));
    err::checkEqual(std::string("T"), nick_selector.getCurrentNick(), "T");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::U));
    err::checkEqual(std::string("U"), nick_selector.getCurrentNick(), "U");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::V));
    err::checkEqual(std::string("V"), nick_selector.getCurrentNick(), "V");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::W));
    err::checkEqual(std::string("W"), nick_selector.getCurrentNick(), "W");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::X));
    err::checkEqual(std::string("X"), nick_selector.getCurrentNick(), "X");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Y));
    err::checkEqual(std::string("Y"), nick_selector.getCurrentNick(), "Y");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Z));
    err::checkEqual(std::string("Z"), nick_selector.getCurrentNick(), "Z");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num0));
    err::checkEqual(std::string("0"), nick_selector.getCurrentNick(), "0");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num1));
    err::checkEqual(std::string("1"), nick_selector.getCurrentNick(), "1");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num2));
    err::checkEqual(std::string("2"), nick_selector.getCurrentNick(), "2");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num3));
    err::checkEqual(std::string("3"), nick_selector.getCurrentNick(), "3");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num4));
    err::checkEqual(std::string("4"), nick_selector.getCurrentNick(), "4");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num5));
    err::checkEqual(std::string("5"), nick_selector.getCurrentNick(), "5");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num6));
    err::checkEqual(std::string("6"), nick_selector.getCurrentNick(), "6");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num7));
    err::checkEqual(std::string("7"), nick_selector.getCurrentNick(), "7");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num8));
    err::checkEqual(std::string("8"), nick_selector.getCurrentNick(), "8");

    nick_selector.input(simulateKeypress(sf::Keyboard::Key::BackSpace));
    nick_selector.input(simulateKeypress(sf::Keyboard::Key::Num9));
    err::checkEqual(std::string("9"), nick_selector.getCurrentNick(), "9");
}
