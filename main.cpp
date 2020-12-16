#include "graphic.hpp"
#include "logic.hpp"
#include "player.hpp"
#include "events.hpp"

void update_data(Player* p1, Player* p2){
    if((p2->getX()-p1->getX())<200){
        std::cout << "collision" << std::endl;
    } else {
        std::cout << "no collision" << std::endl;
    }
    //collision
    //if collision == 1 {handle attacks}
}


int main(){
    game_t* game = (game_t*)malloc(sizeof(game_t*));
    init_game(game);
    textures_t* textures = (textures_t*)malloc(sizeof(textures_t*));
    SDL_Event events;

    Player p1 = Player(1);
    Player p2 = Player(2);

    if(init_sdl(&game->window,&game->renderer)){
        std::cout << "Quitting sdl: ";
        std::cout << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    init_textures(textures,game->renderer);

    // Boucle principale
    while(game->ingame){
        handle_events(&events,game,textures,&p1,&p2);

        update_data(&p1,&p2);
 
        // Affichage a l'ecran
        update_graphics(game->renderer,textures,p1,p2);
    }
    clean_textures(textures);
    quit_sdl(game->window,game->renderer);
    // free(textures);
    free(game);
    return 0;
}
