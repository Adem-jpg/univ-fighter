#include "graphic.hpp"


int main()
{
    SDL_Window* window; // Déclaration de la fenêtre
    SDL_Event events; // Événements liés à la fenêtre
    SDL_Renderer* renderer;
    SDL_Surface* surfaceTest;
    SDL_Texture* textureTest;
    bool terminer = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Créer la fenêtre
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_RESIZABLE);
    if(window == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //Creation du renderer
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer){
        std::cout << "Erreur creation du Renderer" <<std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //Chargement d'une surface
    surfaceTest = SDL_LoadBMP("ressources/images/maps/map_chat.bmp");
    if(!surfaceTest){
        std::cout << "Erreur chargement de la surface" <<std::endl;
        SDL_Quit();
        return EXIT_FAILURE;  
    }

    //Chargement d'une texture depuis une surface
    textureTest = SDL_CreateTextureFromSurface(renderer,surfaceTest);
    if(!textureTest){
        std::cout << "Erreur chargement de la texture" <<std::endl;
        SDL_Quit();
        return EXIT_FAILURE;  
    }

    //affichage a l'ecran
    SDL_RenderClear(renderer);    
    SDL_RenderCopy(renderer,textureTest,NULL,NULL);
    SDL_RenderPresent(renderer);

    // Boucle principale
    while(!terminer)
    {
        while( SDL_PollEvent( &events ) )
            switch(events.type)
            {
                case SDL_QUIT:
                    terminer = true; break;
                case SDL_KEYDOWN:
                switch(events.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true; break;
                }
            }
    }

    // Quitter SDL
    SDL_DestroyTexture(textureTest);
    SDL_FreeSurface(surfaceTest);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}