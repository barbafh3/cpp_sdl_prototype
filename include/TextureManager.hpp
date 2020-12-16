#pragma once

#include "Game.hpp"

class TextureManager {
    SDL_Texture* LoadTexture(const char* texturePath);
};