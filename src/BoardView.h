
#ifndef TETRIS_CPP_BOARDVIEW_H
#define TETRIS_CPP_BOARDVIEW_H

#include <vector>
#include <algorithm>
#include <memory>
#include "header.h"
#include "CONSTANT.h"
#include "Board.h"
#include "Entity.h"

class BoardView {
public:
    explicit BoardView(Board& board);

    void update();
    void draw(SDL_Renderer* renderer);

private:
    void setBoardSizingAndPositioning();

    Board& m_board;
    std::vector<Entity> m_grid;

    int m_cell_size;
    Vec2i m_tlc;                    // Top Left Corner of the board

};

#endif
