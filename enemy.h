#include <SFML/Graphics.hpp>
#include<string.h>
#include"player.h"
#include <iostream>
using namespace sf;
using namespace std;
class Bomb{
public:
Texture tex2;
Sprite sprite1;
float speed2;
int x1,y1;
bool isactive=true;

Bomb(string png_path)
{


tex2.loadFromFile(png_path);
sprite1.setTexture(tex2);
x1=0;y1=0;
speed2 = 0.3f;
sprite1.setPosition(sf::Vector2f(x1,y1));
sprite1.setScale(1,1);
}
FloatRect getGlobalBounds() const {
        return sprite1.getGlobalBounds();
    }

void movebomb(){
float delta_x1 = 0; float delta_y1 = 0;


   
    Vector2f newPos = sprite1.getPosition()+ Vector2f(delta_x1, delta_y1) ;

    // Wrap around the window
    if (newPos.y < 0 ){
        newPos.y = -1000;
        isactive = false;
        }
    else if (newPos.y > 780){
        newPos.y = -1000;
        isactive =  false;
        }
    

    sprite1.setPosition(newPos);
    
    
if(isactive){
delta_y1 += 1;
}


delta_y1 *= speed2;

sprite1.move(sf::Vector2f(delta_x1, delta_y1));
  
}



};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Enemy{

public:
Bomb * B;
Texture tex;
Sprite sprite;
float speed=0.3;
float x,y;
Enemy(std::string png_path)
{

  

tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=40;y=20;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.5,0.5);

}
virtual void DropBomb(){};

};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Invaders: public Enemy{
public:

bool isavail = true;
bool ishit = false;
float posx =0.0f;
 float posy =0.0f;
int size = 0;
Invaders() : Enemy("img/enemy_1.png") {
B = new Bomb("img/enemy_laser.png");
 B->sprite1.setPosition(-1,-1);
}
Invaders(string png_path):Enemy(png_path){
B = new Bomb("img/enemy_laser.png");
 B->sprite1.setPosition(-1,-1);
}
 void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }
     FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }

    void destroy() {
       x = -1000;
        y = -1000;
        sprite.setPosition(-1000, -1000);
    }
    //*********************************************************//
 /*  void DropBomb() {

  
   B->sprite1.setPosition(posx,posy);
// cout<<B->sprite1.getPosition().x << " here 1" << B->sprite1.getPosition().y <<endl;
   B->movebomb();
//  cout<<B->sprite1.getPosition().x << " " << B->sprite1.getPosition().y <<endl;
  posx = B->sprite1.getPosition().x;
  posy = B->sprite1.getPosition().y;
   }
  */
  void DropBomb() {
  if (B->isactive) {
        posx = B->sprite1.getPosition().x; // Update invader's position from the bomb's position
        posy = B->sprite1.getPosition().y;
    }
     B->movebomb();
    if (!B->isactive) {
     posx = this->sprite.getPosition().x;
     posy = this->sprite.getPosition().y;
        B->sprite1.setPosition(posx, posy); // Set the bomb position to the invader's position
        B->isactive = true; // Set the bomb as active
    }

   

    
}


    //*********************************************************//
Invaders * DrawRectangle(Invaders * I){
size = 15;
int index = 0;

   x = 50;
   y = 0;
 

for(int i = 0 ; i< 5; i++){

  x += 100;
  y = 100;
  I[index].setPosition(x,y);
  index++;
}
x= 50;
y += 100;
for(int i = 0 ; i< 5 ;i++ ){

 x += 100;
  
  I[index].setPosition(x,y);
  index++;
}
x = 50;
y += 100;

for(int i = 0 ; i< 5; i++){
 x+=100;
 
  I[index].setPosition(x,y);
  index++;
}
return I;
}
Invaders * DrawTriangle(Invaders * I){
size = 16;
int index = 0;

   x = 0;
   y = 0;
 

x = 350;
  y = 75;
  I[index].setPosition(x,y);
  index++;
  x = 150;
  y+=100;
  
for(int i = 0 ; i< 3; i++){

  x += 100;
 
  I[index].setPosition(x,y);
  index++;
}
x= 50;
y += 100;
for(int i = 0 ; i< 5 ;i++ ){

 x += 100;
  
  I[index].setPosition(x,y);
  index++;
}
x = -50;
y += 100;

for(int i = 0 ; i< 7; i++){
 x+=100;
 
  I[index].setPosition(x,y);
  index++;
}
return I;
}

