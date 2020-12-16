#pragma once

#include "Math.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Entity {
   public:
    Entity(Vector2 p_position, SDL_Texture *p_texture, Vector2 p_spriteCoord);

    Vector2 getPosition() { return position; }
    SDL_Rect getCurrentFrame() { return currentFrame; }
    SDL_Texture *getTexture() { return texture; }

   private:
    Vector2 position;
    SDL_Rect currentFrame;
    SDL_Texture *texture;
    Vector2 spriteCoord;
};