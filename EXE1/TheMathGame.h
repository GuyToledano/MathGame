#ifndef _THE_MATH_GAME_H_
#define _THE_MATH_GAME_H_

#include "ISpecificGame.h"


class TheMathGame : public ISpecificGame
{
	unsigned int currentLevel;
	
public:
	virtual bool isLevelDone()const;
	virtual bool hasNextLevel()const;
	virtual void startLevel();
	virtual void doIteration(const list<char>& keyHits);
	virtual void doSubIteration();
	virtual void showInstructions()const;
};

#endif