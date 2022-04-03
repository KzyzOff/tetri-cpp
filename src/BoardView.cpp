
#include "BoardView.h"

BoardView::BoardView(Board& board)
    : m_board(board),
      m_cell_size(0),
      m_tlc({0, 0})
{
    setBoardSizingAndPositioning();
}

void BoardView::setBoardSizingAndPositioning()
{
    m_grid.clear();
    m_cell_size = WINDOW_HEIGHT / BOARD_HEIGHT;
    m_tlc.y = 0;
    m_tlc.x = WINDOW_WIDTH / 2 - m_cell_size * BOARD_WIDTH / 2;

    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            m_grid.push_back(Entity({m_tlc.x + m_cell_size * x, m_tlc.y + m_cell_size * y},
                                    m_cell_size, m_cell_size, Color::white));
        }
    }

}

void BoardView::draw(SDL_Renderer *renderer)
{
    for (const auto& cell : m_grid)
    {
        cell.draw(renderer);
    }
}

void BoardView::update()
{
    auto board = m_board.getBoardWithCurrentBlock();
    for (size_t x = 0; x < BOARD_WIDTH; x++)
    {
        for (size_t y = BOARD_OFFSET; y < BOARD_HEIGHT + BOARD_OFFSET; y++)
        {
            SDL_Color color {Color::light_gray};
            switch (board.at(x + y * BOARD_WIDTH))
            {
                case '#':
                    color = Color::black;
                    break;
                case 'I':
                    color = Color::yellow;
                    break;
                case 'J':
                    color = Color::red;
                    break;
                case 'L':
                    color = Color::light_blue;
                    break;
                case 'T':
                    color = Color::orange;
                    break;
                case 'O':
                    color = Color::light_green;
                    break;
                case 'Z':
                    color = Color::dark_gray;
                    break;
                case 'S':
                    color = Color::magenta;
                    break;
            }
            m_grid.at(x + (y - BOARD_OFFSET) * BOARD_WIDTH).setColor(color);
        }
    }
}