
#ifndef TETRIS_CPP_COMMON_H
#define TETRIS_CPP_COMMON_H

#include <array>
#include <map>
#include "types.h"

struct Vec2i
{
    int x;
    int y;
};

struct KeyState
{
    bool isPressed;
    bool wasPressed;
};

enum class AppState {
    MENU,
    GAME,
    CREDITS
};

enum class GameState {
    PAUSE,
    RUNNING,
    FINISHED
};

enum class Direction {
    DOWN,
    LEFT,
    RIGHT
};

namespace Pattern
{
    constexpr std::array<char, 16> L = { ' ', 'L', ' ', ' ',
                                         ' ', 'L', ' ', ' ',
                                         ' ', 'L', 'L', ' ',
                                         ' ', ' ', ' ', ' ' };

    constexpr std::array<char, 16> J = { ' ', ' ', 'J', ' ',
                                         ' ', ' ', 'J', ' ',
                                         ' ', 'J', 'J', ' ',
                                         ' ', ' ', ' ', ' ' };

    constexpr std::array<char, 16> I = { ' ', 'I', ' ', ' ',
                                         ' ', 'I', ' ', ' ',
                                         ' ', 'I', ' ', ' ',
                                         ' ', 'I', ' ', ' ' };

    constexpr std::array<char, 16> Z = { ' ', ' ', ' ', ' ',
                                         'Z', 'Z', ' ', ' ',
                                         ' ', 'Z', 'Z', ' ',
                                         ' ', ' ', ' ', ' ' };

    constexpr std::array<char, 16> S = { ' ', ' ', ' ', ' ',
                                         ' ', 'S', 'S', ' ',
                                         'S', 'S', ' ', ' ',
                                         ' ', ' ', ' ', ' ' };

    constexpr std::array<char, 16> T = { ' ', ' ', ' ', ' ',
                                         ' ', 'T', ' ', ' ',
                                         'T', 'T', 'T', ' ',
                                         ' ', ' ', ' ', ' ' };

    constexpr std::array<char, 16> O = { ' ', ' ', ' ', ' ',
                                         ' ', 'O', 'O', ' ',
                                         ' ', 'O', 'O', ' ',
                                         ' ', ' ', ' ', ' ' };
}

#endif
