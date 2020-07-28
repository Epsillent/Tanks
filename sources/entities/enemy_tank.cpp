#include "entities/enemy_tank.hpp"
#include "unistd.h"
#include "core/math/math.hpp"
#include "entities/missile.hpp"
#include "entities/bar.hpp"

EnemyTank::EnemyTank():
    BaseTank(sf::Color(255,54,151))
{
    missile.lightning();
    BarProps shoot(&time);
    shoot.position = sf::Vector2f(0,-10);
    shoot.value_max = missile.shoot_speed;
    shoot.current = sf::Color::Yellow;
    shooting_speed->reset(shoot);
}




void EnemyTank::handle_movement(){
    if(Input::key_pressed(KeyCode::Up)){
        //translate(0,speed*dt);
        rb->force_add_y(-speed);
    }
    if(Input::key_pressed(KeyCode::Down)){
        //translate(0,-speed*dt);
        rb->force_add_y(speed);

    }
    if(Input::key_pressed(KeyCode::Left)){
        //translate(-speed*dt,0);
        rb->force_add_x(-speed);
    }
    if(Input::key_pressed(KeyCode::Right)){
        //translate(speed*dt,0);
        rb->force_add_x(speed);
    }
}



void EnemyTank::handle_shooting(){
    sf::Vector2f direction = Math::normalize(Math::points_to_vector(global_transform().transformPoint(sf::Vector2f(TANK_WIDTH/2,TANK_HEIGTH/2)),sf::Vector2f(Input::mouse_position().x,Input::mouse_position().y)));
    tower->set_rotation(Math::vector_angle(direction)+90);
    //Info(ARG(Math::vector_angle(direction)+90));
    if(Input::mouse_pressed(MouseButton::Left) && time >= missile.shoot_speed){
        object_introduce(new Missile(direction,missile),sf::Vector2f(TANK_WIDTH/2,TANK_HEIGTH/2)+sf::Vector2f(TANK_HEIGTH*cos(Math::rad(Math::vector_angle(direction))),TANK_HEIGTH*sin(Math::rad(Math::vector_angle(direction)))));
        time = 0;
    }
}