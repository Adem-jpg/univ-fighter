#include "graphic.hpp"

int main(){
    bool terminer = false;
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
    while(!terminer){
        while(SDL_PollEvent(&events)){
            switch(events.type){
                case SDL_QUIT:
                    terminer = true;
                    break;
                case SDL_KEYDOWN: // a modifier
                switch(events.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;
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
