#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Equation.h"
#include <iostream>
#include "io_utils.h"
using namespace std;

class Player
{
	char body;
	int score;
	Equation* eq;
	int x;
	int y;
	int lives;
	// TODO: create 'Point' class, and point data member instead of 2 ints
public:
	Player(char body='*',  int x=0, int y=0, int score = 0, int lives = 3) 
		: body(body), x(x), y(y), score(score), lives(lives) {}

	void setEquation(Equation *newEq) { eq = newEq; }
	Equation* getEquation() { return eq; }

	void setLives(int newLives = 3) { lives = newLives; }	
	int getLives() { return lives; }

	void setXY(int newX, int newY)  { x = newX; y = newY; }
	int getX() { return x; }
	int getY() { return y; }

	void showPlayer(int x, int y);
	void printlives(int x, int y);
	int getscore() { return score; }

};


#endif