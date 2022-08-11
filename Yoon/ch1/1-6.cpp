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
		cout << "���� ID" << ' ' << people[i].ID << endl;
		cout << "�̸�" << ' ' << people[i].name << endl;
		cout << "�Ѿ�" << ' ' << people[i].money << endl;
		cout << endl;
		cout << endl;
	}
}

void MakeAccount()
{
	int id, money;
	char name[20] = {};
	cout << "[���� ����]" << endl;
	cout << "����ID : ";
	cin >> id;
	people[peopleNum].ID = id;
	
	cout << "�̸� : ";
	cin >> name;
	strcpy_s(people[peopleNum].name, name);

	cout << "�Աݾ� : ";
	cin >> money;
	people[peopleNum].money = money;
	
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
		if (id == people[i].ID)
		{
			cout << "�Աݾ� :";
			cin >> money;
			people[i].money += money;
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
		if (id == people[i].ID)
		{
			cout << "��ݾ� :";
			cin >> money;
			people[i].money -= money;
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

