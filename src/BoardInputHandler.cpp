
#include "BoardInputHandler.h"

BoardInputHandler::BoardInputHandler()
    : m_left_flag(false),
      m_right_flag(false),
      m_up_flag(false),
      m_down_flag(false),
      m_space_flag(false) {}

void BoardInputHandler::handleEvents(SDL_Event& event, Board& board)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_LEFT:
            if (event.type == SDL_KEYDOWN && !m_left_flag)
            {
                m_left_flag = true;
                board.getCurrentBlockPtr()->move(board.getBoard(), Direction::LEFT);
                return;
            }
            if (event.type == SDL_KEYUP && m_left_flag)
            {
                m_left_flag = false;
                return;
            }
            break;

        case SDLK_RIGHT:
            if (event.type == SDL_KEYDOWN && !m_right_flag)
            {
                m_right_flag = true;
                board.getCurrentBlockPtr()->move(board.getBoard(), Direction::RIGHT);
                return;
            }
            if (event.type == SDL_KEYUP && m_right_flag)
            {
                m_right_flag = false;
                return;
            }
            break;

        case SDLK_UP:
            if (event.type == SDL_KEYDOWN && !m_up_flag)
            {
                m_up_flag = true;
                board.getCurrentBlockPtr()->rotate(board.getBoard(), true);
                return;
            }
            if (event.type == SDL_KEYUP && m_up_flag)
            {
                m_up_flag = false;
                return;
            }
            break;

        case SDLK_SPACE:
            if (event.type == SDL_KEYDOWN && !m_space_flag)
            {
                m_space_flag = true;
                board.placeBlockDown();
                return;
            }
            if (event.type == SDL_KEYUP && m_space_flag)
            {
                m_space_flag = false;
                return;
            }
            break;
    }

}
