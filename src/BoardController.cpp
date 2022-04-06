
#include "BoardController.h"

BoardController::BoardController()
    : m_font_mgr(FontManager("../assets/VCR_OSD_MONO.ttf")),
      m_input_handler(BoardInputHandler()),
      m_board(Board()),
      m_view(m_board, m_font_mgr) {}

void BoardController::update()
{
    m_board.update();
    m_view.update();
}

void BoardController::draw(SDL_Renderer *renderer)
{
    m_view.draw(renderer);
}

void BoardController::handleEvents(SDL_Event &ev)
{
    m_input_handler.handleEvents(ev, m_board);
}
