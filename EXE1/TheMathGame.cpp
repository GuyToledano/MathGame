#include "GameManager.h"
#include "TheMathGame.h"
#include "io_utils.h"
#include "Equation.h"

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

	this->player1 = Player('@', 10, 9, 0, 3);
	this->player2 = Player('#', 70, 9, 0, 3);
	
	this->player1.showPlayer(10, 9);
	this->player2.showPlayer(70, 9);
	setEquations(currentLevel);
	printframe(currentLevel);
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

			if (playerMove == 1 && gotDirectionForPlayer1 == false)
			{
				gotDirectionForPlayer1 = true;
				this->player1.move(direction);
			}
			if (playerMove == 2 && gotDirectionForPlayer2 == false)
			{
				gotDirectionForPlayer2 = true;
				this->player2.move(direction);
			}			
		}
	}
}
//TODO DEFINE PLAYER X X
int TheMathGame::assignToPlayer(char direction)
{
	switch (direction)
	{
	case 'w':
		return 1;
	case 'd':
		return 1;
	case 'a':
		return 1;
	case 'x':
		return 1;
	case 'i':
		return 2;
	case 'l':
		return 2;
	case 'j':
		return 2;
	case 'm':
		return 2;
	}
	return 0;
}
bool TheMathGame::isValid(char direction)
{
	return (assignToPlayer(direction) != 0);
}
void TheMathGame::doSubIteration()
{

}