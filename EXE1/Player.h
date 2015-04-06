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

public:
	Player(char body='*', Equation *eq = NULL, int x=0, int y=0, int score = 0, int lives = 3) 
		: body(body), x(x), y(y), score(score), lives(lives), eq(eq) {}

	void setEquation(Equation *newEq) { eq = newEq; }
	void setLives(int newLives = 3) { lives = newLives; }

	Equation* getEquation() { return eq; }
	int getLives() { return lives; }

	void printlives(int x, int y);
	int getscore() { return score; }

};


#endif