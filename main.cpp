#include "graphic.hpp"
#include "logic.hpp"
#include "player.hpp"
#include "events.hpp"


int main(){
    game_t* game = (game_t*)malloc(sizeof(game_t*));
    init_game(game);
    textures_t* textures = (textures_t*)malloc(sizeof(textures_t*));
    SDL_Event events;

    Player p1 = Player(1);

    if(init_sdl(&game->window,&game->renderer)){
        std::cout << "Quitting sdl: ";
        std::cout << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    init_textures(textures,game->renderer);

    // Boucle principale
    while(game->ingame){
        // printf("player pos x: %i, y: %i\n",p1.getX(),p1.getY());
        handle_events(&events,game,textures,&p1);


 
        // Affichage a l'ecran
        update_graphics(game->renderer,textures,p1);
    }
    clean_textures(textures);
    quit_sdl(game->window,game->renderer);
    // free(textures);
    free(game);
    return 0;
}
