#include "GameManager.h"
#include "TheMathGame.h"
#include "io_utils.h"
#include "Equation.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

//TODO: create function "levelDone. it will free the equasions

//TODO: style the instructions a bit
void TheMathGame::showInstructions()const
{
	clear_screen();
	//gotoxy(40, 10);
	cout << "each player gets a math problem, ";
	//gotoxy(20, 11);
	cout << "use the following keys to move and collect the correct answer." << endl;
	gotoxy(20, 5);
	cout << "Player| #1:      |         #2:" << endl;
	gotoxy(20, 5);
	cout << "Up    |  W       |          I" << endl;
	gotoxy(20, 5);
	cout << "down  |  X       |          M" << endl;
	gotoxy(20, 5);
	cout << "Left  |  A       |          J" << endl;
	gotoxy(20, 5);
	cout << "right |  D       |          L" << endl << endl;

	cout << "press any key to go back to main menu";
	_getch();
	clear_screen();
	
}
// virtual fucnction with =0 is called an "abstract method"
// abstract method must be implemented by non-abstract inherited class
bool TheMathGame::isLevelDone()const
{
	return false;
}
bool TheMathGame::hasNextLevel(const unsigned int currentLevel)const
{
	if (currentLevel < LAST_LEVEL)
		return true;

	return false;
}
//TODO: create c'tor of TheMathGame to initiate both players
void TheMathGame::startLevel(const unsigned int currentLevel)
{
	clear_screen();

	this->player1 = Player('@', 10, 9, MOVE_RIGHT, STAY, 0, 3);
	this->player2 = Player('#', 70, 9, MOVE_LEFT, STAY, 0, 3);
	
	setEquations(currentLevel);
	printframe(currentLevel);

	this->player1.showPlayer(10, 9);
	this->player2.showPlayer(70, 9);

}
void TheMathGame::setEquations(const unsigned int currentLevel)
{
	this->player1.setEquation(new Equation(currentLevel));
	this->player2.setEquation(new Equation(currentLevel));
}
void TheMathGame::printframe(const unsigned int currentLevel)
{
	Equation* eq1 = this->player1.getEquation();
	Equation* eq2 = this->player2.getEquation();
	eq1->printEquation(0,0);
	eq2->printEquation(60, 0);
	player1.printlives(0, 1);
	player2.printlives(60, 1);
	gotoxy(8,1);
	cout << "score: " << player1.getscore();
	gotoxy(68, 1);
	cout << "score: " << player2.getscore();
	gotoxy(36, 0);
	cout << "Level: " << currentLevel;
	gotoxy(0, 2);
	for (int i = 0; i < 80; i++)
		cout << "_";

}
// get a list with keyHits and returns a list with the keys that were used
void TheMathGame::doIteration(const list<char>& keyHits)
{
	char direction;
	int playerMove;
	bool gotDirectionForPlayer1 = false;
	bool gotDirectionForPlayer2 = false;

	for (list<char>::const_iterator itr = keyHits.cbegin();
		(itr != keyHits.cend()) && (gotDirectionForPlayer1 == false || gotDirectionForPlayer2 == false);
		++itr)
	{
		direction = *itr;
		if (isValid(direction))
		{
			playerMove = assignToPlayer(direction);

			if (playerMove == PLAYER_1 && gotDirectionForPlayer1 == false)
			{
				gotDirectionForPlayer1 = true;
				this->player1.changeDirection(direction);
			}
			if (playerMove == PLAYER_2 && gotDirectionForPlayer2 == false)
			{
				gotDirectionForPlayer2 = true;
				this->player2.changeDirection(direction);
			}
		}
	}
	didPlayersCollide();
	this->player1.move();
	this->player2.move();
}
//TODO: change the letters to defines
int TheMathGame::assignToPlayer(char direction)
{
	switch (direction)   //switch to check whisch button was pressed
	{
	case PLAYER_1_UP:
		return PLAYER_1;

	case PLAYER_1_RIGHT:
		return PLAYER_1;

	case PLAYER_1_LEFT:
		return PLAYER_1;

	case PLAYER_1_DOWN:
		return PLAYER_1;

	case PLAYER_2_UP:
		return PLAYER_2;

	case PLAYER_2_RIGHT:
		return PLAYER_2;

	case PLAYER_2_LEFT:
		return PLAYER_2;

	case PLAYER_2_DOWN:
		return PLAYER_2;
	}
	return 0;        //returns 0 as default if the keyboard hit didnt belong to neither one of the players
}
bool TheMathGame::isValid(char direction)
{
	return (assignToPlayer(direction) != 0);
}
void TheMathGame::doSubIteration()
{

}

void TheMathGame::didPlayersCollide()
{
	if ((this->player1.getX() == this->player2.getX() - 1) && (this->player1.getDirx() == 1 && this->player2.getDirx() == -1))
	{
		this->player1.setDirx(0);
		this->player2.setDirx(0);
	}
	else if ((this->player1.getX() == this->player2.getX() + 1) && (this->player1.getDirx() == -1 && this->player2.getDirx() == 1))
	{
		this->player1.setDirx(0);
		this->player2.setDirx(0);
	}
	else if ((this->player1.getY() == this->player2.getY() - 1) && (this->player1.getDiry() == 1 && this->player2.getDiry() == -1))
	{
		this->player1.setDiry(0);
		this->player2.setDiry(0);
	}
	else if ((this->player1.getY() == this->player2.getY() + 1) && (this->player1.getDiry() == -1 && this->player2.getDiry() == 1))
	{
		this->player1.setDiry(0);
		this->player2.setDiry(0);
	}
	

}