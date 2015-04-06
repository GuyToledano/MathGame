#ifndef _THE_MATH_GAME_H_
#define _THE_MATH_GAME_H_

#include <iostream>
#include "ISpecificGame.h"
#include "Player.h"
#define LAST_LEVEL 20
#define FIRST_LEVEL 0

using namespace std;

class TheMathGame : public ISpecificGame
{
private:
	Player player1;
	Player player2;

	
public:
	virtual bool isLevelDone()const;
	virtual bool hasNextLevel(const unsigned int currentLevel)const;
	virtual void startLevel(const unsigned int currentLevel);
	void printframe(const unsigned int currentLevel);
	virtual void doIteration(const list<char>& keyHits);
	virtual void doSubIteration();
	virtual void showInstructions()const;
	void setEquations(const unsigned int currentLevel);
};

#endif