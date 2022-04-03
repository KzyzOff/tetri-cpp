
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

class Board {
public:
    Board();

    void setTickMS(timetype tick_ms);

    [[nodiscard]] std::vector<celltype> getBoardWithCurrentBlock() const;
    [[nodiscard]] std::vector<celltype> getBoard() const;
    [[nodiscard]] std::shared_ptr<Block> getCurrentBlockPtr() const;
    void update();
    void placeBlockDown();

    void debugDraw() const;

private:
    void generateBlock();
    void solidifyBlock();
    void checkForFullLines();
    void removeRow(rowNumType row);
    void moveSolidBlocksDown(rowNumType lowest_row);

    std::vector<std::array<celltype, 16>> m_patterns;
    std::vector<celltype> m_fields;
    std::shared_ptr<Block> m_current_block;
    Clock m_clock;
    timetype m_tick_ms;

};


#endif
