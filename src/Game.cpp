// #include <Game.hpp>
#include "Game.hpp"

SDL_Renderer *Game::renderer = nullptr;

void Game::init(const char *title, int x, int y, int width, int height,
                bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::update(double delta) {
    // Updates shit
}

void Game::render(std::list<Entity> e_list) {
    SDL_RenderClear(renderer);

    // Render shit here
    for (Entity e : e_list) {
        SDL_Rect src = e.getCurrentFrame();
        SDL_Rect dst;
        dst.x = e.getPosition().x;
        dst.y = e.getPosition().y;
        dst.w = e.getCurrentFrame().w;
        dst.h = e.getCurrentFrame().h;
        SDL_RenderCopy(renderer, e.getTexture(), &src, &dst);
    }

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running() { return isRunning; }

SDL_Texture *Game::loadTexture(const char *p_filePath) {
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) {
        std::cout << "Failed to load texture from path " << p_filePath
                  << ". Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}