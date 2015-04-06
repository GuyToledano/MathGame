#ifndef _THE_MATH_GAME_H_
#define _THE_MATH_GAME_H_

#include "ISpecificGame.h"
#define LAST_LEVEL 20
#define FIRST_LEVEL 0

class TheMathGame : public ISpecificGame
{
	unsigned int currentLevel;
	
public:
	virtual bool isLevelDone()const;
	virtual bool hasNextLevel(const unsigned int currentLevel)const;
	virtual void startLevel();
	void printLayout();
	virtual void doIteration(const list<char>& keyHits);
	virtual void doSubIteration();
	virtual void showInstructions()const;
};

#endif