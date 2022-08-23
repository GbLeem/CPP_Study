#ifndef BANKINGCOMMONDECL_H
#define BANKINGCOMMONDECL_H

#include <iostream>
using namespace std;

enum
{
	LEVEL_A = 7,
	LEVEL_B = 4,
	LEVEL_C = 2
};

enum
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};

#endif // !BANKINGCOMMONDECL_H