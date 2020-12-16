#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texturePath) {
    SDL_Surface* temp_surface = IMG_Load(texturePath);
    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    return texture;
}