Invaders * DrawCross(Invaders * I){
size = 12;
int index = 0;

   x = 0;
   y = 0;
   
for(int i = 0 ; i< 6; i++){

  x += 100;
 y += 100;
  I[index].setPosition(x,y);
  index++;
}
x= 600;
y = 0;
for(int i = 0 ; i< 6 ;i++ ){
if(i == 4){continue;}
 x -= 100;
 y += 100;
  
  I[index].setPosition(x,y);
  index++;
}

return I;
}
Invaders* DrawDiamond(Invaders* I) {
     size = 12;
    int index = 0;

    // Diamond shape
   
    I[index].setPosition(290, 130);
    index++;
    I[index].setPosition(390, 130);
    index++;
    I[index].setPosition(490, 130);
    index++;
    I[index].setPosition(190, 270);
    index++;
    I[index].setPosition(290, 270);
    index++;
    I[index].setPosition(390, 270);
    index++;
    I[index].setPosition(490, 270);
    index++;
    I[index].setPosition(590, 270);
    index++;
    I[index].setPosition(290, 410);
    index++;
    I[index].setPosition(390, 410);
    index++;
    I[index].setPosition(490, 410);
    index++;
    I[index].setPosition(390, 550);
    index++;
    return I;
}

Invaders* DrawCircle(Invaders* I) {
    size = 12;
    int index = 0;

    // Circle shape
    I[index].setPosition(400, 0);
    index++;
    I[index].setPosition(300, 0);
    index++;
    I[index].setPosition(200, 120);
    index++;
    I[index].setPosition(500, 120);
    index++;
    I[index].setPosition(100, 240);
    index++;
    I[index].setPosition(600, 240);
    index++;
    I[index].setPosition(100, 360);
    index++;
    I[index].setPosition(600, 360);
    index++;
    I[index].setPosition(200, 480);
    index++;
    I[index].setPosition(500, 480);
    index++;
    I[index].setPosition(300, 600);
    index++;
    I[index].setPosition(400, 600);
    index++;
    return I;
}

