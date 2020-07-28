#include "entities/missile.hpp"
#include "unistd.h"
#include "entities/explosion.hpp"
#include "entities/base_tank.hpp"

Missile::Missile(const sf::Vector2f& dir,const MissileConf& conf):
    direction(dir),
    speed(conf.speed),
    damage(conf.damage),
    time(0),
    begin(conf.begin),
    end(conf.end)
{
    set_tag("Missile");
    ParticleSystemProperties props;
    props.color_begin = begin;
    props.color_end = end;
    props.size = sf::Vector2f(10,10);
    props.dispersion = sf::Vector2i(10,10);
    props.spawn_rate = 0.00001;
    ps = component_add<ParticleSystem>(props);


    Trigger2DProperties tgprops;
    tgprops.callback = CALLBACK(&Missile::on_collided);
    tgprops.size = Trigger2D::size(15,15);
    trigger = component_add<Trigger2D>(tgprops);

}


void Missile::on_update(float dt){
    time += dt;
    if(time > 1.f){
        destroy();
    }
    translate(direction*speed*dt);
}

void Missile::on_collided(Trigger2D other){
    //Info("Missile collided with "+ other.owner()->tag());
    if(other.owner()->tag()=="Tank"){
        static_cast<BaseTank*>(other.owner())->hit(damage);
    }
    object_introduce(new Explosion(begin,end,0.2f));
    destroy();
}