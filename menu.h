#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;
using namespace std;
class Menu{
public:

Font font;
Text startText;
Text highscoreText;
Text instructText;
Text exitText;
Sprite background; //Game background sprite
Texture bg_texture;
int selectedOption = 0;
      

   


Menu(){

//constructors body
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2.25, 1.5);
font.loadFromFile("img/OpenSans-ExtraBold.ttf");

    // Initialize start text
    startText.setFont(font);
    startText.setString("1. Start");
    startText.setCharacterSize(32);
    startText.setPosition(500 / 2 - startText.getGlobalBounds().width / 2, 150);

    // Initialize highscore text
    highscoreText.setFont(font);
    highscoreText.setString("2. Highscore");
    highscoreText.setCharacterSize(32);
    highscoreText.setPosition(500 / 2 - highscoreText.getGlobalBounds().width / 2, 200);
    //

    instructText.setFont(font);
    instructText.setString("3. Instructions");
    instructText.setCharacterSize(32);
    instructText.setPosition(500 / 2 - instructText.getGlobalBounds().width / 2, 250);

    // Initialize exit text
    exitText.setFont(font);
    exitText.setString("4. Exit");
    exitText.setCharacterSize(32);
    exitText.setPosition(500/ 2 - exitText.getGlobalBounds().width / 2, 300);

    // Set selected option to start by default
    selectedOption = 0;

}


void display_menu()

{

    Levels L; 
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
                L.display_level();
            }
            else if (event.key.code == sf::Keyboard::Num2)
            {
               
             highscores();
                
            }
            else if (event.key.code == sf::Keyboard::Num3)
            {
               
                Instructions();
              
            }
             else if (event.key.code == sf::Keyboard::Num4)
            {
                window.close();
              
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
    window.draw(startText);
    window.draw(highscoreText);
    window.draw(instructText);
    window.draw(exitText);

    window.display();


}
}
 void Instructions(){
 RenderWindow window(VideoMode(500, 500),"Instructions");
   Texture o1;         //just for the sake of changing names
   o1.loadFromFile("img/background.jpg");
  
   
     
     Sprite sprite(o1);
     // text to display
     Font font;
     font.loadFromFile("img/OpenSans-ExtraBold.ttf");
     Text text("Use up,down,left,right", font, 30);
     text.setPosition(45,50);
     
     Text text1("to dodge your enemies", font, 30);
     text1.setPosition(45,150);
     
     Text text2("to close window press C",font,10);
     text2.setPosition(30,290);
                   
       while(window.isOpen()){
     Event eve;
      while(window.pollEvent(eve)){
      if(eve.type == Event::Closed)
      window.close();
       if (eve.type == Event::KeyPressed) {            
                if (eve.key.code == Keyboard::C)           
                    window.close();             
      }
      }
      
       window.clear();
      
      window.draw(sprite);
    
      
      window.draw(text);
  
       window.draw(text1);
          
      window.draw(text2); 
      
      window.display();
      
      }
 
 }
void highscores() {
    // Create an SFML window
    RenderWindow window(VideoMode(500, 500), "High Scores");
	Texture o1;         //just for the sake of changing names
   	o1.loadFromFile("img/background.jpg");
  
   
     
     Sprite sprite(o1);
    // Read from the file
    ifstream file("Scores");
    if (!file) {
        std::cerr << "Error opening file: Scores" << std::endl;
        return;
    }

    string fileContent;
    string line;
    while (getline(file, line)) {
        fileContent += line + "\n";
    }
    file.close();

    // Create an SFML text object to display the file contents
    Font font;
    if (!font.loadFromFile("img/OpenSans-ExtraBold.ttf")) {
        cerr << "Error loading font" << endl;
        return;
    }

    Text text;
    text.setFont(font);
    text.setString(fileContent);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(220, 50);

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
}
/*void highscores() {
    // Create an SFML window
    
    RenderWindow window(VideoMode(500, 500), "High Scores");
	Texture o1;         //just for the sake of changing names
   	o1.loadFromFile("img/background.jpg");
  
   
     
     Sprite sprite(o1);
    // Read from the file
    ifstream file("Scores");
    if (!file) {
        cerr << "Error opening file: Scores" << endl;
        return;
    }

    // Move the file pointer to the end of the file
    int pos;
    char ch;
    file.seekg(0, std::ios::end);
    pos = file.tellg();
    string fileContent;

    // Read the file contents in reverse order
   for(int i=0;i<pos;i++)
    {
        ch=file.get();
        cout<<ch;
        file.seekg(-2,ios::cur);
    }

    file.close();

    // Reverse the string to get the correct order
   // reverse(fileContent.begin(), fileContent.end());

    // Create an SFML text object to display the file contents
    Font font;
    if (!font.loadFromFile("img/OpenSans-ExtraBold.ttf")) {
        cerr << "Error loading font" << std::endl;
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(fileContent);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(220, 50);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
}*/
};
