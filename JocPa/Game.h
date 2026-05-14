#pragma once
#include "maze.h"
#include "player.h"
#include "menu.h"
class Game {
	public:
		sf::Clock inputClock;
		std::stack<std::string>states;
		int selectedQuizz;
		int selectedHint;
		Maze M;
		Player P;
		Game();
		void ExecuteState(sf::RenderWindow&window,Menu&m,Menu&m1,Menu&m2,Menu&m3,QuizzMenu&q1,Menu&hint);
		void MenuState(Menu& m, sf::RenderWindow& w);
		void RunState(sf::RenderWindow&window,sf::Font&f,Menu&hint);
		void GameOverState();
		void QuizzMenuState(QuizzMenu&q,sf::RenderWindow&w);
		void changeToQuizz();
		void changeToHint(Menu&hint);
		void Restart();
		void WinState();
		void drawMask(sf::RenderWindow&w);
		void checkLeaving();
};