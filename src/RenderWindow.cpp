
#include "RenderWindow.h"

RenderWindow* RenderWindow::m_instance {nullptr};

RenderWindow* RenderWindow::instance()
{
    if (m_instance == nullptr)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {
            SDL_Window* window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                                  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
            if (window)
            {
                printf("Initialized window successfully!\n");
                SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if (renderer)
                {
                    printf("Initialized renderer successfully!\n");
                    m_instance = new RenderWindow(window, renderer);
                }
            }
        }
    }
    return m_instance;
}

RenderWindow::RenderWindow(SDL_Window* window, SDL_Renderer* renderer)
: m_window(window),
  m_renderer(renderer) {}

//std::unique_ptr<SDL_Texture> RenderWindow::loadTexture(const char *filepath)
//{
//
//}

void RenderWindow::render(Entity& e)
{
    SDL_RenderClear(m_renderer);

    SDL_RenderPresent(m_renderer);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    delete m_instance;
}
