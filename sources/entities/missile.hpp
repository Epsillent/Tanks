#ifndef MISSILE_H
#define MISSILE_H

#include "engine.hpp"
#include "components/particle_system.hpp"
struct MissileConf{
    float shoot_speed;
    sf::Color begin,end;
    float speed;
    float damage;
    MissileConf():
        shoot_speed(0.4f), begin(sf::Color::Yellow), end(sf::Color::Red), speed(800), damage(25)
    {}

    void def(){
        shoot_speed= 0.4f;
        begin = sf::Color::Yellow;
        end = sf::Color::Red;
        speed = 800;
        damage = 25;
    }
    void fast(){
        shoot_speed= 0.2f;
        begin = sf::Color::Yellow;
        end = sf::Color::Red;
        speed = 1000;
        damage = 10;
    }
    void lightning(){
        shoot_speed= 2.f;
        begin = sf::Color::White;
        end = sf::Color::Blue;
        speed = 6000;
        damage = 95;
    }
};


class Missile: public GameObject{
private:
    ParticleSystem* ps;
    Trigger2D* trigger;
    sf::Vector2f direction;
    sf::Color begin,end;
    float speed;
    float damage;
    float time;
public:
    Missile(const sf::Vector2f& direction,const MissileConf&);
    void on_update(float dt)override;
    void on_collided(Trigger2D other);
};



#endif