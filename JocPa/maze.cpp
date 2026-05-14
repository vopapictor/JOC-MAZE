#include "maze.h"
#include<cstdlib>
#include<ctime>

void Maze::setQuizz() {
    quizzArr[0].question = "What role does backend development play?";
    quizzArr[0].choices[0] = "To create the server-side logic of a web app";
    quizzArr[0].choices[1] = "To design the web app";
    quizzArr[0].choices[2] = "To create the content of the web app";
    quizzArr[0].choices[3] = "To create the user experience of the web app";
    quizzArr[0].active = true;
    quizzArr[0].correctAnswer = 0;

    hintArr[0].question = "A backend developer is\n someone who understands servers";
    hintArr[0].active = true;

    quizzArr[1].question = "What is a content management system?";
    quizzArr[1].choices[0] = "An web framework";
    quizzArr[1].choices[1] = "A tool deploy websites";
    quizzArr[1].choices[2] = "An app used to create, manage,\n and modify content for a website";
    quizzArr[1].choices[3] = "A programming language";
    quizzArr[1].active = true;
    quizzArr[1].correctAnswer = 2;

    hintArr[1].question = "App that creates";
    hintArr[1].active = true;

    quizzArr[2].question = "What is the database used for?";
    quizzArr[2].choices[0] = "Store data that is used for the website";
    quizzArr[2].choices[1] = "Create the website";
    quizzArr[2].choices[2] = "Store websites";
    quizzArr[2].choices[3] = "Create data for the website";
    quizzArr[2].active = true;
    quizzArr[2].correctAnswer = 0;

    hintArr[2].question = "Data is something that needs to be stored";
    hintArr[2].active = true;

    quizzArr[3].question = "Which of the following is NOT\n a core technology of web development?";
    quizzArr[3].choices[0] = "CSS";
    quizzArr[3].choices[1] = "HTML";
    quizzArr[3].choices[2] = "JavaScript";
    quizzArr[3].choices[3] = "Mobile development";
    quizzArr[3].active = true;
    quizzArr[3].correctAnswer = 3;

    hintArr[3].question = "HTML,CSS and Javascript are\n the backbone of the web";
    hintArr[3].active = true;

    quizzArr[4].question = "What is a web framework?";
    quizzArr[4].choices[0] = "A collection of tools and\n libraries used to create a website";
    quizzArr[4].choices[1] = "A tool to design websites";
    quizzArr[4].choices[2] = "A user interface";
    quizzArr[4].choices[3] = "A type of web server";
    quizzArr[4].active = true;
    quizzArr[4].correctAnswer = 0;

    hintArr[4].question = "Frameworks are tools";
    hintArr[4].active = true;

    quizzArr[5].question = "What defines a responsive design?";
    quizzArr[5].choices[0] = "A design that applies for all types of devices";
    quizzArr[5].choices[1] = "A design that works well\n with both dark theme and light theme";
    quizzArr[5].choices[2] = "All the rest";
    quizzArr[5].choices[3] = "A design that applies for\n different screen sizes";
    quizzArr[5].active = true;
    quizzArr[5].correctAnswer = 2;

    hintArr[5].question = "Responsive means adaptable to many kinds of conditions";
    hintArr[5].active = true;

    quizzArr[6].question = "What role does the frontend development play?";
    quizzArr[6].choices[0] = "To distribute web application in multiple languages";
    quizzArr[6].choices[1] = "To create the visual interface\n including the interactions for a website";
    quizzArr[6].choices[2] = "To manage the content of the website";
    quizzArr[6].choices[3] = "To create the user experience of a website";
    quizzArr[6].active = true;
    quizzArr[6].correctAnswer = 1;

    hintArr[6].question = "Front means visual";
    hintArr[6].active = true;

    quizzArr[7].question = "What is a content management system?";
    quizzArr[7].choices[0] = "None of the answers";
    quizzArr[7].choices[1] = "A framework created to build web apps";
    quizzArr[7].choices[2] = "A programming language to create websites";
    quizzArr[7].choices[3] = "A tool used to create content for a website";
    quizzArr[7].active = true;
    quizzArr[7].correctAnswer = 0;

    hintArr[7].question = "NONE ARE CORRECT";
    hintArr[7].active = true;

    quizzArr[8].question = "What is a domain name?";
    quizzArr[8].choices[0] = "An address used to find a website";
    quizzArr[8].choices[1] = "A name used to identify a web page";
    quizzArr[8].choices[2] = "A name used for a web server";
    quizzArr[8].choices[3] = "An unique name that identifies\n a website on the internet";
    quizzArr[8].active = true;
    quizzArr[8].correctAnswer = 3;

    hintArr[8].question = "Domains are unique";
    hintArr[8].active = true;



    quizzArr[9].question = "What is a web hosting service?";
    quizzArr[9].choices[0] = "A service that provides\n storage space for web pages";
    quizzArr[9].choices[1] = "All the rest";
    quizzArr[9].choices[2] = "A service that provides a\n domain name for a website";
    quizzArr[9].choices[3] = "A service that provides a\n web server for a website";
    quizzArr[9].active = true;
    quizzArr[9].correctAnswer = 1;

    hintArr[9].question = "Web hosting services provide many things";
    hintArr[9].active = true;
}
Maze::Maze():tileSprite(tileTexture){
    setQuizz();
    questionsLeft = 10;
    if (tileTexture.loadFromFile("sprites/tileTexture.png")) {
        tileSprite.setTexture(tileTexture, true);
        tileSprite.setScale(sf::Vector2f(tileSize/16,tileSize/16));
    }
    hintTexture.loadFromFile("sprites/hint.png");
    questionTexture.loadFromFile("sprites/question.png");
    for (int i = 0;i < 10;i++) {
        quizzArr[i].s.setSize(sf::Vector2f(30, 30));
        quizzArr[i].s.setTexture(&questionTexture, false);
        hintArr[i].s.setSize(sf::Vector2f(30, 30));
        hintArr[i].s.setTexture(&hintTexture, false);

    }
            for(int i=0;i<mazeH;i++)
                for(int j=0;j<mazeW;j++){
                    cells[i][j].isVisited=false;
                    cells[i][j].i=i;
                    cells[i][j].j=j;
                     for (int k=0;k<4;k++){
                        
                        cells[i][j].walls[k].visible=true;
                        cells[i][j].walls[k].edge.setFillColor(sf::Color::Black);
                        
                    }
                    cells[i][j].walls[0].edge.setSize(sf::Vector2f(tileSize,5));
                   // cells[i][j].walls[0].edge.setTexture(&wallTexture, false);
                    
                    cells[i][j].walls[2].edge.setSize(sf::Vector2f(tileSize, 5));
                   // cells[i][j].walls[2].edge.setTexture(&wallTexture, false);
                    cells[i][j].walls[1].edge.setSize(sf::Vector2f(5,tileSize));
                   // cells[i][j].walls[1].edge.setTexture(&wallTexture, false);
                    cells[i][j].walls[3].edge.setSize(sf::Vector2f(5, tileSize));
                   // cells[i][j].walls[3].edge.setTexture(&wallTexture, false);
                    cells[i][j].walls[0].edge.setPosition(sf::Vector2f(j*tileSize,i*tileSize));
                    cells[i][j].walls[1].edge.setPosition(sf::Vector2f((j+1)*tileSize-5,i*tileSize));
                    cells[i][j].walls[2].edge.setPosition(sf::Vector2f(j*tileSize,(i+1)*tileSize-5));
                    cells[i][j].walls[3].edge.setPosition(sf::Vector2f(j*tileSize,i*tileSize));
                
                        
                }
        }
