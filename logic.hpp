#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "commun.hpp"

struct game_s{
    bool ingame;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

typedef struct game_s game_t;

void init_game(game_t* g);

#endif