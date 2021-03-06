#include "graphic.hpp"

int init_sdl(SDL_Window** window, SDL_Renderer** renderer){
    
    // Initialisation de SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Erreur d’initialisation SDL: ";
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Creation de la fenêtre
    *window = SDL_CreateWindow("univ-fighter", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_RESIZABLE);
    if(!window){
        std::cout << "Erreur de la creation d’une fenetre: ";
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Creation du renderer
    *renderer = SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer){
        std::cout << "Erreur creation du Renderer: ";
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    return 0;
    
}

void quit_sdl(SDL_Window* window, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    printf("Destroyed: renderer\n");
    SDL_DestroyWindow(window);
    printf("Destroyed: window\n");
    SDL_Quit();
}

void init_textures(textures_t* t,SDL_Renderer* r){

    //map texture load
    SDL_Surface* sTemp = SDL_LoadBMP("ressources/images/maps/map_chat.bmp");
    if(!sTemp){
        std::cout << "Erreur chargement de la surface de la map: ";
        std::cout << SDL_GetError() << std::endl;
    }
    t->map = SDL_CreateTextureFromSurface(r,sTemp);
    SDL_FreeSurface(sTemp);

    //player 1 texture load
    sTemp = SDL_LoadBMP("ressources/images/player/player1neutral.bmp");
    if(!sTemp){
        std::cout << "Erreur chargement de la surface du joueur: ";
        std::cout << SDL_GetError() << std::endl;
    }
    t->player1neutral = SDL_CreateTextureFromSurface(r,sTemp);
    SDL_FreeSurface(sTemp);

    //player 1 high kick texture load
    sTemp = SDL_LoadBMP("ressources/images/player/player1highkick.bmp");
    if(!sTemp){
        std::cout << "Erreur chargement de la surface du high kick du joueur 1: ";
        std::cout << SDL_GetError() << std::endl;
    }
    t->player1highkick = SDL_CreateTextureFromSurface(r,sTemp);
    SDL_FreeSurface(sTemp);


    //player 1 kick texture load
    sTemp = SDL_LoadBMP("ressources/images/player/player1kick.bmp");
    if(!sTemp){
        std::cout << "Erreur chargement de la surface du kick du joueur 1: ";
        std::cout << SDL_GetError() << std::endl;
    }
    t->player1kick = SDL_CreateTextureFromSurface(r,sTemp);
    SDL_FreeSurface(sTemp);

    t->player1 = t->player1neutral;
    t->player2 = t->player1neutral;
}

void clean_textures(textures_t* t){
    SDL_DestroyTexture(t->map);
    printf("Destroyed: map\n");
    SDL_DestroyTexture(t->player1neutral);
    printf("Destroyed: player1neutral\n");
    SDL_DestroyTexture(t->player1highkick);
    printf("Destroyed: player1highkick\n");
    SDL_DestroyTexture(t->player1kick);
    printf("Destroyed: player1kick\n");
}

void update_graphics(SDL_Renderer* r,textures_t* t,Player* p1,Player* p2){
    if(p1->getAttack()==NOATTACKS){
        t->player1=t->player1neutral;
    }
    if(p1->getAttack()==KICK){
        t->player1=t->player1kick;
    }
    if(p1->getAttack()==HIGHKICK){
        t->player1=t->player1highkick;
    }
    SDL_RenderClear(r);    
    SDL_RenderCopy(r,t->map,NULL,NULL);
    SDL_Rect rectp1 = {p1->getX(),p1->getY(),200,400};
    SDL_Rect rectp2 = {p2->getX(),p2->getY(),200,400};
    SDL_RenderCopy(r,t->player1, NULL, &rectp1);
    SDL_RenderCopy(r,t->player2, NULL, &rectp2);
    SDL_RenderPresent(r);
}
