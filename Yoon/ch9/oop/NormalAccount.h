#ifndef NORMALACCOUNT_H
#define NORMALACCOUNT_H

#include"BankingCommonDecl.h"
#include"Account.h"

class NormalAccount : public Account
{
private:
	int Ratio;

public:
	NormalAccount(int id, const char* name, int money, int ratio)
		:Account(id, name, money)
		, Ratio(ratio)
	{
	}
	virtual void PlusMoney(int money)
	{
		Account::PlusMoney(money);
		Account::PlusMoney(money * (Ratio / 100.f));
	}
};

#endif // !NORMALACCOUNT_H