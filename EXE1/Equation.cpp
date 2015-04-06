#include "Equation.h"
#include <iostream>


Equation::Equation(const unsigned int currentlevel )
{
	num1 = rand() % currentlevel + 10;
	num2 = rand() % currentlevel + 10;
	oper = rand() % 4;
	switch (oper)
	{
	case PLUS:
		result = num1 + num2;
		hiddenNum = rand() % 2;
		break;
	case MULT:
		result = num1*num2;
		hiddenNum = rand() % 2;
		break;
	case MINUS:
		result = num1 + num2;
		hiddenNum = rand() % 2;
		break;
	case DIV:
		result = num1*num2;
		hiddenNum = rand() % 2;
		break;
	}
}