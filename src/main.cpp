#include <iostream>
#include <list>

#include "Entity.hpp"
#include "Game.hpp"
#include "Math.hpp"

Game* game = nullptr;

const int FPS = 60;
const int frameDelay = 1000 / 60;

SDL_Texture* tileSet;

int tileMap[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // -
};

int main() {
    game = new Game();
    game->init("Test", 400, 400, 800, 600, false);

    tileSet = game->loadTexture("assets/tileset.png");

    Entity knight(Vector2(416, 416), tileSet, Vector2(16 * 2, 16 * 16));
    // Entity knight4(400 + (16 * 4), 400 + (16 * 4), knightTexture);

    std::list<Entity> e_list;
    e_list.insert(e_list.begin(), knight);
    // e_list.insert(e_list.begin(), knight2);
    // e_list.insert(e_list.begin(), knight3);
    // e_list.insert(e_list.begin(), knight4);

    Uint32 frameStart;
    int frameTime;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double delta_time = 0;

    while (game->running()) {
        frameStart = SDL_GetTicks();
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        delta_time = ((double)((LAST - NOW) * 1000 /
                               (double)SDL_GetPerformanceFrequency())) *
                     0.001;

        game->handleEvents();
        game->update(delta_time);
        game->render(e_list);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}
