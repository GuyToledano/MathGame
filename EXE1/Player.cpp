#include "Player.h"

void Player::printlives(int x, int y)
{
	gotoxy(x, y);
	for (int i = 0; i < lives; i++)
	{
		cout << "X ";					// TODO: find heart ascii
	}
}
void Player::erasePlayer(int x, int y)
{
	gotoxy(x, y);
	cout << " ";
}
void Player::showPlayer(int x, int y)
{
	gotoxy(x, y);
	cout << this->body;
}
void Player::changeDirection(char direction)
{
	

	if (direction == PLAYER_1_UP || direction == PLAYER_2_UP)
	{
		dirx = STAY;
		diry = MOVE_UP;
	}
	else if (direction == PLAYER_1_DOWN || direction == PLAYER_2_DOWN)
	{
		dirx = STAY;
		diry = MOVE_DOWN;
	}
	else if (direction == PLAYER_1_LEFT || direction == PLAYER_2_LEFT)
	{
		dirx = MOVE_LEFT;
		diry = STAY;
	}
	else
	{
		dirx = MOVE_RIGHT;
		diry = STAY;
	}
}
void Player::move()
{
	erasePlayer(x, y);
	x += dirx;
	y += diry;

	if (x > X_MAX)
		x = X_MIN;
	else if (x < X_MIN)
		x = X_MAX;
	
	if (y > Y_MAX)
		y = Y_MIN;
	else if (y < Y_MIN)
		y = Y_MAX;

	showPlayer(x, y);
}