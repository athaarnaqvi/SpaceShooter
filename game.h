
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <math.h>
#include "player.h"
#include "enemy.h"
using namespace sf;
const char title[] = "OOP-Project, Spring-2023";


class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Music music;

Player* p; //player 

Invaders * invadersarray;//invaders
Monster * M;
Dragon * D;

// add other game attributes
int temp =0;
bool shoot = false;
bool isshoot = 0;
bool ispressed = 0;
bool bombloop = 0;
bool spriteshow = true;
int monstertime = 0;
int dragontime = 0;
int chooseinvader = 0;
int level;
int countloop = 0;
int count =0;
bool nextshape=0;
bool nextshape1=0;
bool nextshape2=0;
bool nextshape3=0;
bool nextshape4=0;
bool ispaused;
int lives = 5;
int scores = 0;


Game()
{
p=new Player("img/player_ship.png");
M = new Monster("img/monster1.png");
D = new Dragon("img/dragon.png");
invadersarray = new Invaders[12];
bg_texture.loadFromFile("img/background.jpg");
music.openFromFile("img/stranger-things-124008.ogg");

 ispaused = false;
background.setTexture(bg_texture);
background.setScale(2.25, 1.5);

}
void start_game(int l)
{   
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    
    float timer=0;
    level = l;
   music.play();
   
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time; 
 if(countloop % 2000 == 0){
   shoot = true;
   bombloop = false;
   } else{
   shoot = false;
   bombloop = true;
   }
  
      
	
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game 
            if (e.type == Event::KeyPressed && e.key.code == sf::Keyboard::P){
               ispaused = !ispaused;
               }
          }
                          	    
        
        if(!ispaused){
       
        if (Keyboard::isKeyPressed(::Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
	{
	    ispressed = 1;
	    p->tex.loadFromFile("img/player_ship2.png");
	  //  p->b->sprite1.setPosition(p->sprite.getPosition().x , p->sprite.getPosition().y)
	}  
	if (Keyboard::isKeyPressed(::Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
	{
	    ispressed = 1;
	    p->tex.loadFromFile("img/player_ship1.png");
	}   
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
	
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
        
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
	
	    isshoot = 1;  
}
    


 
if (level == 1) {
    if (temp == 0) {
        invadersarray->DrawCross(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 10;
        }
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        if (count == 12) {
       
            count = 0;
            temp = 1;
            scores += 10;
          
           // delete[] invadersarray;
           // invadersarray = nullptr;
        }
    }
    else if (temp == 1) {
        invadersarray = new Invaders[15];
        nextshape = 1;
        temp = -1;
    }
    else if (nextshape == 1 &&  temp == -1) {
        invadersarray->DrawRectangle(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 14;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 15) {
            count = 0;
            temp = 2;
            scores+=20;
          //  delete[] invadersarray;
           // invadersarray = nullptr;
          
        }
        
    }
   //  cout<<"temp" <<temp <<endl;
    
     if (temp == 2) {
    
        invadersarray = new Invaders[16];
        nextshape1 = 1;
        temp = -2;
    }
    else if (nextshape1 == 1 && temp == -2) {
        invadersarray->DrawTriangle(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 15;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 16) {
            count = 0;
            temp = 3;
            scores += 30;
            nextshape1 = 0;
          
            //delete[] invadersarray;
            //invadersarray = nullptr;
        }
    }
}

if (level == 2) {
    if (temp == 0) {
        invadersarray->DrawDiamond(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 10;
        }
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        if (count == 12) {
       
            count = 0;
            temp = 1;
            scores += 20;
          
           // delete[] invadersarray;
           // invadersarray = nullptr;
        }
    }
    else if (temp == 1) {
        invadersarray = new Invaders[12];
        nextshape = 1;
        temp = -1;
    }
    else if (nextshape == 1 &&  temp == -1) {
        invadersarray->DrawCircle(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 11;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 12) {
            count = 0;
            temp = 2;
             scores += 20;
          //  delete[] invadersarray;
           // invadersarray = nullptr;
          
        }
        
    }
   //  cout<<"temp" <<temp <<endl;
    
     if (temp == 2) {
    
        invadersarray = new Invaders[12];
        nextshape1 = 1;
        temp = -2;
    }
    else if (nextshape1 == 1 && temp == -2) {
        invadersarray->DrawHeart(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 11;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 12) {
            count = 0;
            temp = 3;
             scores += 20;
            nextshape1 = 0;
          
            //delete[] invadersarray;
            //invadersarray = nullptr;
        }
    }
}
	
	
	/****************************************************************************/
	if (level == 3) {
    if (temp == 0) {
        invadersarray->DrawCross(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 10;
        }
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        if (count == 12) {
       
            count = 0;
            temp = 1;
            scores += 10;
          
           // delete[] invadersarray;
           // invadersarray = nullptr;
        }
    }
    else if (temp == 1) {
        invadersarray = new Invaders[15];
        nextshape = 1;
        temp = -1;
    }
    else if (nextshape == 1 &&  temp == -1) {
        invadersarray->DrawRectangle(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 14;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 15) {
            count = 0;
            temp = 2;
            scores+=20;
          //  delete[] invadersarray;
           // invadersarray = nullptr;
          
        }
        
    }
   //  cout<<"temp" <<temp <<endl;
    
     if (temp == 2) {
    
        invadersarray = new Invaders[16];
        nextshape1 = 1;
        temp = -2;
    }
    else if (nextshape1 == 1 && temp == -2) {
        invadersarray->DrawTriangle(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 15;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 16) {
            count = 0;
            temp = 6;
            scores += 30;
            nextshape1 = 0;
          
            //delete[] invadersarray;
            //invadersarray = nullptr;
        }
    }
    if (temp == 6) {
    
        invadersarray = new Invaders[11];
        nextshape2 = 1;
        temp = -3;
    }
    else if (nextshape2 == 1 && temp == -3) {
        invadersarray->DrawDiamond(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 10;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 11) {
            count = 0;
            temp = 7;
            scores += 40;
            
          
            //delete[] invadersarray;
            //invadersarray = nullptr;
        }
    }
    
    if (temp == 7) {
    
        invadersarray = new Invaders[12];
        nextshape3 = 1;
        temp = -4;
    }
    else if (nextshape3 == 1 && temp == -4) {
        invadersarray->DrawCircle(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 11;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 12) {
            count = 0;
            temp = 8;
            scores += 50;
            
          
            //delete[] invadersarray;
            //invadersarray = nullptr;
        }
    }
    
    if (temp == 8) {
    
        invadersarray = new Invaders[12];
        nextshape4 = 1;
        temp = -5;
    }
    else if (nextshape4 == 1 && temp == -5) {
        invadersarray->DrawHeart(invadersarray);
        if(shoot == 1){chooseinvader = rand()% 11;}
        if(bombloop == 1){
        DroppingBomb(chooseinvader);
        }
        
        if (count == 12) {
            count = 0;
            temp = 3;
            scores += 60;
            nextshape4 = 0;
          
            //delete[] invadersarray;
            //invadersarray = nullptr;
        }
    }
}
	/****************************************************************************/
       
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	//////////////////////////////////////////////
	 if(isshoot == 1){
	
	 p->shootbullet();
	
	 }
	   checkCollision();
	   checkCollisionplayer(window);
	   
	 
	 if(ispressed == 0){
	 p->tex.loadFromFile("img/player_ship.png");
	 }
	
	

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	//window.draw(B->sprite1);
	
	for(int i = 0; i < invadersarray->size ; i++){
	if(invadersarray[i].isavail != false && invadersarray[i].ishit == false){
	
	window.draw(invadersarray[i].sprite);} }  // setting player on screen
	
	 
	 
         ispressed = 0;
         
  if(temp == 3){
  
  if( monstertime <= 5000){
  
       M->move();
  	M->shootbomb();
  	checkCollisionMonster(window);
	window.draw(M->sprite);
	window.draw(M->B->sprite1);
	monstertime ++;
 }
 else{temp = 4;
 scores += 100;
 }}
 

 if(temp == 4){
  
 if(dragontime <=10000){
 
 D->shootbomb();
 checkCollisionDragon(window);
 window.draw(D->sprite);
 window.draw(D->B1->sprite1);
 window.draw(D->B2->sprite1);
 window.draw(D->B3->sprite1);
 dragontime ++;
 }
 else{temp = 5;
 scores += 500;
 } 
 }
 
 if(temp ==5){
 window.close();
 levelcomplete();
 
 }
 
       window.draw(p->b->sprite1);//setting bullet on screen
       
       
      
	window.draw(invadersarray[chooseinvader].B->sprite1);
	   
	
       
       
       
       
//invadersarray[chooseinvader].canDropBomb = 0;

     countloop++;
	window.display();  //Displying all the sprites
    }


  }
}

void checkCollision() {
    for (int i = 0; i < invadersarray->size; i++) {
        if (invadersarray[i].ishit!= true && p->b->getGlobalBounds().intersects(invadersarray[i].getGlobalBounds())) {
            count += 1;
            invadersarray[i].x = -1000;
             invadersarray[i].y = -1000;
             invadersarray[i].sprite.setPosition(invadersarray[i].x,invadersarray[i].y); 
             //invadersarray[i].B->sprite1.setPosition(invadersarray[i].x,invadersarray[i].y);
             p->b->sprite1.setPosition(p->sprite.getPosition().x+40, p->sprite.getPosition().y-1);
            
            invadersarray[i].ishit = true;
           
            
          break;
        }
    }
}
void checkCollisionplayer(RenderWindow& window) {
     for (int i = 0; i < invadersarray->size; i++) {
        if ( p->iscollided != false && (p->getGlobalBounds().intersects(invadersarray[chooseinvader].B->getGlobalBounds()) || p->getGlobalBounds().intersects(invadersarray[i].getGlobalBounds()))) {
        cout<<"here are your lives: " << lives <<endl;
           if(lives == 0){
          
           window.close();
     /////////////////////////GAMEOVER WINDOW//////////////////////////////////
     
      
          GameOver();
           
           }
           else{
           
          
           Texture texdes;
           Sprite spritedes;
           float xdes = 0.0f;
           float ydes = 0.0f;
           
           texdes.loadFromFile("img/playerShip1_damage3.png");
	   spritedes.setTexture(texdes);
	    xdes = p->sprite.getPosition().x;
	    ydes = p->sprite.getPosition().y;
		spritedes.setPosition(sf::Vector2f(xdes,ydes));
		spritedes.setScale(0.75,0.75);
           window.draw(spritedes);
          
           lives-=1;
           window.display();
            p->x = -1000;
           p->y = -1000;
           p->sprite.setPosition(p->x,p->y);
           
           }
            
        }
        p->iscollided = true;
    }

}
void checkCollisionMonster(RenderWindow& window) {
     
        if ( p->iscollided != false && (p->getGlobalBounds().intersects(M->B->getGlobalBounds()))) {
        cout<<"here are your lives : " << lives <<endl;
           if(lives == 0){
          
           window.close();
           GameOver();
           
           }
           else{
            p->x = -1000;
           p->y = -1000;
           p->sprite.setPosition(p->x,p->y);
          
           Texture texdes;
           Sprite spritedes;
           float xdes = 0.0f;
           float ydes = 0.0f;
           
           texdes.loadFromFile("img/playerShip1_damage3.png");
	   spritedes.setTexture(texdes);
	    xdes = p->sprite.getPosition().x;
	    ydes = p->sprite.getPosition().y;
		spritedes.setPosition(sf::Vector2f(xdes,ydes));
		spritedes.setScale(0.75,0.75);
           window.draw(spritedes);
          
           lives-=1;
           window.display();
           
           }
            
        }
        p->iscollided = true;
    

}

void checkCollisionDragon(RenderWindow& window) {
     
        if ( p->iscollided != false && (p->getGlobalBounds().intersects(D->B1->getGlobalBounds()) || p->getGlobalBounds().intersects(D->B2->getGlobalBounds()) || p->getGlobalBounds().intersects(D->B3->getGlobalBounds()) )) {
        cout<<"here are your lives : " << lives <<endl;
           if(lives == 0){
          
           window.close();
           GameOver();
           
           }
           else{
            p->x = -1000;
           p->y = -1000;
           p->sprite.setPosition(p->x,p->y);
          
           Texture texdes;
           Sprite spritedes;
           float xdes = 0.0f;
           float ydes = 0.0f;
           
           texdes.loadFromFile("img/playerShip1_damage3.png");
	   spritedes.setTexture(texdes);
	    xdes = p->sprite.getPosition().x;
	    ydes = p->sprite.getPosition().y;
		spritedes.setPosition(sf::Vector2f(xdes,ydes));
		spritedes.setScale(0.75,0.75);
           window.draw(spritedes);
          
           lives-=1;
           window.display();
           
           }
            
        }
        p->iscollided = true;
    

}
 void DroppingBomb(int x){
 
	   invadersarray[x].DropBomb(); 
	   
 }
 void GameOver(){
 RenderWindow window(VideoMode(500, 500),"Game Over");
   Texture o1;         //just for the sake of changing names
   o1.loadFromFile("img/background.jpg");
  
   
     
     Sprite sprite(o1);
     // text to display
     Font font;
     font.loadFromFile("img/OpenSans-ExtraBold.ttf");
     Text text("GAME", font, 40);
     text.setPosition(45,50);
     
     Text text1("OVER", font, 40);
     text1.setPosition(45,90);
     
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
void levelcomplete(){
 RenderWindow window(VideoMode(500, 500),"Level Complete");
   Texture o1;         //just for the sake of changing names
   o1.loadFromFile("img/background.jpg");
  
   
     
     Sprite sprite(o1);
     // text to display
     Font font;
     font.loadFromFile("img/OpenSans-ExtraBold.ttf");
     Text text("LEVEL", font, 40);
     text.setPosition(45,50);
     
     Text text1("COMPLETE", font, 40);
     text1.setPosition(45,90);
     
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
};

