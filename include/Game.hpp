#pragma once

#include <iostream>
#include <list>

#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game {
   public:
    void init(const char *title, int x, int y, int width, int height,
              bool fullscreen);

    void handleEvents();
    void update(double delta);
    void render(std::list<Entity> e_list);
    void clean();

    bool running();

    SDL_Texture *loadTexture(const char *p_filePath);

    static SDL_Renderer *renderer;

   private:
    bool isRunning;
    SDL_Window *window;
};
