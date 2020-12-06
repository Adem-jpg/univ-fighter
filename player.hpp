#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "commun.hpp"

class Player{
    private:
        int p_x,p_y;
        double p_health;        
    public:

    Player(int player);
    void moveLeft();
    void moveRight();
    int getX(){return p_x;}
    int getY(){return p_y;}
    void setX(int x);
    void setY(int y);
    double getHealth(){return p_health;}

};

#endif