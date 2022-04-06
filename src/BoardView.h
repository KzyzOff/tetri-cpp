
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
    void setBoardSizingAndPos();
    void setPreviewSizingAndPos(int cell_size);
    void drawNextBlockPreview(SDL_Renderer* renderer);
    void updatePreview();

    [[nodiscard]] SDL_Color getCellColor(celltype cell) const;

    Board& m_board;
    std::vector<Entity> m_grid;
    std::vector<Entity> m_preview_grid;

    int m_cell_size;
    Vec2i m_tlc;                    // Top Left Corner of the board

};

#endif
