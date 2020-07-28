#ifndef HEALTH_BAR
#define HEALTH_BAR

#include "engine.hpp"

struct BarProps{
    float *value;
    float value_max;
    sf::Color total;
    sf::Color current;
    sf::Vector2f position;
    BarProps(float *v):
        value(v), value_max(*v), total(sf::Color::Red),current(sf::Color::Green),position(0,-4)
    {}
};

class Bar: public GameObject{
private:
    BarProps props;
    Sprite2D *total, *current;
public:
    Bar(const BarProps&);
    void on_update(float dt)override;
    void reset(const BarProps&);
};

#endif