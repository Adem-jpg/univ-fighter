#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "commun.hpp"

struct textures_s{
    SDL_Texture* map;
};

typedef struct textures_s textures_t;

int init_sdl(SDL_Window** window, SDL_Renderer** renderer);
void quit_sdl(SDL_Window* window, SDL_Renderer* renderer);
void init_textures(textures_t* t, SDL_Renderer* r);
void clean_textures(textures_t* t);

#endif