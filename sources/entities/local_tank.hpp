#ifndef LOCAL_TANK_H
#define LOCAL_TANK_H
#include "entities/base_tank.hpp"

class LocalTank: public BaseTank{
public:
    LocalTank();
    void handle_movement()override;
    void handle_shooting()override;
};

#endif