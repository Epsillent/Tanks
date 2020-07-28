#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "engine.hpp"
#include "components/rigidbody_2d.hpp"
#include "components/sprite_2d.hpp"

class Obstacle: public GameObject{
private:
    Sprite2D* sprite;
    Rigidbody2D* rb;
public:
    Obstacle(const sf::Vector2f& size, const sf::Color& color);

};

#endif