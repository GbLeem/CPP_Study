//NormalAccount�� HighCreditAccount �߰�

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
	cout << "���� ID: " << ID << endl;
	cout << "�� ��: " << Name << endl;
	cout << "�� ��: " << Money << endl;
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
	cout << "1. ���°輳" << endl;
	cout << "2. ��  ��" << endl;
	cout << "3. ��  �� " << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
}

void AccountHandler::PrintAll()const
{
	cout << "[��ü���]" << endl;

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
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���" << ' ' << "2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
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

	cout << "[���� ���� ���� ����]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�̸� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;
	cout << "������: ";
	cin >> ratio;

	account[peopleNum++] = new NormalAccount(id, name, money, ratio);

	cout << endl;
}
void AccountHandler::MakeHighCreditAccount()
{
	int id, money, ratio, rate;
	char name[20];

	cout << "[�ſ� �ŷ� ���� ����]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�̸� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;
	cout << "������: ";
	cin >> ratio;
	cout << "�ſ��� : ";
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
	cout << "[��  ��]" << endl;
	cout << "����ID : ";
	cin >> id;

	//���� ID��
	for (int i = 0; i < peopleNum; ++i)
	{
		if (account[i]->GetID() == id)
		{
			cout << "�Աݾ� :";
			cin >> money;
			account[i]->PlusMoney(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "���� ID �Դϴ�" << endl;
	cout << endl;
}

void AccountHandler::MoneyOut()
{
	int id, money;
	cout << "[��  ��]" << endl;
	cout << "����ID : ";
	cin >> id;

	//���� ID��
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == account[i]->GetID())
		{
			cout << "��ݾ� :";
			cin >> money;
			account[i]->MinusMoney(money);
			cout << "��ݿϷ�" << endl;
		}

		else
		{
			cout << "���� ID �Դϴ�" << endl;
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

