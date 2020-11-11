#include "graphic.hpp"
#include "logic.hpp"

int main(){
    game_t* game = (game_t*)malloc(sizeof(game_t*));
    init_game(game);
    SDL_Window* window = NULL; // Déclaration de la fenêtre
    SDL_Event events; // Événements liés à la fenêtre
    textures_t* textures = (textures_t*)malloc(sizeof(textures_t*));
    SDL_Renderer* renderer = NULL;

    if(init_sdl(&window,&renderer)){
        std::cout << "Quitting sdl: ";
        std::cout << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    init_textures(textures,renderer);

    // Boucle principale
    while(game->ingame){
        while(SDL_PollEvent(&events)){
            switch(events.type){
                case SDL_QUIT:
                    game->ingame = false;
                    break;
                case SDL_KEYDOWN: // a modifier
                switch(events.key.keysym.sym){
                    case SDLK_ESCAPE:
                        game->ingame = false;
                        break;
                }
            }
        }
        // Affichage a l'ecran
        update_graphics(renderer,textures);
    }
    clean_textures(textures);
    // Quitter SDL
    quit_sdl(window,renderer);
    return 0;
}
