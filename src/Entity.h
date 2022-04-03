
#ifndef TETRIS_CPP_ENTITY_H
#define TETRIS_CPP_ENTITY_H

#include "header.h"
#include "common.h"
#include "Color.h"

class Entity {
public:
    Entity();
    Entity(Vec2i pos, int w, int h, SDL_Color color);

    void draw(SDL_Renderer* renderer) const;

    void setColor(SDL_Color color);
    void setPos(Vec2i pos);
    void setSize(int w, int h);

    [[nodiscard]] SDL_Rect getRect() const { return m_rect; };

private:
    SDL_Rect m_rect;
    SDL_Color m_color;

};

#endif
