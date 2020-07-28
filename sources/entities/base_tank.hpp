#ifndef TANK_H
#define TANK_H

#include "engine.hpp"
#include "components/sprite_2d.hpp"
#include "components/rigidbody_2d.hpp"
#include "components/particle_system.hpp"
#include "entities/missile.hpp"
#include "entities/bar.hpp"
#define TANK_WIDTH 100
#define TANK_HEIGTH 100



class BaseTank: public GameObject{
protected:
    Sprite2D *body;
    Sprite2D *tower;
    Rigidbody2D *rb;
    float speed;
    float health;
    float time;
    MissileConf missile;
    Bar* shooting_speed;




public:
    BaseTank(const sf::Color&);
    virtual void on_update(float dt);


    void hit(float damage);


    virtual void handle_movement() = 0;
    virtual void handle_shooting() = 0;
};

#endif