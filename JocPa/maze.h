#include <SFML/Graphics.hpp>
#include "cell.h"
#include<stack>
#include "globals.h"
#include "quizz.h"
#include<iostream>
#pragma once

class Maze{
    public:
        bool isGameFinished;
        Quizz quizzArr[10];
        common hintArr[10];
        sf::Texture tileTexture,questionTexture,hintTexture;
        sf::Sprite tileSprite;
        int tileSize=50;
        int questionsLeft;
        int quizzMatrix[mazeH][mazeW];
        cell cells[mazeH][mazeW];;
        std::stack<cell*>s;
        Maze();

        void Dfs();
        void reset();
        void Draw(sf::RenderWindow&w);
        void DrawPath(sf::RenderWindow&w);
        void showGrid(sf::RenderWindow&w);
        void pathToFinish();
        void setVecini(int i,int j);
        void placeQuizz(int nr);
        void drawQuizz(sf::RenderWindow&w);
        void setQuizz();
        void drawQLeft(sf::RenderWindow& w,sf::Font&f);
};