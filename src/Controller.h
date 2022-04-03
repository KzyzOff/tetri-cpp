
#ifndef TETRIS_CPP_CONTROLLER_H
#define TETRIS_CPP_CONTROLLER_H

#include "header.h"

class Controller
{
public:
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void update() = 0;
    virtual void handleEvents(SDL_Event& ev) = 0;

    virtual ~Controller() = default;

};

#endif
