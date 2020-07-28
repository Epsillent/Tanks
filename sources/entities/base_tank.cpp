#include "entities/base_tank.hpp"
#include "entities/bar.hpp"

BaseTank::BaseTank(const sf::Color& color):
    speed(20),
    health(100),
    time(0)
{
    set_tag("Tank");

    body = component_add<Sprite2D>();
    body->set_color(color);
    body->set_size(TANK_WIDTH,TANK_HEIGTH);


    Rigidbody2DProperties rbprops;
    rbprops.gravity = sf::Vector2f(0,0);
    rbprops.mass = 1.f;
    rbprops.inertia = 0.1f;
    rb = component_add<Rigidbody2D>(rbprops);
    rb->collider_add(sf::Vector2f(TANK_WIDTH,TANK_HEIGTH));

    BarProps live(&health);
    live.position = sf::Vector2f(0,-20);
    child_add(new Bar(live));

    BarProps shoot(&time);
    shoot.position = sf::Vector2f(0,-10);
    shoot.value_max = missile.shoot_speed;
    shoot.current = sf::Color::Yellow;
    shooting_speed = new Bar(shoot);
    child_add(shooting_speed);


    tower = component_add<Sprite2D>();
    tower->set_size(TANK_WIDTH/4,TANK_HEIGTH);
    tower->set_color(sf::Color::Green);
    tower->set_origin(sf::Vector2f(TANK_WIDTH/4/2,TANK_HEIGTH));
    tower->set_position(sf::Vector2f(TANK_WIDTH/2,TANK_HEIGTH/2));
}


void BaseTank::on_update(float dt){
    time +=dt;
    handle_movement();
    handle_shooting();
}

void BaseTank::hit(float d){
    health -=d;
    if(health <= 0)
        destroy();
}


