#ifndef _EQUATION_H_
#define _EQUATION_H_

#include <iostream>

class Equation
{
	int num1;
	int num2;
	int result;
	int oper;
	int hiddenNum;
	enum
	{
		PLUS,
		MULT,
		MINUS,
		DIV
	};
public:
	Equation(const unsigned int currentLevel);
	
};

#endif