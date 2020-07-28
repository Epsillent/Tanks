#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "engine.hpp"
#include "components/particle_system.hpp"
#include "utils/debug.hpp"

struct Explosion: public GameObject{
    ParticleSystem * system;
    float lifetime;
    float time;
    Explosion(const sf::Color& begin, const sf::Color& end,float scale):
        time(0), lifetime(0.1f)
    {
        ParticleSystemProperties props;
        props.color_begin = begin;
        props.size = sf::Vector2f(50,50)*scale;
        props.color_end = end;
        props.speed = 50;
        props.spawn_rate = 0.00001;
        props.life_time = lifetime*8;
        props.dispersion = sf::Vector2i(50*scale,50*scale);
        system = component_add<ParticleSystem>(props);
    }
    void on_update(float dt)override{
        time += dt;
        if(time > lifetime){
            destroy();
        }
    }
};

#endif