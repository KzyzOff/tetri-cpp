
#include "Board.h"

Board::Board()
    : m_clock(Clock()),
      m_current_block(nullptr),
      m_patterns({Pattern::L, Pattern::J, Pattern::I, Pattern::Z, Pattern::S, Pattern::T, Pattern::T, Pattern::O}),
      m_fields({}),
      m_tick({800, 800, false}),
      m_next_block_idx(-1),
      m_score(0)
{
    m_fields.clear();
    m_fields.resize(BOARD_WIDTH * (BOARD_HEIGHT + BOARD_OFFSET));

    for (size_t x = 0; x < BOARD_WIDTH; x++)
    {
        for (size_t y = 0; y < BOARD_HEIGHT + BOARD_OFFSET; y++)
        {
            m_fields.at(x + y * BOARD_WIDTH)
                    = (x == 0 || x == BOARD_WIDTH - 1 || y == BOARD_HEIGHT + BOARD_OFFSET - 1)
                    ? '#' : ' ';
        }
    }

    genBlockAndNext();

    m_clock.start();
}

void Board::update()
{
    updateBoard();
}

void Board::updateBoard()
{
    if (m_clock.duration() < m_tick.current)
        return;

    if (Block::canMove(m_fields, m_current_block.get(), Direction::DOWN))
    {
        m_current_block->move(m_fields, Direction::DOWN);
    }
    else
    {
        solidifyBlock();
        removeFullRows();
        genBlockAndNext();
        updateTimeTick();
    }

    m_clock.init();
    m_clock.start();
}

void Board::updateTimeTick()
{
    if (m_tick.base > 200)
        m_tick.base = 800 - m_score / 18;
}

void Board::placeBlockDown()
{
    while (Block::canMove(m_fields, m_current_block.get(), Direction::DOWN))
    {
        m_current_block->move(m_fields, Direction::DOWN);
    }
    solidifyBlock();
    removeFullRows();
    genBlockAndNext();
}

void Board::toggleSpeedUp()
{
    if (!m_tick.is_sped_up)
        m_tick.current = m_tick.base / 2;
    else
        m_tick.current = m_tick.base;
    m_tick.is_sped_up = !m_tick.is_sped_up;
}

void Board::genBlockAndNext()
{
    std::random_device r;
    std::default_random_engine generator(r());
    std::uniform_int_distribution<size_t> distribution(0, static_cast<int>(m_patterns.size() - 1));

    if (m_next_block_idx == -1) {
        size_t idx = distribution(generator);
        m_current_block = std::make_shared<Block>(Block(m_patterns.at(idx), {BOARD_WIDTH / 2 - 2, 0}));
    }
    else
        m_current_block = std::make_shared<Block>(Block(m_patterns.at(m_next_block_idx), {BOARD_WIDTH / 2 - 2, 0}));

    m_next_block_idx = distribution(generator);
}

void Board::solidifyBlock()
{
    for (size_t x = 0; x < 4; x++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            if (m_current_block->getFields().at(x + 4 * y) != ' ')
            {
                m_fields.at(m_current_block->getPosition().x + x + (m_current_block->getPosition().y + y) * BOARD_WIDTH)
                        = m_current_block->getFields().at(x + 4 * y);
            }
        }
    }
}

void Board::removeFullRows()
{
    int removed_rows = 0;
    for (int row = BOARD_OFFSET; row < BOARD_HEIGHT + BOARD_OFFSET - 1; row++)
    {
        bool isFull = true;
        for (int cell_in_row_idx = 0; cell_in_row_idx < BOARD_WIDTH; cell_in_row_idx++)
        {
            if (m_fields.at(cell_in_row_idx + row * BOARD_WIDTH) == '#')
                continue;

            if (m_fields.at(cell_in_row_idx + row * BOARD_WIDTH) == ' ')
            {
                isFull = false;
                break;
            }
        }

        if (isFull)
        {
            removeRow(row);
            moveSolidBlocksDown(row - 1);
            removed_rows++;
        }
    }

    if (removed_rows > 0)
        m_score += removed_rows * 100;
}

void Board::removeRow(rowNumType row)
{
    for (int i = 1; i < BOARD_WIDTH - 1; i++)
    {
        m_fields.at(i + row * BOARD_WIDTH) = ' ';
    }
}

void Board::moveSolidBlocksDown(rowNumType lowest_row)
{
    for (;lowest_row > BOARD_OFFSET - 1; lowest_row--)
    {
        for (int cell_in_row_idx = 1; cell_in_row_idx < BOARD_WIDTH - 1; cell_in_row_idx++)
        {
            int current_idx = cell_in_row_idx + lowest_row * BOARD_WIDTH;
            m_fields.at(current_idx + BOARD_WIDTH) = m_fields.at(current_idx);
            m_fields.at(current_idx) = ' ';
        }
    }
}

void Board::setTickMS(timetype tick_ms)
{
    m_tick.base = tick_ms;
}

std::vector<celltype> Board::getBoardWithCurrentBlock() const
{
    std::vector<celltype> output {};
    output.clear();
    output.resize(BOARD_WIDTH * (BOARD_HEIGHT + BOARD_OFFSET));

    for (size_t i = 0; i < m_fields.size(); i++)
    {
        output.at(i) = m_fields.at(i);
    }

    for (size_t x = 0; x < 4; x++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            if (m_current_block->getFields().at(x + 4 * y) != ' ')
            {
                output[m_current_block->getPosition().x + x + (m_current_block->getPosition().y + y) * BOARD_WIDTH]
                        = m_current_block->getFields().at(x + 4 * y);
            }
        }
    }

    return output;
}

std::vector<celltype> Board::getBoard() const
{
    return m_fields;
}

std::shared_ptr<Block> Board::getCurrentBlockPtr() const
{
    return m_current_block;
}

std::vector<celltype> Board::getNextBlockPattern() const
{
    return {m_patterns.at(m_next_block_idx).begin(), m_patterns.at(m_next_block_idx).end()};
}

int Board::getScore() const
{
    return m_score;
}

void Board::debugDraw() const
{
    auto output = getBoardWithCurrentBlock();

    for (size_t i = 0; i < output.size(); i++)
    {
        printf("%c", output.at(i));
        if ((i + 1) % BOARD_WIDTH == 0 && i != BOARD_WIDTH * BOARD_OFFSET)
            printf("\n");
    }
}
