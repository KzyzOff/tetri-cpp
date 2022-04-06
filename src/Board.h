
#ifndef TETRIS_CPP_BOARD_H
#define TETRIS_CPP_BOARD_H

#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <random>
#include "CONSTANT.h"
#include "common.h"
#include "types.h"
#include "Block.h"
#include "Clock.h"

struct TimeTick
{
    timetype base;
    timetype current;
    bool is_sped_up;
};

// TODO: Add score system

class Board {
public:
    Board();

    void setTickMS(timetype tick_ms);

    [[nodiscard]] std::vector<celltype> getBoardWithCurrentBlock() const;
    [[nodiscard]] std::vector<celltype> getBoard() const;
    [[nodiscard]] std::shared_ptr<Block> getCurrentBlockPtr() const;
    [[nodiscard]] std::vector<celltype> getNextBlockPattern() const;
    void update();
    void placeBlockDown();
    void toggleSpeedUp();

    void debugDraw() const;

private:
    void updateBoard();
    void genBlockAndNext();
    void solidifyBlock();
    void removeFullRows();
    void removeRow(rowNumType row);
    void moveSolidBlocksDown(rowNumType lowest_row);

    std::vector<std::array<celltype, 16>> m_patterns;
    std::vector<celltype> m_fields;
    std::shared_ptr<Block> m_current_block;
    size_t m_next_block_idx;
    scoreType m_score;
    Clock m_clock;
    TimeTick m_tick;

};


#endif
