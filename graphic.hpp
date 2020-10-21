#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "commun.hpp"

int init_sdl(SDL_Window** window, SDL_Renderer** renderer);
void quit_sdl(SDL_Window* window, SDL_Renderer* renderer);

#endif