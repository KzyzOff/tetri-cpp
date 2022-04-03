
#include "App.h"

App::App()
    : m_running(true),
      m_current_controller(std::make_unique<BoardController>())
{

}

void App::run()
{
    SDL_Event event;
    while (m_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                m_running = false;
                SDL_Quit();
            }
            m_current_controller->handleEvents(event);
        }

        m_current_controller->update();

        RenderWindow::instance()->clear();
        m_current_controller->draw(RenderWindow::instance()->getRenderer());
//        RenderWindow::instance()->render();
        RenderWindow::instance()->display();
    }
}
