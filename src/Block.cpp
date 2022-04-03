
#include "Block.h"

Block::Block(std::array<celltype, 16> pattern, Vec2i position)
    : m_fields(pattern),
      m_current_pos(position)
      {}

void Block::rotate(const std::vector<celltype>& board, bool clockwise)
{
    if (!canRotate(board, this, clockwise))
        return;

    std::array<celltype, 16> rotated_pattern {};

    for (size_t x = 0; x < 4; x++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            if (clockwise)
            {
                rotated_pattern.at(12 - 4 * x + y) = getFields().at(x + 4 * y);
            }
            else
            {
                rotated_pattern.at(3 + 4 * x - y) = getFields().at(x + 4 * y);
            }
        }
    }

    m_fields = rotated_pattern;
}

bool Block::canRotate(const std::vector<celltype> &board, const Block* block, bool clockwise)
{
    std::array<celltype, 16> rotated_pattern {};

    for (size_t x = 0; x < 4; x++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            if (clockwise)
            {
                rotated_pattern.at(12 - 4 * x + y) = block->getFields().at(x + 4 * y);
            }
            else
            {
                rotated_pattern.at(3 + 4 * x - y) = block->getFields().at(x + 4 * y);
            }
        }
    }

    auto b = std::make_shared<Block>(rotated_pattern, block->getPosition());

    return !collides(board, b.get());
}

void Block::move(const std::vector<celltype>& board, Direction d)
{
    if (!canMove(board, this, d))
        return;

    switch (d)
    {
        case Direction::DOWN:
            m_current_pos.y += 1;
            break;

        case Direction::LEFT:
            m_current_pos.x -= 1;
            break;

        case Direction::RIGHT:
            m_current_pos.x += 1;
            break;
    }
}

bool Block::canMove(const std::vector<celltype>& board, const Block* block, Direction d)
{
    std::unique_ptr<Block> b = nullptr;
    Vec2i block_pos = block->getPosition();
    switch (d)
    {
        case Direction::DOWN:
            b = std::make_unique<Block>(Block(block->getFields(), {block_pos.x, block_pos.y + 1}));
            break;

        case Direction::LEFT:
            b = std::make_unique<Block>(Block(block->getFields(), {block_pos.x - 1, block_pos.y}));
            break;

        case Direction::RIGHT:
            b = std::make_unique<Block>(Block(block->getFields(), {block_pos.x + 1, block_pos.y}));
            break;
    }

    return !collides(board, b.get());
}

bool Block::collides(const std::vector<celltype> &board, const Block* block)
{
    Vec2i pos = block->getPosition();
    for (size_t x = 0; x < 4; x++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            if (pos.x + x + (pos.y + y) * BOARD_WIDTH >= board.size())
                continue;

            if (board.at(pos.x + x + (pos.y + y) * BOARD_WIDTH) != ' ' && block->getFields().at(x + y * 4) != ' ')
                return true;
        }
    }

    return false;
}

std::array<celltype, 16> Block::getFields() const
{
    return m_fields;
}

void Block::debugDraw() const
{
    for (int i = 0; i < 16; i++)
    {
        printf("%c", m_fields.at(i));
        if (i != 0 && (i + 1) % 4 == 0)
            printf("\n");
    }
}
