#include<SFML/Graphics.hpp>
#include "cell.h"
#include "globals.h"
#pragma once
class Player{
    public:
        int dir;
        bool isMoving;
        sf::IntRect frame;
        sf::RectangleShape sprite;
        sf::RectangleShape heart;
        sf::Texture w0, w1, w2, w3;
        sf::Texture heartTexture;
        int hp=3;
        int size;
        int speed;
        int x;
        int y;
        int animationX;
        Player();
       bool checkCollision(cell cells[mazeH][mazeW], sf::FloatRect nextRect);
       void move(cell cells[mazeH][mazeW]);
       void animate();
       void changeDir(int d);
       void showHp(sf::RenderWindow&w);


};