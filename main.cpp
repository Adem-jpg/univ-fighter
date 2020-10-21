#include "graphic.hpp"


int main()
{
    bool terminer = false;
    SDL_Window* window = NULL; // Déclaration de la fenêtre
    SDL_Event events; // Événements liés à la fenêtre
    SDL_Renderer* renderer = NULL;
    SDL_Surface* surfaceTest = NULL;
    SDL_Texture* textureTest = NULL;

    if(init_sdl(&window,&renderer)){
        std::cout << "quitting sdl" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    //Chargement d'une surface
    surfaceTest = SDL_LoadBMP("ressources/images/maps/map_chat.bmp");
    if(!surfaceTest){
        std::cout << "Erreur chargement de la surface" <<std::endl;
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;  
    }

    //Chargement d'une texture depuis une surface
    textureTest = SDL_CreateTextureFromSurface(renderer,surfaceTest);
    if(!textureTest){
        std::cout << "Erreur chargement de la texture" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;  
    }

    //affichage a l'ecran
    SDL_RenderClear(renderer);    
    SDL_RenderCopy(renderer,textureTest,NULL,NULL);
    SDL_RenderPresent(renderer);

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