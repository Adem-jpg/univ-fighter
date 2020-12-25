#include "logic.hpp"

void init_game(game_t* g){
    g->ingame = true;
    g->window = NULL;
    g->renderer = NULL;
}

void update_data(Player* p1, Player* p2){
    printf("%i\n",p1->getAttack());
    if((p2->getX()-p1->getX())<200){
        std::cout << "collision" << std::endl;

    } else {
        std::cout << "no collision" << std::endl;
    }
    //collision
    //if collision == 1 {handle attacks}
}
