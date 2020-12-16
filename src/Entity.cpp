#include "Entity.hpp"

#include "Math.hpp"

Entity::Entity(Vector2 p_position, SDL_Texture *p_texture,
               Vector2 p_spriteCoord)
    : position(p_position), texture(p_texture), spriteCoord(p_spriteCoord) {
    currentFrame.x = p_spriteCoord.x;
    currentFrame.y = p_spriteCoord.y;
    currentFrame.w = 16;
    currentFrame.h = 16;
}
