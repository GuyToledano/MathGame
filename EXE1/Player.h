#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Equation.h"
#include <iostream>
#include "io_utils.h"
//#include "TheMathGame.h"
using namespace std;

/*#define player_1_UP 'w'
#define player_1_DOWN 'x'
#define player_1_LEFT 'a'
#define player_1_RIGHT 'd'
#define player_2_UP 'i'
#define player_2_DOWN 'm'
#define player_2_LEFT 'j'
#define player_2_RIGHT 'l'*/

#define X_MAX 79
#define X_MIN 0
#define Y_MAX 23
#define Y_MIN 3
#define MOVE_LEFT -1
#define MOVE_RIGHT 1
#define MOVE_UP -1
#define MOVE_DOWN 1
#define STAY 0

class Player
{
	char body;
	int score;
	Equation* eq;
	int x;
	int y;
	int lives;
	int dirx, diry;

	// TODO: create 'Point' class, and point data member instead of 2 ints
public:
	Player(char body='*',  int x=0, int y=0, int dirx = 0, int diry = 0,int score = 0, int lives = 3) 
		: body(body), x(x), y(y), dirx(dirx), diry(diry), score(score), lives(lives) {}

	void setEquation(Equation *newEq) { eq = newEq; }
	Equation* getEquation() { return eq; }

	void setLives(int newLives = 3) { lives = newLives; }	
	int getLives() { return lives; }

	void setXY(int newX, int newY)  { x = newX; y = newY; }
	int getX() { return x; }
	int getY() { return y; }

	void showPlayer(int x, int y);
	void erasePlayer(int x, int y);
	void changeDirection(char direction);
	void move(char direction);

	void printlives(int x, int y);
	int getscore() { return score; }

};


#endif