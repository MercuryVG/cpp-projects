#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "hero.cpp"


using namespace sf;

int main(int argc, char *argv[])
{
    RenderWindow window(VideoMode(300, 300), "Game");

    Hero hero;

    while(window.isOpen())
    {
        Event window_event;
        while(window.pollEvent(window_event))
        {
            if(window_event.type == Event::Closed)
            {
                window.close();
            }
        }

        hero.draw_hero(window);
        window.display();

    }
    return 0;
}
