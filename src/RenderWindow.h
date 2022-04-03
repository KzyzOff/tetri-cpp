
#ifndef TETRIS_CPP_RENDERWINDOW_H
#define TETRIS_CPP_RENDERWINDOW_H

#include <cstdio>
#include <memory>
#include "CONSTANT.h"
#include "header.h"
#include "Entity.h"

class RenderWindow {
public:
    ~RenderWindow();
    static RenderWindow* instance();

    std::unique_ptr<SDL_Texture> loadTexture(const char* filepath);
    void clear() const { SDL_RenderClear(m_renderer); };
    void display() const { SDL_RenderPresent(m_renderer); };
    void render(Entity& e);

    SDL_Renderer* getRenderer() { return m_renderer; };
    SDL_Window* getWindow() { return m_window; };

private:
    RenderWindow(SDL_Window* window, SDL_Renderer* renderer);

    static RenderWindow* m_instance;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

};


#endif //TETRIS_CPP_RENDERWINDOW_H
