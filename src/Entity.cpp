
#include "Entity.h"

Entity::Entity()
    : m_rect({0, 0, 10, 10}),
      m_color(Color::white)
{

}

Entity::Entity(Vec2i pos, int w, int h, SDL_Color color)
    : m_rect({pos.x, pos.y, w, h}),
      m_color(color)
{

}

void Entity::draw(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderFillRect(renderer, &m_rect);
}

void Entity::setColor(SDL_Color color)
{
    m_color = color;
}

void Entity::setPos(Vec2i pos)
{
    m_rect.x = pos.x;
    m_rect.y = pos.y;
}

void Entity::setSize(int w, int h)
{
    m_rect.w = w;
    m_rect.h = h;
}
