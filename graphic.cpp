#include "graphic.hpp"

int init_sdl(SDL_Window* window, SDL_Renderer* renderer){

    // Initialisation de SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Erreur d’initialisation SDL:";
        std::cout << SDL_GetError();
        SDL_Quit();
        return 1;
    }

    // Creer la fenêtre
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_RESIZABLE);
    if(window == NULL){
        std::cout << "Erreur de la creation d’une fenetre:";
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    //Creation du renderer
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer){
        std::cout << "Erreur creation du Renderer";
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    return 0;
}

void quit_sdl(SDL_Window* window, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}