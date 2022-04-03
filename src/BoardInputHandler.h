
#ifndef TETRIS_CPP_BOARDINPUTHANDLER_H
#define TETRIS_CPP_BOARDINPUTHANDLER_H

#include "header.h"
#include "Board.h"
#include "common.h"
#include <string>

class BoardInputHandler {
public:
    BoardInputHandler();

    void handleEvents(SDL_Event& event, Board& board);

private:
    bool m_left_flag;
    bool m_right_flag;
    bool m_up_flag;
    bool m_down_flag;
    bool m_space_flag;

};

#endif
