#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "commun.hpp"
#include "player.hpp"

struct textures_s{
    SDL_Texture* map;
    SDL_Texture* player1neutral;
    SDL_Texture* player1highkick;
    SDL_Texture* player1kick;
    SDL_Texture* player1;
    SDL_Texture* player2neutral;
    SDL_Texture* player2highkick;
    SDL_Texture* player2kick;
    SDL_Texture* player2;
};

typedef struct textures_s textures_t;

int init_sdl(SDL_Window** window, SDL_Renderer** renderer);
void quit_sdl(SDL_Window* window, SDL_Renderer* renderer);
void init_textures(textures_t* t, SDL_Renderer* r);
void clean_textures(textures_t* t);
void update_graphics(SDL_Renderer* r,textures_t* t,Player* p1,Player* p2);

#endif
