#include "GameManager.h"
#include "TheMathGame.h"
#include "io_utils.h"
void TheMathGame::showInstructions()const
{
	clear_screen();
	gotoxy(40, 10);
	cout << "each player gets a math problem, ";
	gotoxy(40, 11);
	cout << "use the following keys to move and collect the correct answer." << endl;
	gotoxy(40, 12);
	cout << "Player| #1:      |         #2:" << endl;
	gotoxy(40, 13);
	cout << "Up    |  W       |          I" << endl;
	gotoxy(40, 14);
	cout << "down  |  X       |          M" << endl;
	gotoxy(40, 15);
	cout << "Left  |  A       |          J" << endl;
	gotoxy(40, 16);
	cout << "right |  D       |          L" << endl << endl;

	cout << "press any key to go back to main menu";
	_getch();
	clear_screen();
	
}
// virtual fucnction with =0 is called an "abstract method"
// abstract method must be implemented by non-abstract inherited class
bool TheMathGame::isLevelDone()const
{
	return true;
}
bool TheMathGame::hasNextLevel(const unsigned int currentLevel)const
{


	if (currentLevel <= LAST_LEVEL)
		return true;

	return false;
}
void TheMathGame::startLevel()
{
	gotoxy();



}

void TheMathGame::printLayout()
{

}

// get a list with keyHits and returns a list with the keys that were used
void TheMathGame::doIteration(const list<char>& keyHits)
{

}
void TheMathGame::doSubIteration()
{

}