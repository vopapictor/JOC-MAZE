#include <SFML/Graphics.hpp>
#include "player.h"
#include "quizz.h"
#include <vector>
#include "Game.h"
#include<iostream>
int main()
{
    
    srand(time(0));
    Game game;
    Menu start({ "Play", "Exit" });
    Menu pause({"Resume","Restart","Exit"});
    Menu gameOver({ "Restart","Exit" });
    Menu win({ "Restart","Exit" });
    Menu hint({});
    QuizzMenu quizz({});
    quizz.updated = false;
    sf::Text title1(gameOver.f,"Game over",20);
    title1.setPosition(sf::Vector2f({ 100,0 }));

    sf::Text title2(gameOver.f, "You won!", 20);
    title2.setPosition(sf::Vector2f({ 100,0 }));

    sf::Text title3(gameOver.f, "Pause", 20);
    title3.setPosition(sf::Vector2f({ 100,0 }));

    pause.title = title3;
    win.title = title2;
    gameOver.title = title1;
    
    sf::RenderWindow window(sf::VideoMode({mazeW*50,mazeH*50 }), "JOC MAZE");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        
       game.ExecuteState(window,start,pause,gameOver,win,quizz,hint);
        window.display();
    }
}