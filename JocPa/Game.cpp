#include "Game.h"
Game::Game() {
	states.push("StartMenu");
	M.Dfs();
	M.placeQuizz(10);
}
void Game::checkLeaving() {
	if (P.dir == 1 && P.x / M.tileSize == mazeW - 1 && P.y / M.tileSize == mazeH - 1) {
		if (M.questionsLeft == 0)states.push("Win");
		else std::cout << "Nu poti pleaca inca";
	}
}
void Game::ExecuteState(sf::RenderWindow&window,Menu&m,Menu&m1,Menu&m2,Menu&m3,QuizzMenu&q1,Menu&hint) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && inputClock.getElapsedTime().asSeconds() > delay) {
		inputClock.restart();
		states.push("Pause");

	}
	if (states.top() == "StartMenu") {

		MenuState(m, window);
		return;
	}
	if (states.top() == "Win") {
		MenuState(m3,window);
		return;
	}
	if (states.top() == "Restart") {
		Restart();
		while (states.top() != "Play")states.pop();
		return;
	}
	if (states.top() == "Resume") {
		states.pop();
		states.pop();
		return;
	}
	if (states.top() == "Play") {
		window.setFramerateLimit(60);
		RunState(window,m1.f,hint);
		return;
	}
	if (states.top() == "Pause") {
		MenuState(m1,window);
		return;
	}
	if (states.top() == "Game Over") {
		MenuState(m2,window);
		return;
	}
	if (states.top() == "Exit")window.close();
	if (states.top() == "Quizz") {
		QuizzMenuState(q1, window);
		return;
	}
	if (states.top() == "Hint") {
		if (hint.updated == false) {
			hint.Update(M.hintArr[selectedHint]);
			M.hintArr[selectedHint].active = false;
			hint.updated = true;
		}
		MenuState(hint, window);
		return;

	}
}
void Game::changeToQuizz() {
	for (int i = 0;i < 10;i++) {
		if(M.quizzArr[i].active)
		if (M.quizzArr[i].x / M.tileSize == P.x / M.tileSize && M.quizzArr[i].y / M.tileSize == P.y / M.tileSize) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && inputClock.getElapsedTime().asSeconds()>delay) {
				selectedQuizz = i;
				states.push("Quizz");
				inputClock.restart();
				return;
			}
		}
	}
}
void Game::changeToHint(Menu&hint) {
	for (int i = 0;i < 10;i++) {
		if (M.hintArr[i].active)
			if (M.hintArr[i].x / M.tileSize == P.x / M.tileSize && M.hintArr[i].y / M.tileSize == P.y / M.tileSize) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && inputClock.getElapsedTime().asSeconds() > delay) {
					selectedHint = i;
					hint.updated = false;
					states.push("Hint");
					inputClock.restart();
					return;
				}
			}
	}
}
void Game::GameOverState() {

}

void Game::RunState(sf::RenderWindow&window,sf::Font&f,Menu&hint) {
	M.Draw(window);
	M.drawQuizz(window);
	P.move(M.cells);
	//P.sprite.setTextureRect(sf::IntRect({ 0,0 }, { 16,16 }));
	//P.animate();
	window.draw(P.sprite);
	changeToQuizz();
	changeToHint(hint);
	checkLeaving();
	//P.animate();
	

	P.showHp(window);
	M.drawQLeft(window, f);
}
void Game::QuizzMenuState(QuizzMenu&q,sf::RenderWindow&w) {
	drawMask(w);
	if (q.updated == false) {
		q.Update(M.quizzArr[selectedQuizz]);
	}
	q.changeColor();
	if (inputClock.getElapsedTime().asSeconds() > delay) {
		q.Move();
		q.Select(states,M.quizzArr[selectedQuizz],P.hp,M.questionsLeft);
		inputClock.restart();
		
	}
	q.checkTimeout(states, P.hp);
	q.Draw(w);
	q.DisplayTimeLeft(w);
	q.Timer();
	
	
		
}
void Game::drawMask(sf::RenderWindow&w) {
	M.Draw(w);
	sf::RectangleShape mask(sf::Vector2f(mazeW * M.tileSize, mazeH * M.tileSize));
	mask.setFillColor(sf::Color(0, 0, 0,130));
	mask.setPosition(sf::Vector2f(0, 0));
	w.draw(mask);
}
void Game::MenuState(Menu&m, sf::RenderWindow& w) {
	drawMask(w);
	m.changeColor();
	if (inputClock.getElapsedTime().asSeconds() > delay) {
		m.Move();
		m.Select(states);
		inputClock.restart();
		
	}
	m.Draw(w);
		
}
void Game::Restart() {
	P.hp = 3;
	P.x = 10;
	P.y = 10;
	P.dir = 1;
	P.changeDir(P.dir);
	P.animationX = 0;
	M.reset();
	M.Dfs();
	M.questionsLeft = 10;
	M.setQuizz();
	M.placeQuizz(10);
	
}
