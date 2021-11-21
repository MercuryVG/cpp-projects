#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>

class Hero
{
public:
     Hero();
    ~Hero();

     void move_hero(sf::Keyboard::Key key);
     void check_for_collission();
     void draw_hero(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;

};

#endif // HERO_H
