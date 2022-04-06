
#ifndef TETRIS_CPP_BOARDVIEW_H
#define TETRIS_CPP_BOARDVIEW_H

#include <vector>
#include <algorithm>
#include <memory>
#include "header.h"
#include "CONSTANT.h"
#include "Board.h"
#include "FontManager.h"
#include "Entity.h"

class BoardView {
public:
    BoardView(Board& board, FontManager& fm);

    void update();
    void draw(SDL_Renderer* renderer);

private:
    void setBoardSizingAndPos();
    void setPreviewSizingAndPos(int cell_size);
    void setScoreSizingAndPos(Vec2i board_trc_pos);
    void drawNextBlockPreview(SDL_Renderer* renderer);
    void drawScore(SDL_Renderer* renderer);
    void updatePreview();
    void updateScore();

    [[nodiscard]] SDL_Color getCellColor(celltype cell) const;

    FontManager& m_font_mgr;
    Board& m_board;
    std::vector<Entity> m_grid;
    std::vector<Entity> m_preview_grid;

    int m_cell_size;
    Vec2i m_tlc;                    // Top Left Corner of the board

    Vec2i m_score_pos;

};

#endif
