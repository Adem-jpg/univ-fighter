#include "graphic.hpp"
#include "logic.hpp"
#include "player.hpp"

void handle_events(SDL_Event* events,game_t* game, textures_t* textures){
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
                    case SDLK_k:
                        textures->player1 = textures->player1kick;
                        break;
                    default:
                        break;
                }
            }
            if(events->type == SDL_KEYUP){
                switch(events->key.keysym.sym){
                    case SDLK_a:
                        textures->player1 = textures->player1neutral;
                        break;
                    case SDLK_k:
                        textures->player1 = textures->player1neutral;
                        break;
                    default:
                        break;
                }
            }
        }
}

int main(){
    game_t* game = (game_t*)malloc(sizeof(game_t*));
    init_game(game);
    textures_t* textures = (textures_t*)malloc(sizeof(textures_t*));
    SDL_Event events;

    if(init_sdl(&game->window,&game->renderer)){
        std::cout << "Quitting sdl: ";
        std::cout << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    init_textures(textures,game->renderer);

    // Boucle principale
    while(game->ingame){
        handle_events(&events,game,textures);
 
        // Affichage a l'ecran
        update_graphics(game->renderer,textures);
    }
    // SDL_RenderClear(game->renderer);
    clean_textures(textures);
    quit_sdl(game->window,game->renderer);
    // free(textures);
    free(game);
    return 0;
}
