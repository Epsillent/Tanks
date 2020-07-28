#ifndef ENEMY_TANK_H
#define ENEMY_TANK_H
#include "entities/base_tank.hpp"



class EnemyTank: public BaseTank{
public:
    EnemyTank();
    void handle_movement()override;
    void handle_shooting()override;
};

#endif