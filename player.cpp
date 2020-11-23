#include "player.hpp"

class Player
{
    private:
        int x,y;
        double health;        
    public:
    Player(int player){
        if(player == 1){
            x = 200;
            y = 350;
        } else {
            x = 1200;
            y = 350;
        }
    }
    ~Player();
};

Player::

Player::~Player(){
    
}
