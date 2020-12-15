#include "events.hpp"

void handle_events(SDL_Event* events,game_t* game, textures_t* textures,Player* p1,Player* p2){
    while(SDL_PollEvent(events)){
        if(events->type == SDL_QUIT){
            game->ingame = false;
        }
        if(events->type == SDL_KEYDOWN){
            switch(events->key.keysym.sym){
                case SDLK_ESCAPE:
                    game->ingame = false;
                    break;
                case SDLK_a:
                    textures->player1 = textures->player1highkick;
                    break;
                case SDLK_d:
                    textures->player1 = textures->player1kick;
                    break;
                case SDLK_q:
                    p1->moveLeft();
                    break;
                case SDLK_e:
                    p1->moveRight();
                    break;
                case SDLK_o:
                    p2->moveLeft();
                    break;
                case SDLK_LEFTBRACKET:
                    p2->moveRight();
                default:
                    break;
            }
        }
        if(events->type == SDL_KEYUP){
            switch(events->key.keysym.sym){
                case SDLK_a:
                    textures->player1 = textures->player1neutral;
                    break;
                case SDLK_d:
                    textures->player1 = textures->player1neutral;
                    break;
                default:
                    break;
            }
        }
    }
}
