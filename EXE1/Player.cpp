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
	

	if (direction == player_1_UP || direction == player_2_UP)
	{
		dirx = 0;
		diry = -1;
	}
	else if (direction == player_1_DOWN || direction == player_2_DOWN)
	{
		dirx = 0;
		diry = 1;
	}
	else if (direction == player_1_LEFT || direction == player_2_LEFT)
	{
		dirx = -1;
		diry = 0;
	}
	else
	{
		dirx = 1;
		diry = 0;
	}
}
void Player::move(char direction)
{
	changeDirection(direction);

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