Invaders* DrawHeart(Invaders* I) {
    size = 12;
    int index = 0;

    // Heart shape
    I[index].setPosition(390, 210);
    index++;
    I[index].setPosition(300, 110);
    index++;
    I[index].setPosition(210, 110);
    index++;
    I[index].setPosition(120, 210);
    index++;
    I[index].setPosition(480, 110);
    index++;
    I[index].setPosition(570, 110);
    index++;
     I[index].setPosition(650, 210);
    index++;
    I[index].setPosition(210, 310);
    index++;
    I[index].setPosition(570, 310);
    index++;
    I[index].setPosition(300, 410);
    index++;
    I[index].setPosition(480, 410);
    index++;
    I[index].setPosition(390, 510);
    index++;
  

    return I;
}

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Monster: public Enemy{
public:
bool movement = 0;
float posx = 0.0f;
float posy = 0.0f;
float speed = 0.5f;
Monster() : Enemy("img/monster1.png") {
 B=new Bomb("img/fire00.png");
 B->sprite1.setScale(2,2);
x = 0; y = 0;
}
Monster(string png_path):Enemy(png_path){
B=new Bomb("img/fire00.png");
B->sprite1.setScale(2,2);
x = 0 ; y = 0;
}
FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }
void move(){
float x1 = 0; float y1 = 0;


    
    Vector2f newPos = sprite.getPosition() + Vector2f(x1, y1);

    // Wrap around the window
    if (newPos.x < 0){
        newPos.x = 0;
        movement = false;
        }
    else if (newPos.x > 780){
        newPos.x = 780;
        movement = true;
        }
    

    sprite.setPosition(newPos);
if(movement){
x1 -= 1;
}
else{
x1 += 1;
}

x1 *= speed;

sprite.move(sf::Vector2f(x1, y1));
 
}
    
 void shootbomb(){  // New function to handle bullet shooting
 
 B->speed2 = 2;
 if (B->isactive) {
        posx = B->sprite1.getPosition().x; // Update invader's position from the bomb's position
        posy = B->sprite1.getPosition().y;
    }
     B->movebomb();
 if (!B->isactive) {
     posx = this->sprite.getPosition().x + 150;
     posy = this->sprite.getPosition().y + 100;
        B->sprite1.setPosition(posx, posy); // Set the bomb position to the invader's position
        B->isactive = true; // Set the bomb as active
    }

   

    
  
    }  

};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Dragon: public Enemy{
public:
Bomb * B1;
Bomb * B2;
Bomb * B3;
bool movement = 0;
float posx1 = 0.0f;
float posy1 = 0.0f;
float posx2 = 0.0f;
float posy2 = 0.0f;
float posx3 = 0.0f;
float posy3 = 0.0f;

Dragon() : Enemy("img/dragon.png") {
 B1=new Bomb("img/laserBlue11.png");
 B2=new Bomb("img/laserBlue11.png");
 B3=new Bomb("img/laserBlue11.png");
 B1->sprite1.setScale(1,1);
 B2->sprite1.setScale(1,1);
 B3->sprite1.setScale(1,1);
 B1->sprite1.setPosition(-1,-1);
 B2->sprite1.setPosition(-1,-1);
 B3->sprite1.setPosition(-1,-1);
x = 390; y = 10;
sprite.setPosition(x,y);
}
Dragon(string png_path):Enemy(png_path){
B1=new Bomb("img/laserBlue11.png");
B2=new Bomb("img/laserBlue11.png");
B3=new Bomb("img/laserBlue11.png");
 B1->sprite1.setScale(1,1);
 B2->sprite1.setScale(1,1);
 B3->sprite1.setScale(1,1);
 B1->sprite1.setPosition(-1,-1);
 B2->sprite1.setPosition(-1,-1);
 B3->sprite1.setPosition(-1,-1);
x = 390 ; y = 10;
sprite.setPosition(x,y);
}
FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }

    
 void shootbomb(){  // New function to handle bullet shooting
 
 B1->speed2 = 0.75;
 B2->speed2 = 0.75;
 B3->speed2 = 0.75;
 if (!B1->isactive) {
     posx1 = this->sprite.getPosition().x - 300;
     posy1 = this->sprite.getPosition().y + 100;
        B1->sprite1.setPosition(posx1+=20 , posy1 ); // Set the bomb position to the invader's position
        B1->isactive = true; // Set the bomb as active
    }

  if (!B2->isactive) {
     posx2 = this->sprite.getPosition().x;
     posy2 = this->sprite.getPosition().y + 100;
        B2->sprite1.setPosition(posx2, posy2); // Set the bomb position to the invader's position
        B2->isactive = true; // Set the bomb as active
    } 
if (!B3->isactive) {
     posx3 = this->sprite.getPosition().x + 300;
     posy3 = this->sprite.getPosition().y + 100;
        B3->sprite1.setPosition(posx3 -=20, posy3); // Set the bomb position to the invader's position
        B3->isactive = true; // Set the bomb as active
    }
    
     
 
 if (B1->isactive) {
        posx1 = B1->sprite1.getPosition().x ; // Update invader's position from the bomb's position
        posy1 = B1->sprite1.getPosition().y ;
        posx1 += 20;
        
    }
 if (B2->isactive) {
        posx2 = B2->sprite1.getPosition().x; // Update invader's position from the bomb's position
        posy2 = B2->sprite1.getPosition().y;
    }
 if (B3->isactive) {
        posx3 = B3->sprite1.getPosition().x; // Update invader's position from the bomb's position
        posy3 = B3->sprite1.getPosition().y;
        posx3 -= 20;
      
    }
    
    
     B1->movebomb();
     B2->movebomb();
     B3->movebomb();
 
    
  
    }  

};

