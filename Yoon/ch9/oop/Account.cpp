#include "Account.h"
#include"BankingCommonDecl.h"


Account::Account(int id, const char* name, int money)
	:ID(id)
	, Money(money)
{
	Name = new char(strlen(name) + 1);
	strcpy_s(Name, strlen(name) + 1, name);
}

Account::Account(const Account& copy)
	:ID(copy.ID)
	, Money(copy.Money)
{
	Name = new char(strlen(copy.Name) + 1);
	strcpy_s(Name, strlen(copy.Name) + 1, copy.Name);
}

Account::~Account()
{
	delete[]Name;
}

void Account::PlusMoney(int money)
{
	Money += money;
}

void Account::MinusMoney(int money)
{
	Money -= money;
}

void Account::ShowInfo()const
{
	cout << "°èÁÂ ID: " << ID << endl;
	cout << "ÀÌ ¸§: " << Name << endl;
	cout << "ÀÜ ¾×: " << Money << endl;
}