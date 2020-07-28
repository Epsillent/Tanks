#include "entities/bar.hpp"


Bar::Bar(const BarProps& p):
    props(p)
{
    total = component_add<Sprite2D>();
    total->set_color(props.total);
    total->set_size(sf::Vector2f(100,4));
    total->set_position(props.position);
    current = component_add<Sprite2D>();
    current->set_color(props.current);
    current->set_size(sf::Vector2f(100.f*(*props.value/props.value_max),4));
    current->set_position(props.position);
    Info("Props value " + ARG(*props.value) + " Vmax " + ARG(props.value_max));
}

void Bar::on_update(float dt){
    if(*props.value<=props.value_max && props.value >= 0){
        current->set_size(sf::Vector2f(100*(*props.value/props.value_max),4));
    }else if(props.value < 0){
        current->set_size(sf::Vector2f(0,4));
    }
}

void Bar::reset(const BarProps& p){
    props=p;
    total->set_color(props.total);
    total->set_size(sf::Vector2f(100,4));
    total->set_position(props.position);
    current->set_color(props.current);
    current->set_size(sf::Vector2f(100.f*(*props.value/props.value_max),4));
    current->set_position(props.position);
}