void Maze::reset(){
    for(int i=0;i<mazeH;i++)
        for(int j=0;j<mazeW;j++)
            cells[i][j].isVisited=false;
}
void Maze::Draw(sf::RenderWindow&w){
    sf::RectangleShape rect(sf::Vector2f(tileSize,tileSize));
            sf::RectangleShape border(sf::Vector2f(tileSize,3));
            border.setFillColor(sf::Color(0,0,0));
            border.setOrigin({0,0});
            rect.setFillColor(sf::Color(14,80,200));
            for(int i=0;i<mazeH;i++){
                for(int j=0;j<mazeW;j++){
                    //rect.setPosition(sf::Vector2f(j*tileSize,i*tileSize));
                    tileSprite.setPosition(sf::Vector2f(j * tileSize, i * tileSize));
                    w.draw(tileSprite);
                    for(int k=0;k<4;k++)
                        if (cells[i][j].walls[k].visible) {
                            w.draw(cells[i][j].walls[k].edge);
                        }
                           
                        
                }
            }
}
void Maze::DrawPath(sf::RenderWindow&w){
    std::stack<cell*>s2=s;
    while(!s2.empty()){
        sf::RectangleShape rect(sf::Vector2f(tileSize,tileSize));
        rect.setFillColor(sf::Color(150,20,102));
        rect.setPosition(sf::Vector2f(s2.top()->j*tileSize,s2.top()->i*tileSize));
        w.draw(rect);
        for(int k=0;k<4;k++)
                        if(s2.top()->walls[k].visible)
                            w.draw(s2.top()->walls[k].edge);
        s2.pop();
    }
}
void Maze::showGrid(sf::RenderWindow&w){
    sf::RectangleShape r;
    r.setSize({50,50});
    r.setOutlineColor(sf::Color::Red);
    r.setOutlineThickness(1);
    r.setFillColor(sf::Color::Transparent);
    for(int i=0;i<mazeH;i++){
        for(int j=0;j<mazeW;j++){
                 r.setPosition(sf::Vector2f(j*50,i*50));
            w.draw(r);
        }
           
    }

}
void Maze::pathToFinish(){
    cell*curCell=&cells[0][0];
    s.push(curCell);
    while(curCell!=&cells[mazeH-1][mazeW-1]){
        curCell->isVisited=true;
        cell*vecini[4];
        int index=-1;
        //vecin sus
        if(curCell->i!=0 && cells[curCell->i-1][curCell->j].isVisited==false&&cells[curCell->i-1][curCell->j].walls[2].visible==false){
            index+=1;
            vecini[index]=&cells[curCell->i-1][curCell->j];
        }
        //vecin jos
        if(curCell->i!=mazeH-1 && cells[curCell->i+1][curCell->j].isVisited==false&&cells[curCell->i+1][curCell->j].walls[0].visible==false){
            index+=1;
            vecini[index]=&cells[curCell->i+1][curCell->j];
        }
            
        
        //vecin dreaota
        if(curCell->j!=mazeW-1 && cells[curCell->i][curCell->j+1].isVisited==false&&cells[curCell->i][curCell->j+1].walls[3].visible==false){
            index+=1;
            vecini[index]=&cells[curCell->i][curCell->j+1];
        }
            
        
        //vecin stanga
        if(curCell->j!=0 && cells[curCell->i][curCell->j-1].isVisited==false&&cells[curCell->i][curCell->j-1].walls[1].visible==false){
            index+=1;
            vecini[index]=&cells[curCell->i][curCell->j-1];
        }
        if(index==-1){
            s.pop();
            if(!s.empty()){
                 curCell=s.top();
            }
           
        }else{
            int next=rand()%(index+1);
            curCell=vecini[next];
            s.push(curCell);
        }
    }

}
void Maze::Dfs(){
    std::stack<cell*>s;
    cell *curCell=&cells[0][0];
    //push(curCell);
    s.push(curCell);
    while(!s.empty()){
        curCell->isVisited=true;
        cell *vecini[4];
        int index=-1;
        //vecin sus
        if(curCell->i!=0 && cells[curCell->i-1][curCell->j].isVisited==false){
            index+=1;
            vecini[index]=&cells[curCell->i-1][curCell->j];
        }
        //vecin jos
        if(curCell->i!=mazeH-1 && cells[curCell->i+1][curCell->j].isVisited==false){
            index+=1;
            vecini[index]=&cells[curCell->i+1][curCell->j];
        }
            
        
        //vecin dreaota
        if(curCell->j!=mazeW-1 && cells[curCell->i][curCell->j+1].isVisited==false){
            index+=1;
            vecini[index]=&cells[curCell->i][curCell->j+1];
        }
            
        
        //vecin stanga
        if(curCell->j!=0 && cells[curCell->i][curCell->j-1].isVisited==false){
            index+=1;
            vecini[index]=&cells[curCell->i][curCell->j-1];
        }
            
        if(index==-1){
            s.pop();
            if(!s.empty()){
                 curCell=s.top();
            }
           
        }else{
            
            int i=rand()%(index+1);
            if(curCell->i>vecini[i]->i){
                curCell->walls[0].visible=false;
                vecini[i]->walls[2].visible=false;
            }
            if(curCell->i<vecini[i]->i){
                curCell->walls[2].visible=false;
                vecini[i]->walls[0].visible=false;
            }
            if(curCell->j<vecini[i]->j){
                curCell->walls[1].visible=false;
                vecini[i]->walls[3].visible=false;
            }
            if(curCell->j>vecini[i]->j){
                curCell->walls[3].visible=false;
                vecini[i]->walls[1].visible=false;
            }
            curCell=vecini[i];
            s.push(curCell);

        }
        
            
    }
}
void Maze::placeQuizz(int nr) {
    int index = 0;
    for (int i = 0;i < mazeH;i++) {
        for (int j = 0;j < mazeW;j++) {
            if ((i == 0 && j == 0) || (i == mazeH - 1 && j == mazeW - 1))
                quizzMatrix[i][j] = 2;
            else quizzMatrix[i][j] = 0;
        }
    }
    while (index < nr) {
       
        int I, J;
        I = rand() % mazeH;
        J = rand() % mazeW;
        while (quizzMatrix[I][J] !=0) {
            I = rand() % mazeH;
            J = rand() % mazeW;
        }
        quizzMatrix[I][J] = 1;
        quizzArr[index].y = I * tileSize;
        quizzArr[index].x = J * tileSize;
        //quizzArr[index].s.setTexture(&questionTexture,true);
        quizzArr[index].s.setSize(sf::Vector2f(tileSize, tileSize));
        quizzArr[index].s.setPosition(sf::Vector2f(quizzArr[index].x, quizzArr[index].y));
        quizzArr[index].active = true;

        I = rand() % mazeH;
        J = rand() % mazeW;
        while (quizzMatrix[I][J] != 0) {
            I = rand() % mazeH;
            J = rand() % mazeW;
        }
        quizzMatrix[I][J] = 3;
        hintArr[index].x = J * tileSize;
        hintArr[index].y = I * tileSize;
        hintArr[index].active = true;
        hintArr[index].s.setSize(sf::Vector2f(tileSize, tileSize));
        hintArr[index].s.setPosition(sf::Vector2f(hintArr[index].x, hintArr[index].y));
        index += 1;
    }
   
}
void Maze::drawQuizz(sf::RenderWindow&w) {
    for (int i = 0;i < 10;i++) {
        if(quizzArr[i].active)
        w.draw(quizzArr[i].s);
        if (hintArr[i].active)
            w.draw(hintArr[i].s);
    }
}
void Maze::drawQLeft(sf::RenderWindow&w,sf::Font&f) {
    std::string s;
    s = "Questions left: " + std::to_string(questionsLeft) + "/10";
    sf::Text t(f, s,20 );
    t.setPosition(sf::Vector2f(mazeW * tileSize - 430, 0));
    w.draw(t);
}