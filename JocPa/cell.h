#pragma once
#include<SFML/Graphics.hpp>
struct wall{
    sf::RectangleShape edge;
    bool visible;
};
struct cell{
    bool isVisited;
    int i;
    int j;
    wall walls[4];
};