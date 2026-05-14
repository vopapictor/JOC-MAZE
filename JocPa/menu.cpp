#include "menu.h"
#include <iostream>
Menu::Menu(std::initializer_list<std::string>items):title(f) {
	va_list args;
	selectedOption = 0;
	int n = 0;
	f.openFromFile("PressStart2P-Regular.ttf");
	
	for (const auto&s : items ) {
		sf::Text t(f,s,20);
		//float width = t.getLocalBounds().size().width;
		t.setFillColor(sf::Color::White);
		t.setPosition(sf::Vector2f(100, n * 40 + 40));
		options.push_back(t);
		n += 1;
	}
	nrOfOptions = n;
		
}
void Menu::Draw(sf::RenderWindow& w) {
	w.draw(title);
	for (int i = 0;i < options.size();i++) {
		w.draw(options.at(i));
	}
}
void Menu::Move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		options[selectedOption].setFillColor(sf::Color::White);
		selectedOption = (selectedOption - 1 + nrOfOptions) % nrOfOptions;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		options[selectedOption].setFillColor(sf::Color::White);
		selectedOption = (selectedOption + 1) % nrOfOptions;
	}
}
void Menu::changeColor() {
	options[selectedOption].setFillColor(sf::Color::Red);
}
void Menu::Select(std::stack<std::string>&s) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
		s.push(options.at(selectedOption).getString().toAnsiString());
	}
}
void Menu::Update(common&c) {
	options.clear();
	sf::Text t(f, c.question, 20);
	t.setPosition(sf::Vector2f(100, 0));
	title = t;
	sf::Text o(f, "Resume", 20);
	o.setPosition(sf::Vector2f(100, 40));
	options.push_back(o);
	nrOfOptions = 1;
	selectedOption = 0;
}
void QuizzMenu::Select(std::stack<std::string>& s,Quizz&q,int&hp,int&qLeft) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
		if (selectedOption == correctOption) {
			std::cout << "Bravo";
			s.pop();
			q.active = false;
			updated = false;
			qLeft -= 1;
		}
		else {
			updated = false;
			hp -= 1;
			std::cout << hp;
			s.pop();
			if (hp == 0)s.push("Game Over");

			
		}
			
	}



}
void QuizzMenu::Update(Quizz& q) {
	options.clear();
	selectedOption = 0;
	timeLeft = 30;
	sf::Text t(f,q.question,20);
	t.setPosition(sf::Vector2f(100, 0));
	title = t;
	
	for (int i = 0;i < 4;i++) {
		t.setString(q.choices[i]);
		t.setPosition(sf::Vector2f(100, (i+1) * 50));
		options.push_back(t);
		
	}
	nrOfOptions = 4;
	correctOption = q.correctAnswer;
	updated = true;
	internalClock.restart();
}
void QuizzMenu::DisplayTimeLeft(sf::RenderWindow&w) {
	std::string s;
	s = "Time left: 00:" + std::to_string(timeLeft);
	sf::Text t(f, s, 20);
	t.setPosition(sf::Vector2f(100, 7*40));
	w.draw(t);

}
void QuizzMenu::Timer() {
	if (internalClock.getElapsedTime().asSeconds() > 1) {
		timeLeft -= 1;
		internalClock.restart();
	}
}
void QuizzMenu::checkTimeout(std::stack<std::string>& s,int &hp) {
	if (timeLeft == 0) {
		hp -= 1;
		updated = false;
		s.pop();
	}
}