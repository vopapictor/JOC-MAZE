#pragma once
#include<SFML/Graphics.hpp>
#include<string>
class common {
	public:
		int x, y;
		bool active;
		std::string question;
		sf::RectangleShape s;
};
class Quizz:public common {
	public:
		std::string choices[4];
		int correctAnswer;
		sf::RectangleShape s;
};
