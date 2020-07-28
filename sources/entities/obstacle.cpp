#include "entities/obstacle.hpp"

Obstacle::Obstacle(const sf::Vector2f& size, const sf::Color& c)
{
    set_tag("Obstacle");
    sprite = component_add<Sprite2D>();
    sprite->set_color(c);
    sprite->set_size(size);
    Rigidbody2DProperties rbprops;
    rbprops.mass = 0;
    rb = component_add<Rigidbody2D>(rbprops);
    rb->collider_add(size);
}