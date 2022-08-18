//const Ű���� �߰�

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
	cout << "1. ���°輳" << endl;
	cout << "2. ��  ��" << endl;
	cout << "3. ��  �� " << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
}

void PrintAll()
{
	cout << "[��ü���]" << endl;

	for (int i = 0; i < peopleNum; ++i)
	{
		cout << "���� ID" << ' ' << people[i]->GetID() << endl;
		cout << "�̸�" << ' ' << people[i]->Getname() << endl;
		cout << "�Ѿ�" << ' ' << people[i]->GetMoney() << endl;
		cout << endl;
		cout << endl;
	}
}

void MakeAccount()
{
	int id, money;
	char name[20];

	cout << "[���� ����]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�̸� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;

	people[peopleNum] = new People(id, name, money);
	peopleNum++;

	cout << endl;
}

void MoneyIn()
{
	int id, money;
	cout << "[��  ��]" << endl;
	cout << "����ID : ";
	cin >> id;

	//���� ID��
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == people[i]->GetID())
		{
			cout << "�Աݾ� :";
			cin >> money;
			people[i]->PlusMoney(money);
			cout << "�ԱݿϷ�" << endl;
		}

		else
		{
			cout << "���� ID �Դϴ�" << endl;
			return;
		}
	}
	cout << endl;

}

void MoneyOut()
{
	int id, money;
	cout << "[��  ��]" << endl;
	cout << "����ID : ";
	cin >> id;

	//���� ID��
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == people[i]->GetID())
		{
			cout << "��ݾ� :";
			cin >> money;
			people[i]->MinusMoney(money);
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

