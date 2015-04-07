#ifndef _THE_MATH_GAME_H_
#define _THE_MATH_GAME_H_

#include <iostream>
#include "ISpecificGame.h"
#include "Player.h"

#define LAST_LEVEL 20
#define FIRST_LEVEL 0
#define PLAYER_1 1
#define PLAYER_2 2
#define PLAYER_1_UP 'w'
#define PLAYER_1_DOWN 'x'
#define PLAYER_1_LEFT 'a'
#define PLAYER_1_RIGHT 'd'
#define PLAYER_2_UP 'i'
#define PLAYER_2_DOWN 'm'
#define PLAYER_2_LEFT 'j'
#define PLAYER_2_RIGHT 'l'
#define X_MAX 79
#define X_MIN 0
#define Y_MAX 23
#define Y_MIN 3

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
	int assignToPlayer(char direction);
	bool isValid(char direction);
	void didPlayersCollide();
};

#endif