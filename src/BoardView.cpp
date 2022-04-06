
#include "BoardView.h"

BoardView::BoardView(Board& board, FontManager& fm)
    : m_font_mgr(fm),
      m_board(board),
      m_cell_size(0),
      m_tlc({0, 0}),
      m_score_pos({0, 0})
{
    setBoardSizingAndPos();
}

void BoardView::setBoardSizingAndPos()
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

    setPreviewSizingAndPos(m_cell_size);
    setScoreSizingAndPos({m_tlc.x + m_cell_size * BOARD_WIDTH + 40, m_cell_size});
}

void BoardView::setPreviewSizingAndPos(int board_cell_size)
{
    int size = static_cast<int>(m_tlc.x / 4);
    Vec2i tlc {m_tlc.x / 2 - size * 2, board_cell_size * 3};

    m_preview_grid.clear();
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            m_preview_grid.push_back(Entity({tlc.x + size * x, tlc.y + size * y},
                                            size, size, getCellColor(' ')));
        }
    }
}

void BoardView::setScoreSizingAndPos(Vec2i board_trc_pos)
{
    m_font_mgr.setSize(30);
    m_font_mgr.setColor(Color::orange);
    m_score_pos = {board_trc_pos.x, board_trc_pos.y + 30};
}

void BoardView::draw(SDL_Renderer* renderer)
{
    for (const auto& cell : m_grid)
    {
        cell.draw(renderer);
    }

    drawNextBlockPreview(renderer);
    drawScore(renderer);
}

void BoardView::drawNextBlockPreview(SDL_Renderer* renderer)
{
    for (const auto& cell : m_preview_grid)
    {
        cell.draw(renderer);
    }
}

void BoardView::drawScore(SDL_Renderer *renderer)
{
    m_font_mgr.draw(renderer, m_score_pos.x, m_score_pos.y, std::to_string(m_board.getScore()));
}

SDL_Color BoardView::getCellColor(celltype cell) const
{
    SDL_Color color;
    switch (cell)
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
        default:
            color = Color::light_gray;
            break;
    }

    return color;
}

void BoardView::update()
{
    auto board = m_board.getBoardWithCurrentBlock();
    for (size_t x = 0; x < BOARD_WIDTH; x++)
    {
        for (size_t y = BOARD_OFFSET; y < BOARD_HEIGHT + BOARD_OFFSET; y++)
        {
            SDL_Color color {getCellColor(board.at(x + y * BOARD_WIDTH))};
            m_grid.at(x + (y - BOARD_OFFSET) * BOARD_WIDTH).setColor(color);
        }
    }

    updatePreview();
}

void BoardView::updatePreview()
{
    auto preview = m_board.getNextBlockPattern();
    for (size_t x = 0; x < 4; x++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            m_preview_grid.at(x + y * 4).setColor(getCellColor(preview.at(x + y * 4)));
        }
    }
}