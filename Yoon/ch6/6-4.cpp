//const 키워드 추가

#include <iostream>
using namespace std;

class People
{
private:
	int ID;
	char* Name;
	int Money;

public:
	People(int id, const char* name, int money)
		:ID(id)
		, Money(money)
	{
		Name = new char(strlen(name) + 1);
		strcpy_s(Name, strlen(name) + 1, name);
	}

	People(const People& copy)
		:ID(copy.ID)
		, Money(copy.Money)
	{
		Name = new char(strlen(copy.Name) + 1);
		strcpy_s(Name, strlen(copy.Name) + 1, copy.Name);
	}

	~People()
	{
		delete[]Name;
	}

	int GetID() const { return ID; }
	const char* Getname() const { return Name; }
	int GetMoney() const { return Money; }

	void PlusMoney(int money)
	{
		Money += money;
	}

	void MinusMoney(int money)
	{
		Money -= money;
	}

};

int peopleNum = 0;
People* people[100];

void PrintMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌계설" << endl;
	cout << "2. 입  금" << endl;
	cout << "3. 출  금 " << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

void PrintAll()
{
	cout << "[전체출력]" << endl;

	for (int i = 0; i < peopleNum; ++i)
	{
		cout << "계좌 ID" << ' ' << people[i]->GetID() << endl;
		cout << "이름" << ' ' << people[i]->Getname() << endl;
		cout << "총액" << ' ' << people[i]->GetMoney() << endl;
		cout << endl;
		cout << endl;
	}
}

void MakeAccount()
{
	int id, money;
	char name[20];

	cout << "[계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;

	people[peopleNum] = new People(id, name, money);
	peopleNum++;

	cout << endl;
}

void MoneyIn()
{
	int id, money;
	cout << "[입  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	//계좌 ID로
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == people[i]->GetID())
		{
			cout << "입금액 :";
			cin >> money;
			people[i]->PlusMoney(money);
			cout << "입금완료" << endl;
		}

		else
		{
			cout << "없는 ID 입니다" << endl;
			return;
		}
	}
	cout << endl;

}

void MoneyOut()
{
	int id, money;
	cout << "[출  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	//계좌 ID로
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == people[i]->GetID())
		{
			cout << "출금액 :";
			cin >> money;
			people[i]->MinusMoney(money);
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

	while (1)
	{
		PrintMenu();
		cin >> menuIndex;

		switch (menuIndex)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			MoneyIn();
			break;
		case 3:
			MoneyOut();
			break;
		case 4:
			PrintAll();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}

