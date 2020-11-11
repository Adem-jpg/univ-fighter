#ifndef LOGIC_HPP
#define LOGIC_HPP

struct game_s{
    bool ingame;
};

typedef struct game_s game_t;

void init_game(game_t* g);

#endif