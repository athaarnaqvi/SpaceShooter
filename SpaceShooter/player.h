#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include<string.h>
#include<cmath>
#include <iostream>
using namespace sf;
using namespace std;
class Bullet{
public:
Texture tex2;
Sprite sprite1;
float speed2;
int x1,y1;
bool isactive=true;


int windowHeight = 780;
int windowWidth = 780;
Bullet(string png_path)
{


tex2.loadFromFile(png_path);
sprite1.setTexture(tex2);
x1=365;y1=680;
sprite1.setPosition(sf::Vector2f(x1,y1));
sprite1.setScale(0.5,0.5);
}
FloatRect getGlobalBounds() const {
        return sprite1.getGlobalBounds();
    }
void movebullet(std::string s1){
float delta_x1=0,delta_y1=0;

if(s1=="s")
	{delta_y1 = -1;
	speed2 = 1;
	
 
	}
else if(s1=="l")
	{delta_x1 = -1;
	speed2 = 0.5;
	}
	
else if(s1=="r"){
	delta_x1 = 1;
	speed2 = 0.5;}
else if(s1=="u"){
	delta_y1=-1;
	speed2 = 0.5;}
else if(s1=="d"){
	delta_y1=1;
	speed2 = 0.5;}



delta_y1*=speed2;
delta_x1*=speed2;



sprite1.move(sf::Vector2f(delta_x1, delta_y1));

}



};
class Player{

public:
Bullet * b;
Texture tex;
Sprite sprite;
bool iscollided = false;
float speed=0.5;
int x,y;
Player(std::string png_path)
{

  b=new Bullet("img/laserRed08.png");

tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.75,0.75);

}
FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }

void move(std::string s){
float delta_x=0,delta_y=0;

Vector2f newPos = sprite.getPosition() + Vector2f(delta_x, delta_y);

    // Wrap around the window
    if (newPos.x < 0)
        newPos.x = 780;
    else if (newPos.x > 780)
        newPos.x = 0;
    if (newPos.y < 0)
        newPos.y = 780;
    else if (newPos.y > 780)
        newPos.y = 0;

    sprite.setPosition(newPos);

if(s=="l")
	{  delta_x = -1;
	 b->movebullet("l");
	}
	
else if(s=="r"){
	delta_x = 1;
	 b->movebullet("r");}
if(s=="u"){
	delta_y=-1;
	 b->movebullet("u");}
else if(s=="d"){
	delta_y=1;
	 b->movebullet("d");}

delta_x*=speed;
delta_y*=speed;

sprite.move(sf::Vector2f(delta_x, delta_y));
 
}
 void shootbullet(){  // New function to handle bullet shooting
 
 b->movebullet("s");
                         
 if (b->sprite1.getPosition().y < 0 ||b->sprite1.getPosition().x < 0) {
                  
 b->sprite1.setPosition(this->sprite.getPosition().x+40, this->sprite.getPosition().y-1);
                   
                }
  
    }
      

};
#endif
