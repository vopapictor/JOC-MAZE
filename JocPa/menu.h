#include<string>
#include<vector>
#include<initializer_list>
#include<SFML/Graphics.hpp>
#include<stack>
#include "quizz.h"
#include "globals.h"
#pragma once
class Menu {
	public:
		bool updated;
		sf::Font f;
		sf::Text title;
		std::vector<sf::Text>options;
		int selectedOption;
		int nrOfOptions;
		Menu(std::initializer_list<std::string>items);
		void changeColor();
		void Draw(sf::RenderWindow& w);
		void Update(common& c);
		void Move();
		void Select(std::stack<std::string>&s);

};
class QuizzMenu : public Menu {
	public:
		int timeLeft;
		sf::Clock internalClock;
		int correctOption;
		void Select(std::stack<std::string>& s,Quizz&q,int &hp,int&qLeft);
		void Update(Quizz &q);
		void Timer();
		void DisplayTimeLeft(sf::RenderWindow&w);
		void checkTimeout(std::stack<std::string>& s, int& hp);
};
