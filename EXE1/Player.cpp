#include "Player.h"

void Player::printlives(int x, int y)
{
	gotoxy(x, y);
	for (int i = 0; i < lives; i++)
	{
		cout << "X ";					// TODO: find heart husky
	}
}

void Player::showPlayer(int x, int y)
{
	gotoxy(x, y);
	cout << this->body;
}