#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "commun.hpp"

#define NOATTACKS 0
#define KICK 1
#define HIGHKICK 2
#define PUNCH 3

class Player{
    private:
        int p_x,p_y;
        double p_health;
        int p_attack;
    public:

    Player(int player);
    void moveLeft();
    void moveRight();
    int getX(){return p_x;}
    int getY(){return p_y;}
    void setX(int x);
    void setY(int y);
    double getHealth(){return p_health;}
    void reduceHP(double x);
    void setAttack(int attack);
    int getAttack(){return p_attack;}
    void resetAttack(){p_attack = NOATTACKS;}

};

#endif