#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include"Account.h"

class AccountHandler
{
private:
	int peopleNum;
	Account* account[1000];
public:
	AccountHandler()
		:peopleNum(0)
		, account()
	{

	}
	void PrintMenu() const;
	void PrintAll()const;
	void MakeAccount();
	void MoneyIn();
	void MoneyOut();

protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount();

};

#endif // !ACCOUNTHANDLER_H