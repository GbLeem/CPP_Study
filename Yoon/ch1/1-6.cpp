#include <iostream>

using namespace std;

struct People
{
	int ID;
	char name[100];
	int money;
};

int peopleNum = 0;
People people[100] = { 0, };

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
		cout << "계좌 ID" << ' ' << people[i].ID << endl;
		cout << "이름" << ' ' << people[i].name << endl;
		cout << "총액" << ' ' << people[i].money << endl;
		cout << endl;
		cout << endl;
	}
}

void MakeAccount()
{
	int id, money;
	char name[20] = {};
	cout << "[계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	people[peopleNum].ID = id;
	
	cout << "이름 : ";
	cin >> name;
	strcpy_s(people[peopleNum].name, name);

	cout << "입금액 : ";
	cin >> money;
	people[peopleNum].money = money;
	
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
		if (id == people[i].ID)
		{
			cout << "입금액 :";
			cin >> money;
			people[i].money += money;
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
		if (id == people[i].ID)
		{
			cout << "출금액 :";
			cin >> money;
			people[i].money -= money;
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

