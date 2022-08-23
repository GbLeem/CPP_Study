#include"NormalAccount.h"
#include"AccountHandler.h"

int main()
{
	int menuIndex;
	AccountHandler ac;
	while (1)
	{
		ac.PrintMenu();
		cin >> menuIndex;

		switch (menuIndex)
		{
		case MAKE:
			ac.MakeAccount();
			break;
		case DEPOSIT:
			ac.MoneyIn();
			break;
		case WITHDRAW:
			ac.MoneyOut();
			break;
		case INQUIRE:
			ac.PrintAll();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}
}