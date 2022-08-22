//NormalAccount와 HighCreditAccount 추가

#include <iostream>
using namespace std;

enum
{
	LEVEL_A = 7,
	LEVEL_B = 4,
	LEVEL_C = 2
};

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
	cout << "계좌 ID: " << ID << endl;
	cout << "이 름: " << Name << endl;
	cout << "잔 액: " << Money << endl;
}


class NormalAccount : public Account
{
private:
	int Ratio;

public:
	NormalAccount(int id, const char* name, int money, int ratio)
		:Account(id, name, money)
		,Ratio(ratio)
	{
	}
	virtual void PlusMoney(int money)
	{
		Account::PlusMoney(money);
		Account::PlusMoney(money * (Ratio / 100.f));
	}
};


class HighCreditAccount : public NormalAccount
{
private:
	int Rate;
public:
	HighCreditAccount(int id, const char* name, int money, int ratio, int rate)
		:NormalAccount(id, name, money, ratio)
		,Rate(rate)
	{
	}
	virtual void PlusMoney(int money)
	{
		NormalAccount::PlusMoney(money);
		Account::PlusMoney(money * (Rate / 100.f));
	}
};


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

void AccountHandler::PrintMenu()const
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌계설" << endl;
	cout << "2. 입  금" << endl;
	cout << "3. 출  금 " << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

void AccountHandler::PrintAll()const
{
	cout << "[전체출력]" << endl;

	for (int i = 0; i < peopleNum; ++i)
	{
		account[i]->ShowInfo();
		cout << endl;
		cout << endl;
	}
}

void AccountHandler::MakeAccount()
{
	int choice;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌" << ' ' << "2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> choice;

	if (choice == 1)
		MakeNormalAccount();
	else if (choice == 2)
		MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
	int id, money, ratio;
	char name[20];

	cout << "[보통 예금 계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;
	cout << "이자율: ";
	cin >> ratio;

	account[peopleNum++] = new NormalAccount(id, name, money, ratio);

	cout << endl;
}
void AccountHandler::MakeHighCreditAccount()
{
	int id, money, ratio, rate;
	char name[20];

	cout << "[신용 신뢰 계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;
	cout << "이자율: ";
	cin >> ratio;
	cout << "신용등급 : ";
	cin >> rate;

	switch (rate)
	{
	case 1:
		account[peopleNum++] = new HighCreditAccount(id, name, money, ratio, LEVEL_A);
		break;
	case 2:
		account[peopleNum++] = new HighCreditAccount(id, name, money, ratio, LEVEL_B);
		break;
	case 3:
		account[peopleNum++] = new HighCreditAccount(id, name, money, ratio, LEVEL_C);
		break;
	}
	cout << endl;
}
void AccountHandler::MoneyIn()
{
	int id, money;
	cout << "[입  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	//계좌 ID로
	for (int i = 0; i < peopleNum; ++i)
	{
		if (account[i]->GetID() == id)
		{
			cout << "입금액 :";
			cin >> money;
			account[i]->PlusMoney(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "없는 ID 입니다" << endl;
	cout << endl;
}

void AccountHandler::MoneyOut()
{
	int id, money;
	cout << "[출  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	//계좌 ID로
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == account[i]->GetID())
		{
			cout << "출금액 :";
			cin >> money;
			account[i]->MinusMoney(money);
			cout << "출금완료" << endl;
		}

		else
		{
			cout << "없는 ID 입니다" << endl;
			return;
		}
	}
	cout << endl;
}

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
		case 1:
			ac.MakeAccount();
			break;
		case 2:
			ac.MoneyIn();
			break;
		case 3:
			ac.MoneyOut();
			break;
		case 4:
			ac.PrintAll();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}

