#include "AccountHandler.h"
#include "NormalAccount.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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