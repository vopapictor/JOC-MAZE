#include"player.h"
#include<iostream>
int min(int a,int b){
  if(a>b)return b;
  return a;  
}
Player::Player(){
    x=10;
    isMoving = false;
    y=10;
    size=32;
    speed=5;
    dir = 3;
    changeDir(0);
   // sf::IntRect r(sf::Vector2i(0, 0), sf::Vector2i(16, 16));
    w0.loadFromFile("sprites/playerwalking0.png");
    w1.loadFromFile("sprites/playerwalking1.png");
    w2.loadFromFile("sprites/playerwalking2.png");
    w3.loadFromFile("sprites/playerwalking3.png");
    sprite.setPosition(sf::Vector2f(x, y));
    
    sprite.setTexture(&w1);
    sprite.setSize(sf::Vector2f(size, size));
    hp=3;
    heart.setSize(sf::Vector2f(32, 32));
    if (heartTexture.loadFromFile("sprites/heart.png")) {
        heart.setTexture(&heartTexture, true);
    }
    
}
void Player::animate() {
    animationX += 16;
    animationX = (animationX) % 128;
    sprite.setTextureRect(sf::IntRect({ animationX,0 }, { 16,16 }));
}
void Player::changeDir(int d) {
        if (dir == 0) {

            sprite.setTexture(&w0);
        }
        if (dir == 2) {
            sprite.setTexture(&w2);
        }
        if (dir == 3) {
            sprite.setTexture(&w3);
        }
        if (dir == 1) {
            sprite.setTexture(&w1);
            return;
        }
    }
    
bool Player::checkCollision(cell cells[mazeH][mazeW], sf::FloatRect nextRect) {
   
    int startCol = std::max(0, static_cast<int>(nextRect.position.x / 50));
    int endCol = std::min(mazeW - 1, static_cast<int>((nextRect.position.x + nextRect.size.x) / 50));
    int startRow = std::max(0, static_cast<int>(nextRect.position.y / 50));
    int endRow = std::min(mazeH - 1, static_cast<int>((nextRect.position.y + nextRect.size.y) / 50));

    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            for (int w = 0; w < 4; w++) {
                if (cells[i][j].walls[w].visible) {
                    if (nextRect.findIntersection(cells[i][j].walls[w].edge.getGlobalBounds())) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Player::move(cell cells[mazeH][mazeW]) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        changeDir(3);
        animate();
        dir = 3;
        isMoving = true;
        movement.x -= speed;
    } 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        changeDir(1);

        animate();
        dir = 1;
        isMoving = true;
        movement.x += speed;
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        changeDir(0);
        animate();
        dir = 0;
        isMoving = true;
        movement.y -= speed;
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        changeDir(2);
        animate();
        dir = 2;
        isMoving = true;

        movement.y += speed;
    }

    sf::FloatRect nextXRect({ float(x) + movement.x, float(y) }, { static_cast<float>(size), static_cast<float>(size) });
    if (!checkCollision(cells, nextXRect)) {
        x += movement.x;
    }

    sf::FloatRect nextYRect({ float(x), y + movement.y }, { static_cast<float>(size), static_cast<float>(size) });
    if (!checkCollision(cells, nextYRect)) {
        y += movement.y;
    }
    if (!isMoving) {
        sprite.setTextureRect(sf::IntRect({ 0,0 }, { 16,16 }));
    }
    sprite.setPosition({ float(x), float(y) });
}

void Player::showHp(sf::RenderWindow&w) {
    for (int i = 0;i < hp;i++) {
        heart.setPosition(sf::Vector2f(i * 32, 0));
        w.draw(heart);
    }
}