#include "scenes/battlefield.hpp"
#include "entities/local_tank.hpp"
#include "entities/enemy_tank.hpp"
#include "entities/obstacle.hpp"
void Battlefield::on_init(){
    object_introduce(new Obstacle(sf::Vector2f(DisplayServer::window_size().x,50),sf::Color(255,198,54)));
    object_introduce(new Obstacle(sf::Vector2f(DisplayServer::window_size().x,50),sf::Color(255,198,54)),sf::Vector2f(0,DisplayServer::window_size().y-50));
    
    object_introduce(new Obstacle(sf::Vector2f(50,DisplayServer::window_size().y),sf::Color(255,198,54)));
    object_introduce(new Obstacle(sf::Vector2f(50,DisplayServer::window_size().y),sf::Color(255,198,54)),sf::Vector2f(DisplayServer::window_size().x-50,0));

    object_introduce(new Obstacle(sf::Vector2f(100,100),sf::Color(255,198,54)),sf::Vector2f(400,400));
    object_introduce(new LocalTank,sf::Vector2f(200,200));
    object_introduce(new EnemyTank,sf::Vector2f(1000,200));

}

void Battlefield::on_update(float dt){

}
