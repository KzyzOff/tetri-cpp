
#include "BoardController.h"

BoardController::BoardController()
    : m_input_handler(BoardInputHandler()),
      m_board(Board()),
      m_view(m_board) {}

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
