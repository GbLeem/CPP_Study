#ifndef HIGHCREDITACCOUNT_H
#define HIGHCREDITACCOUNT_H

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int Rate;
public:
	HighCreditAccount(int id, const char* name, int money, int ratio, int rate)
		:NormalAccount(id, name, money, ratio)
		, Rate(rate)
	{
	}
	virtual void PlusMoney(int money)
	{
		NormalAccount::PlusMoney(money);
		Account::PlusMoney(money * (Rate / 100.f));
	}
};

#endif // !HIGHCREDITACCOUNT_H