#include "graphic.hpp"


int main()
{
    bool terminer = false;
    SDL_Window* window = NULL; // Déclaration de la fenêtre
    SDL_Event events; // Événements liés à la fenêtre
    SDL_Renderer* renderer = NULL;

    if(init_sdl(window,renderer)){
        return EXIT_FAILURE;
    }



    //affichage a l'ecran
    // SDL_RenderClear(renderer);    
    // SDL_RenderCopy(renderer,textureTest,NULL,NULL);
    // SDL_RenderPresent(renderer);

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
    }

    // Quitter SDL
    quit_sdl(window,renderer);
    return 0;
}