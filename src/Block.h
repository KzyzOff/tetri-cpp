
#ifndef TETRIS_CPP_BLOCK_H
#define TETRIS_CPP_BLOCK_H

#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include "CONSTANT.h"
#include "common.h"
#include "types.h"

class Block {
public:
    Block(std::array<celltype, 16> pattern, Vec2i position);

    void rotate(const std::vector<celltype>& board, bool clockwise);
    void move(const std::vector<celltype>& board, Direction d);

    static bool canRotate(const std::vector<celltype>& board, const Block* block, bool clockwise);
    static bool canMove(const std::vector<celltype>& board, const Block* block, Direction d);
    static bool collides(const std::vector<celltype>& board, const Block* block);

    [[nodiscard]] std::array<celltype, 16> getFields() const;
    [[nodiscard]] Vec2i getPosition() const { return m_current_pos; };

    void debugDraw() const;

private:
    std::array<celltype, 16> m_fields;
    Vec2i m_current_pos;

};

#endif
