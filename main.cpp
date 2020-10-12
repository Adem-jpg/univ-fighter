#include <SDL2/SDL.h>
#include <iostream>


int main()
{
    SDL_Window* fenetre; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
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
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //Creation du renderer
    renderer = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer){
        std::cout << "Erreur creation du Renderer" <<std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //Chargement d'une surface
    surfaceTest = SDL_LoadBMP("ressources/images/maps/map_ampli.bmp");
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
        while( SDL_PollEvent( &evenements ) )
            switch(evenements.type)
            {
                case SDL_QUIT:
                    terminer = true; break;
                case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true; break;
                }
            }
    }

    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}