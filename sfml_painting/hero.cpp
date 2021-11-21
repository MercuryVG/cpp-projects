#include "hero.h"

Hero::Hero()
{
    if(!texture.loadFromFile("shroom.jpg"))
    {

    }
    texture.setSmooth(true);
    sprite.setTexture(texture);

}

void Hero::move_hero(sf::Keyboard::Key key)
{

}

void Hero::draw_hero(sf::RenderWindow& window)
{
    window.draw(sprite);
}
