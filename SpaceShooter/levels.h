#include <SFML/Graphics.hpp>
#include <fstream>
#include "game.h"
class Levels{

public:

Font font;
Text Level1Text;
Text Level2Text;
Text Level3Text;
Sprite background; //Game background sprite
Texture bg_texture;
int scores = 0;
      

   


Levels(){

//constructors body
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2.25, 1.5);
font.loadFromFile("img/OpenSans-ExtraBold.ttf");

    // Initialize start text
    Level1Text.setFont(font);
    Level1Text.setString("1. LEVEL 1");
    Level1Text.setCharacterSize(32);
    Level1Text.setPosition(500 / 2 - Level1Text.getGlobalBounds().width / 2, 200);

    // Initialize highscore text
    Level2Text.setFont(font);
    Level2Text.setString("2. LEVEL 2");
    Level2Text.setCharacterSize(32);
    Level2Text.setPosition(500 / 2 - Level2Text.getGlobalBounds().width / 2, 250);

    // Initialize exit text
    Level3Text.setFont(font);
    Level3Text.setString("3. LEVEL 3");
    Level3Text.setCharacterSize(32);
    Level3Text.setPosition(500/ 2 - Level3Text.getGlobalBounds().width / 2, 300);

    // Set selected option to start by default
   

}


void display_level()

{

   Game G; 
 srand(time(0));
    RenderWindow window(VideoMode(500, 500), title);
    Clock clock;
    float timer=0;
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;   
 sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Num1)
            {
                window.close();
               G.start_game(1);
               scores = G.scores;
               Recordscores(scores);
            }
            else if (event.key.code == sf::Keyboard::Num2)
            {
               
                window.close();
                G.start_game(2);
                scores = G.scores;
                Recordscores(scores);
            }
            else if (event.key.code == sf::Keyboard::Num3)
            {
                window.close();
                G.start_game(3);
                scores = G.scores;
                Recordscores(scores);
              
            }
            break;

        case sf::Event::Closed:
            window.close();
            break;
        }
    }
    
  
window.clear();

    // Draw menu options
    
	
   window.draw(background);
    window.draw(Level1Text);
    window.draw(Level2Text);
    window.draw(Level3Text);

    window.display();


}
}

void Recordscores(int scores){
std::ofstream file("Scores", std::ios::app);

    if (!file) {
        std::cerr << "Error opening file: "<< std::endl;
        return;
    }

    file << scores << std::endl;
    file.close();
   

}
};
