#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
	int ID;
	char* Name;
	int Money;

public:
	Account(int id, const char* name, int money);
	Account(const Account& copy);
	~Account();
	int GetID() const { return ID; }
	virtual void PlusMoney(int money);
	void MinusMoney(int money);
	void ShowInfo()const;
};

#endif // !ACCOUNT_H