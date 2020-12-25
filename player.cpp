#include "player.hpp"

Player::Player(int player){
    if(player == 1){
        p_x = 200;
        p_y = 350;
    } else {
        p_x = 1200;
        p_y = 350;
    }
    p_attack = NOATTACKS;
}

void Player::moveLeft(){
    setX(getX() - 10);
}

void Player::moveRight(){
    setX(getX() + 10);
}

void Player::setX(int x){
    p_x = x;
}

void Player::reduceHP(double x){
    p_x -= x;
    if(p_x<0){p_x=0;}
}

void Player::setAttack(int attack){
    if(p_attack==NOATTACKS){
        p_attack = attack;
    }
}